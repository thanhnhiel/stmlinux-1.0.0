cmd_/mnt/data1/workspace/stmlinux-1.0.0/projects/qtdemo2/app/sample.o := arm-uclinuxeabi-gcc -Wp,-MD,/mnt/data1/workspace/stmlinux-1.0.0/projects/qtdemo2/app/.sample.o.d  -nostdinc -isystem /mnt/data1/workspace/compiler/arm-2010q1/bin/../lib/gcc/arm-uclinuxeabi/4.4.1/include -I/mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include -Iinclude  -I/mnt/data1/workspace/stmlinux-1.0.0/linux/include -include include/generated/autoconf.h   -I/mnt/data1/workspace/stmlinux-1.0.0/projects/qtdemo2/app -D__KERNEL__ -mlittle-endian   -I/mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/mach-stm32/include -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -Os -marm -mabi=aapcs-linux -mno-thumb-interwork -mthumb -Wa,-mimplicit-it=always -Wa,-mno-warn-deprecated -mlong-calls -D__LINUX_ARM_ARCH__=7 -mcpu=cortex-m3 -Wa,-mcpu=cortex-m3 -msoft-float -Uarm -Wframe-larger-than=1024 -fno-stack-protector -fomit-frame-pointer -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fno-dwarf2-cfi-asm -fconserve-stack  -DMODULE -mlong-calls -fno-optimize-sibling-calls -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(sample)"  -D"KBUILD_MODNAME=KBUILD_STR(sample)"  -c -o /mnt/data1/workspace/stmlinux-1.0.0/projects/qtdemo2/app/sample.o /mnt/data1/workspace/stmlinux-1.0.0/projects/qtdemo2/app/sample.c

