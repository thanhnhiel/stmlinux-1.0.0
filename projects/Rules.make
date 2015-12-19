# 
# This file contains common make rules for all projects.
#

MAKE		:= make

KERNEL_CONFIG	:= kernel$(if $(MCU),.$(MCU))
KERNEL_LD	:= lds$(if $(MCU),.$(MCU))
RAMFS_CONFIG	:= initramfs
KERNEL_IMAGE	:= uImage
KERNEL_VIMAGE	:= vImage
KERNEL_EIMAGE	:= eImage
ENVM_LOG	:= .envm_log
ENVM_LOG1	:= .envm_log1
ENVM_LOG2	:= .envm_log2
OUTPUT := $(INSTALL_ROOT)/out

# Path to the kernel modules directory in context of which
# these loadable modules are built
KERNELDIR	:=  $(INSTALL_ROOT)/linux

CFLAGS		:= "-Os -mcpu=cortex-m3 -mthumb -I$(INSTALL_ROOT)/A2F/root/usr/include"
LDFLAGS		:= "-mcpu=cortex-m3 -mthumb -L$(INSTALL_ROOT)/A2F/root/usr/lib"

.PHONY	: all busybox linux kmenuconfig bmenuconfig clean kclean bclean aclean $(CUSTOM_APPS) clone

all		: _do_modules linux

# For those projects that have support for loadable kernel modules
# enabled in the kernel configuration, we need to build and install
# modules in the kernel tree, as a first step in building the project.
# This is needed to allow us building an external module (or several
# such modules) as an external module from a project subdirectory
# and then to include the resultant module object in the project
# initramfs filesystem.

MODULES_ON	:= $(shell grep CONFIG_MODULES=y $(SAMPLE).$(KERNEL_CONFIG))
INSTALL_MOD_PATH:= $(OUTPUT)

ifeq ($(MODULES_ON),)
_do_modules 	:
else
_do_modules	: _prepare_modules
endif

$(OUTPUT)/initramfs-list-min.stub :
	cp -f $(INSTALL_ROOT)/linux/initramfs-list-min.stub \
        $(OUTPUT)/initramfs-list-min.stub 

_prepare_modules: $(OUTPUT)/initramfs-list-min.stub $(OUTPUT)
	cp -f $(OUTPUT)/initramfs-list-min.stub \
		$(OUTPUT)/initramfs-list-min
	rm -f $(OUTPUT)/usr/initramfs_data.cpio \
		$(OUTPUT)/usr/initramfs_data.cpio.gz
	cp -f $(SAMPLE).$(KERNEL_CONFIG) $(OUTPUT)/.config
	$(MAKE) -C $(INSTALL_ROOT)/linux O=$(OUTPUT) vmlinux -j4
	$(MAKE) -C $(INSTALL_ROOT)/linux O=$(OUTPUT) modules -j4

linux		: $(SAMPLE).$(KERNEL_IMAGE)

$(OUTPUT) :
	mkdir -p $(OUTPUT)
  
$(CUSTOM_APPS)	:
	 CFLAGS=${CFLAGS} LDFLAGS=${LDFLAGS} make -C $@ all

clean		: kclean bclean aclean
	rm -rf $(SAMPLE).$(KERNEL_IMAGE) $(SAMPLE).$(KERNEL_VIMAGE) \
		$(SAMPLE).$(KERNEL_EIMAGE) \
		$(ENVM_LOG) $(ENVM_LOG1) $(ENVM_LOG2) busybox

kclean		: $(OUTPUT)
	$(MAKE) -C $(INSTALL_ROOT)/linux O=$(OUTPUT) clean

bclean		:
	$(MAKE) -C $(INSTALL_ROOT)/A2F/busybox clean

aclean		:
	@[ "x$(CUSTOM_APPS)" = "x" ] || \
		for i in $(CUSTOM_APPS); do \
			$(MAKE) -C $$i clean; \
		done

kmenuconfig	: $(OUTPUT)
	cp -f $(SAMPLE).$(KERNEL_CONFIG) \
			$(OUTPUT)/.config
	$(MAKE) -C $(INSTALL_ROOT)/linux O=$(OUTPUT) menuconfig
	cp -f $(OUTPUT)/.config \
			./$(SAMPLE).$(KERNEL_CONFIG)

bmenuconfig	: $(OUTPUT)
	cp -f $(SAMPLE).busybox $(INSTALL_ROOT)/A2F/busybox/.config
	$(MAKE) -C $(INSTALL_ROOT)/A2F/busybox menuconfig
	cp -f $(INSTALL_ROOT)/A2F/busybox/.config $(SAMPLE).busybox

