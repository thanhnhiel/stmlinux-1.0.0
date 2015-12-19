#configuration
CONFIG +=  def_files_disabled no_mocdepend release stl qt_no_framework
QT_ARCH = generic
QT_EDITION = OpenSource
QT_CONFIG +=  minimal-config small-config medium-config large-config full-config embedded reduce_exports ipv6 clock-gettime clock-monotonic mremap getaddrinfo ipv6ifname inotify no-jpeg no-mng png no-gif no-tiff no-freetype zlib svg release

#versioning
QT_VERSION = 4.7.3
QT_MAJOR_VERSION = 4
QT_MINOR_VERSION = 7
QT_PATCH_VERSION = 3

#namespaces
QT_LIBINFIX = 
QT_NAMESPACE = 
QT_NAMESPACE_MAC_CRC = 

QMAKE_RPATHDIR += "/usr/local/Trolltech/QtEmbedded-4.7.3-generic/lib"