deps_/mnt/data1/workspace/stmlinux-1.0.0/projects/qtdemo2/app/sample.o := \
  /mnt/data1/workspace/stmlinux-1.0.0/projects/qtdemo2/app/sample.c \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/module.h \
    $(wildcard include/config/symbol/prefix.h) \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/unused/symbols.h) \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/kallsyms.h) \
    $(wildcard include/config/tracepoints.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/event/tracing.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
    $(wildcard include/config/module/unload.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/constructors.h) \
    $(wildcard include/config/sysfs.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/stddef.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/compiler.h \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/compiler-gcc4.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/prefetch.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/types.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/asm-generic/int-ll64.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/bitsperlong.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/asm-generic/bitsperlong.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/posix_types.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/posix_types.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/processor.h \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/cpu/v7m.h) \
    $(wildcard include/config/mpu.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/ptrace.h \
    $(wildcard include/config/cpu/endian/be8.h) \
    $(wildcard include/config/arm/thumb.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/hwcap.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/cache.h \
    $(wildcard include/config/arm/l1/cache/shift.h) \
    $(wildcard include/config/aeabi.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/system.h \
    $(wildcard include/config/cpu/xsc3.h) \
    $(wildcard include/config/cpu/fa526.h) \
    $(wildcard include/config/arch/has/barriers.h) \
    $(wildcard include/config/cpu/sa1100.h) \
    $(wildcard include/config/cpu/sa110.h) \
    $(wildcard include/config/arch/a2f.h) \
    $(wildcard include/config/cpu/32v6k.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/linkage.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/linkage.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/typecheck.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/irqflags.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/outercache.h \
    $(wildcard include/config/outer/cache/sync.h) \
    $(wildcard include/config/outer/cache.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/asm-generic/cmpxchg-local.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/stat.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/stat.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/time.h \
    $(wildcard include/config/arch/uses/gettimeoffset.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/cache.h \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/spinlock/sleep.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
    $(wildcard include/config/ring/buffer.h) \
    $(wildcard include/config/numa.h) \
  /mnt/data1/workspace/compiler/arm-2010q1/bin/../lib/gcc/arm-uclinuxeabi/4.4.1/include/stdarg.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/bitops.h \
    $(wildcard include/config/generic/find/first/bit.h) \
    $(wildcard include/config/generic/find/last/bit.h) \
    $(wildcard include/config/generic/find/next/bit.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/bitops.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/asm-generic/bitops/non-atomic.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/asm-generic/bitops/fls64.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/asm-generic/bitops/sched.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/asm-generic/bitops/hweight.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/asm-generic/bitops/lock.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/dynamic_debug.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/byteorder.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/byteorder/little_endian.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/swab.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/swab.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/byteorder/generic.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/seqlock.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/spinlock.h \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/generic/lockbreak.h) \
    $(wildcard include/config/preempt.h) \
    $(wildcard include/config/debug/lock/alloc.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/preempt.h \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/preempt/notifiers.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/thread_info.h \
    $(wildcard include/config/compat.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/thread_info.h \
    $(wildcard include/config/arm/thumbee.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/fpstate.h \
    $(wildcard include/config/vfpv3.h) \
    $(wildcard include/config/vfpm.h) \
    $(wildcard include/config/iwmmxt.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/domain.h \
    $(wildcard include/config/io/36.h) \
    $(wildcard include/config/cpu/use/domains.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/stringify.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/bottom_half.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/spinlock_types.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/spinlock_types_up.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/lockdep.h \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/lock/stat.h) \
    $(wildcard include/config/generic/hardirqs.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/rwlock_types.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/spinlock_up.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/rwlock.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/spinlock_api_up.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/atomic.h \
    $(wildcard include/config/generic/atomic64.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/asm-generic/atomic64.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/asm-generic/atomic-long.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/math64.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/div64.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/kmod.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/gfp.h \
    $(wildcard include/config/kmemcheck.h) \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/debug/vm.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/sparsemem.h) \
    $(wildcard include/config/arch/populates/node/map.h) \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/cgroup/mem/res/ctlr.h) \
    $(wildcard include/config/have/memory/present.h) \
    $(wildcard include/config/need/node/memmap/size.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/have/arch/early/pfn/to/nid.h) \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/nodes/span/other/nodes.h) \
    $(wildcard include/config/holes/in/zone.h) \
    $(wildcard include/config/arch/has/holes/memorymodel.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/wait.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/current.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/numa.h \
    $(wildcard include/config/nodes/shift.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/init.h \
    $(wildcard include/config/hotplug.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/nodemask.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/bitmap.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/string.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/pageblock-flags.h \
    $(wildcard include/config/hugetlb/page.h) \
    $(wildcard include/config/hugetlb/page/size/variable.h) \
  include/generated/bounds.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/page.h \
    $(wildcard include/config/cpu/copy/v3.h) \
    $(wildcard include/config/cpu/copy/v4wt.h) \
    $(wildcard include/config/cpu/copy/v4wb.h) \
    $(wildcard include/config/cpu/copy/feroceon.h) \
    $(wildcard include/config/cpu/copy/fa.h) \
    $(wildcard include/config/cpu/xscale.h) \
    $(wildcard include/config/cpu/copy/v6.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/page-nommu.h \
    $(wildcard include/config/small/tasks.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/memory.h \
    $(wildcard include/config/page/offset.h) \
    $(wildcard include/config/thumb2/kernel.h) \
    $(wildcard include/config/dram/size.h) \
    $(wildcard include/config/dram/base.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/const.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/mach-stm32/include/mach/memory.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/sizes.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/asm-generic/memory_model.h \
    $(wildcard include/config/sparsemem/vmemmap.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/asm-generic/getorder.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/memory_hotplug.h \
    $(wildcard include/config/have/arch/nodedata/extension.h) \
    $(wildcard include/config/memory/hotremove.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/notifier.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/errno.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/errno.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/asm-generic/errno.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/asm-generic/errno-base.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/mutex.h \
    $(wildcard include/config/debug/mutexes.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/rwsem.h \
    $(wildcard include/config/rwsem/generic/spinlock.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/rwsem-spinlock.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/srcu.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/topology.h \
    $(wildcard include/config/sched/smt.h) \
    $(wildcard include/config/sched/mc.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/cpumask.h \
    $(wildcard include/config/cpumask/offstack.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/debug/per/cpu/maps.h) \
    $(wildcard include/config/disable/obsolete/cpumask/functions.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/smp.h \
    $(wildcard include/config/use/generic/smp/helpers.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/topology.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/asm-generic/topology.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/mmdebug.h \
    $(wildcard include/config/debug/virtual.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/elf.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/elf-em.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/elf.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/user.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/kobject.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/sysfs.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/kref.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/moduleparam.h \
    $(wildcard include/config/alpha.h) \
    $(wildcard include/config/ia64.h) \
    $(wildcard include/config/ppc64.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/tracepoint.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/rcupdate.h \
    $(wildcard include/config/tree/rcu.h) \
    $(wildcard include/config/tree/preempt/rcu.h) \
    $(wildcard include/config/tiny/rcu.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/completion.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/rcutree.h \
    $(wildcard include/config/no/hz.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/local.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/asm-generic/local.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/percpu.h \
    $(wildcard include/config/need/per/cpu/embed/first/chunk.h) \
    $(wildcard include/config/need/per/cpu/page/first/chunk.h) \
    $(wildcard include/config/have/setup/per/cpu/area.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/slab.h \
    $(wildcard include/config/slab/debug.h) \
    $(wildcard include/config/debug/objects.h) \
    $(wildcard include/config/slub.h) \
    $(wildcard include/config/slob.h) \
    $(wildcard include/config/debug/slab.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/slab_def.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/kmemtrace.h \
    $(wildcard include/config/kmemtrace.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/trace/events/kmem.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/trace/define_trace.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/kmalloc_sizes.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/pfn.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/percpu.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/asm-generic/percpu.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/percpu-defs.h \
    $(wildcard include/config/debug/force/weak/per/cpu.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/module.h \
    $(wildcard include/config/arm/unwind.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/trace/events/module.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/fs.h \
    $(wildcard include/config/dnotify.h) \
    $(wildcard include/config/quota.h) \
    $(wildcard include/config/fsnotify.h) \
    $(wildcard include/config/inotify.h) \
    $(wildcard include/config/security.h) \
    $(wildcard include/config/fs/posix/acl.h) \
    $(wildcard include/config/epoll.h) \
    $(wildcard include/config/debug/writecount.h) \
    $(wildcard include/config/file/locking.h) \
    $(wildcard include/config/auditsyscall.h) \
    $(wildcard include/config/block.h) \
    $(wildcard include/config/fs/xip.h) \
    $(wildcard include/config/migration.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/limits.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/ioctl.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/ioctl.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/asm-generic/ioctl.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/kdev_t.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/dcache.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/rculist.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/path.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/radix-tree.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/prio_tree.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/pid.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/capability.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/semaphore.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/fiemap.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/quota.h \
    $(wildcard include/config/quota/netlink/interface.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/dqblk_xfs.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/dqblk_v1.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/dqblk_v2.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/dqblk_qtree.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/nfs_fs_i.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/nfs.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/sunrpc/msg_prot.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/inet.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/fcntl.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/fcntl.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/asm-generic/fcntl.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/err.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/uaccess.h \
    $(wildcard include/config/mpu/user/access.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/unified.h \
    $(wildcard include/config/arm/asm/unified.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/mpu.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/mm_types.h \
    $(wildcard include/config/split/ptlock/cpus.h) \
    $(wildcard include/config/want/page/debug/flags.h) \
    $(wildcard include/config/aio.h) \
    $(wildcard include/config/mm/owner.h) \
    $(wildcard include/config/proc/fs.h) \
    $(wildcard include/config/mmu/notifier.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/auxvec.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/auxvec.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/rbtree.h \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/include/linux/page-debug-flags.h \
    $(wildcard include/config/page/poisoning.h) \
    $(wildcard include/config/page/debug/something/else.h) \
  /mnt/data1/workspace/stmlinux-1.0.0/linux/arch/arm/include/asm/mmu.h \
    $(wildcard include/config/cpu/has/asid.h) \

/mnt/data1/workspace/stmlinux-1.0.0/projects/qtdemo2/app/sample.o: $(deps_/mnt/data1/workspace/stmlinux-1.0.0/projects/qtdemo2/app/sample.o)

$(deps_/mnt/data1/workspace/stmlinux-1.0.0/projects/qtdemo2/app/sample.o):