busybox		: $(SAMPLE).busybox
	cp -f $(SAMPLE).busybox $(INSTALL_ROOT)/A2F/busybox/.config
	$(MAKE) -C $(INSTALL_ROOT)/A2F/busybox -j4
#	cp -f $(INSTALL_ROOT)/A2F/busybox/busybox $@

%.$(KERNEL_IMAGE) : $(OUTPUT) %.$(KERNEL_CONFIG) %.$(RAMFS_CONFIG) $(CUSTOM_APPS) busybox
	cp -f $(SAMPLE).$(RAMFS_CONFIG) $(OUTPUT)/initramfs-list-min
	rm -f $(OUTPUT)/usr/initramfs_data.cpio \
		$(OUTPUT)/usr/initramfs_data.cpio.gz
	cp -f $(SAMPLE).$(KERNEL_CONFIG) $(OUTPUT)/.config
	cp -f $(INSTALL_ROOT)/linux/arch/arm/kernel/vmlinux.lds.S.good \
		$(INSTALL_ROOT)/linux/arch/arm/kernel/vmlinux.lds.S
	([ -e $(SAMPLE).$(KERNEL_LD) ] && \
		cp -f $(SAMPLE).$(KERNEL_LD) \
		$(INSTALL_ROOT)/linux/arch/arm/kernel/vmlinux.lds.S) || \
	true;
	$(MAKE) -C $(INSTALL_ROOT)/linux O=$(OUTPUT) $(KERNEL_IMAGE) SAMPLE=${SAMPLE} -j4
	cp -f $(OUTPUT)/arch/arm/boot/$(KERNEL_IMAGE) $@
	rm -f $(ENVM_LOG)
	(grep "CONFIG_KERNEL_IN_ENVM=y" $(SAMPLE).$(KERNEL_CONFIG) > \
		$(ENVM_LOG) || true)
	([ -s $(ENVM_LOG) ] && \
	($(MAKE) -C $(INSTALL_ROOT)/linux O=$(OUTPUT) $(KERNEL_VIMAGE) SAMPLE=${SAMPLE} -j4; \
	cp -f $(OUTPUT)/arch/arm/boot/$(KERNEL_VIMAGE) \
		$(SAMPLE).$(KERNEL_VIMAGE); \
	cp $@ $(SAMPLE).$(KERNEL_EIMAGE); \
	grep CONFIG_KERNEL_IN_ENVM_OFFSET ${SAMPLE}.kernel.$(MCU) | \
		cut -d "=" -f 2 > $(ENVM_LOG1); \
	grep CONFIG_IMAGE_IN_ENVM_OFFSET ${SAMPLE}.kernel.$(MCU) | \
		cut -d "=" -f 2 > $(ENVM_LOG2); \
	expr `cat $(ENVM_LOG1)` - `cat $(ENVM_LOG2)` > $(ENVM_LOG); \
	dd if=$(SAMPLE).$(KERNEL_VIMAGE) of=$@ obs=1K \
		seek=`cat $(ENVM_LOG)`)) || true;
	rm -f $(ENVM_LOG) $(ENVM_LOG1) $(ENVM_LOG2)
	mv $(SAMPLE).$(KERNEL_IMAGE) $(SAMPLE).$(KERNEL_IMAGE).bin

clone		:
	@[ ! -z ${new} ] || \
	(echo "Please specify the new project name (\"make clone new=...\")";\
		 exit 1);
	@[ ! -d $(INSTALL_ROOT)/projects/${new} ] || \
		(echo \
		"Project $(INSTALL_ROOT)/projects/${new} already exists!"; \
		 exit 1);
	@mkdir -p $(INSTALL_ROOT)/projects/${new}
	@cp -a .  $(INSTALL_ROOT)/projects/${new}
	@for i in ${KERNEL_CONFIG} ${KERNEL_LD} ${RAMFS_CONFIG} busybox; do \
		[ -e $(INSTALL_ROOT)/projects/${new}/${SAMPLE}.$$i ] && \
		mv $(INSTALL_ROOT)/projects/${new}/${SAMPLE}.$$i \
			$(INSTALL_ROOT)/projects/${new}/${new}.$$i; \
	done
	@sed 's/SAMPLE.*\:=.*/SAMPLE\t\t:= ${new}/' Makefile > \
		$(INSTALL_ROOT)/projects/${new}/Makefile
	@echo "New project created in $(INSTALL_ROOT)/projects/${new}"
