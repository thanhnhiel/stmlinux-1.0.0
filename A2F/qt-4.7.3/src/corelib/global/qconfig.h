/* Everything */

/* Qt Edition */
#ifndef QT_EDITION
#  define QT_EDITION QT_EDITION_OPENSOURCE
#endif

/* Machine byte-order */
#define Q_BIG_ENDIAN 4321
#define Q_LITTLE_ENDIAN 1234
#define QT_BUILD_KEY "generic linux uclinuxeabi-g++ full-config"

#ifdef QT_BOOTSTRAPPED
#define Q_BYTE_ORDER Q_LITTLE_ENDIAN
#else
#define Q_BYTE_ORDER Q_LITTLE_ENDIAN
#endif
/* Machine Architecture */
#ifndef QT_BOOTSTRAPPED
# define QT_ARCH_GENERIC
#else
# define QT_ARCH_I386
#endif
/* Compile time features */
#define QT_LARGEFILE_SUPPORT 64
#define QT_POINTER_SIZE 4

#ifndef QT_BOOTSTRAPPED

#if defined(QT_CLIPBOARD) && defined(QT_NO_CLIPBOARD)
# undef QT_CLIPBOARD
#elif !defined(QT_CLIPBOARD) && !defined(QT_NO_CLIPBOARD)
# define QT_CLIPBOARD
#endif

#if defined(QT_CURSOR) && defined(QT_NO_CURSOR)
# undef QT_CURSOR
#elif !defined(QT_CURSOR) && !defined(QT_NO_CURSOR)
# define QT_CURSOR
#endif

#if defined(QT_DRAGANDDROP) && defined(QT_NO_DRAGANDDROP)
# undef QT_DRAGANDDROP
#elif !defined(QT_DRAGANDDROP) && !defined(QT_NO_DRAGANDDROP)
# define QT_DRAGANDDROP
#endif

#if defined(QT_IMAGEFORMAT_PNG) && defined(QT_NO_IMAGEFORMAT_PNG)
# undef QT_IMAGEFORMAT_PNG
#elif !defined(QT_IMAGEFORMAT_PNG) && !defined(QT_NO_IMAGEFORMAT_PNG)
# define QT_IMAGEFORMAT_PNG
#endif

#if defined(QT_NO_ACCESSIBILITY) && defined(QT_ACCESSIBILITY)
# undef QT_NO_ACCESSIBILITY
#elif !defined(QT_NO_ACCESSIBILITY) && !defined(QT_ACCESSIBILITY)
# define QT_NO_ACCESSIBILITY
#endif

#if defined(QT_NO_ALSA) && defined(QT_ALSA)
# undef QT_NO_ALSA
#elif !defined(QT_NO_ALSA) && !defined(QT_ALSA)
# define QT_NO_ALSA
#endif

#if defined(QT_NO_ANIMATION) && defined(QT_ANIMATION)
# undef QT_NO_ANIMATION
#elif !defined(QT_NO_ANIMATION) && !defined(QT_ANIMATION)
# define QT_NO_ANIMATION
#endif

#if defined(QT_NO_BEARERMANAGEMENT) && defined(QT_BEARERMANAGEMENT)
# undef QT_NO_BEARERMANAGEMENT
#elif !defined(QT_NO_BEARERMANAGEMENT) && !defined(QT_BEARERMANAGEMENT)
# define QT_NO_BEARERMANAGEMENT
#endif

#if defined(QT_NO_COMPLETER) && defined(QT_COMPLETER)
# undef QT_NO_COMPLETER
#elif !defined(QT_NO_COMPLETER) && !defined(QT_COMPLETER)
# define QT_NO_COMPLETER
#endif

#if defined(QT_NO_CONCURRENT) && defined(QT_CONCURRENT)
# undef QT_NO_CONCURRENT
#elif !defined(QT_NO_CONCURRENT) && !defined(QT_CONCURRENT)
# define QT_NO_CONCURRENT
#endif

#if defined(QT_NO_COP) && defined(QT_COP)
# undef QT_NO_COP
#elif !defined(QT_NO_COP) && !defined(QT_COP)
# define QT_NO_COP
#endif

#if defined(QT_NO_CUPS) && defined(QT_CUPS)
# undef QT_NO_CUPS
#elif !defined(QT_NO_CUPS) && !defined(QT_CUPS)
# define QT_NO_CUPS
#endif

#if defined(QT_NO_DBUS) && defined(QT_DBUS)
# undef QT_NO_DBUS
#elif !defined(QT_NO_DBUS) && !defined(QT_DBUS)
# define QT_NO_DBUS
#endif

#if defined(QT_NO_DECLARATIVE) && defined(QT_DECLARATIVE)
# undef QT_NO_DECLARATIVE
#elif !defined(QT_NO_DECLARATIVE) && !defined(QT_DECLARATIVE)
# define QT_NO_DECLARATIVE
#endif

#if defined(QT_NO_DESKTOPSERVICES) && defined(QT_DESKTOPSERVICES)
# undef QT_NO_DESKTOPSERVICES
#elif !defined(QT_NO_DESKTOPSERVICES) && !defined(QT_DESKTOPSERVICES)
# define QT_NO_DESKTOPSERVICES
#endif

#if defined(QT_NO_EFFECTS) && defined(QT_EFFECTS)
# undef QT_NO_EFFECTS
#elif !defined(QT_NO_EFFECTS) && !defined(QT_EFFECTS)
# define QT_NO_EFFECTS
#endif

#if defined(QT_NO_EGL) && defined(QT_EGL)
# undef QT_NO_EGL
#elif !defined(QT_NO_EGL) && !defined(QT_EGL)
# define QT_NO_EGL
#endif

#if defined(QT_NO_EXCEPTIONS) && defined(QT_EXCEPTIONS)
# undef QT_NO_EXCEPTIONS
#elif !defined(QT_NO_EXCEPTIONS) && !defined(QT_EXCEPTIONS)
# define QT_NO_EXCEPTIONS
#endif

#if defined(QT_NO_FILESYSTEMMODEL) && defined(QT_FILESYSTEMMODEL)
# undef QT_NO_FILESYSTEMMODEL
#elif !defined(QT_NO_FILESYSTEMMODEL) && !defined(QT_FILESYSTEMMODEL)
# define QT_NO_FILESYSTEMMODEL
#endif

#if defined(QT_NO_FILESYSTEMWATCHER) && defined(QT_FILESYSTEMWATCHER)
# undef QT_NO_FILESYSTEMWATCHER
#elif !defined(QT_NO_FILESYSTEMWATCHER) && !defined(QT_FILESYSTEMWATCHER)
# define QT_NO_FILESYSTEMWATCHER
#endif

#if defined(QT_NO_FREETYPE) && defined(QT_FREETYPE)
# undef QT_NO_FREETYPE
#elif !defined(QT_NO_FREETYPE) && !defined(QT_FREETYPE)
# define QT_NO_FREETYPE
#endif

#if defined(QT_NO_FSCOMPLETER) && defined(QT_FSCOMPLETER)
# undef QT_NO_FSCOMPLETER
#elif !defined(QT_NO_FSCOMPLETER) && !defined(QT_FSCOMPLETER)
# define QT_NO_FSCOMPLETER
#endif

#if defined(QT_NO_FTP) && defined(QT_FTP)
# undef QT_NO_FTP
#elif !defined(QT_NO_FTP) && !defined(QT_FTP)
# define QT_NO_FTP
#endif

#if defined(QT_NO_GESTURES) && defined(QT_GESTURES)
# undef QT_NO_GESTURES
#elif !defined(QT_NO_GESTURES) && !defined(QT_GESTURES)
# define QT_NO_GESTURES
#endif

#if defined(QT_NO_GETIFADDRS) && defined(QT_GETIFADDRS)
# undef QT_NO_GETIFADDRS
#elif !defined(QT_NO_GETIFADDRS) && !defined(QT_GETIFADDRS)
# define QT_NO_GETIFADDRS
#endif

#if defined(QT_NO_GLIB) && defined(QT_GLIB)
# undef QT_NO_GLIB
#elif !defined(QT_NO_GLIB) && !defined(QT_GLIB)
# define QT_NO_GLIB
#endif

#if defined(QT_NO_GSTREAMER) && defined(QT_GSTREAMER)
# undef QT_NO_GSTREAMER
#elif !defined(QT_NO_GSTREAMER) && !defined(QT_GSTREAMER)
# define QT_NO_GSTREAMER
#endif

#if defined(QT_NO_GUI) && defined(QT_GUI)
# undef QT_NO_GUI
#elif !defined(QT_NO_GUI) && !defined(QT_GUI)
# define QT_NO_GUI
#endif

#if defined(QT_NO_HOSTINFO) && defined(QT_HOSTINFO)
# undef QT_NO_HOSTINFO
#elif !defined(QT_NO_HOSTINFO) && !defined(QT_HOSTINFO)
# define QT_NO_HOSTINFO
#endif

#if defined(QT_NO_HTTP) && defined(QT_HTTP)
# undef QT_NO_HTTP
#elif !defined(QT_NO_HTTP) && !defined(QT_HTTP)
# define QT_NO_HTTP
#endif

#if defined(QT_NO_ICD) && defined(QT_ICD)
# undef QT_NO_ICD
#elif !defined(QT_NO_ICD) && !defined(QT_ICD)
# define QT_NO_ICD
#endif

#if defined(QT_NO_ICONV) && defined(QT_ICONV)
# undef QT_NO_ICONV
#elif !defined(QT_NO_ICONV) && !defined(QT_ICONV)
# define QT_NO_ICONV
#endif

#if defined(QT_NO_IM) && defined(QT_IM)
# undef QT_NO_IM
#elif !defined(QT_NO_IM) && !defined(QT_IM)
# define QT_NO_IM
#endif

#if defined(QT_NO_IMAGEFORMAT_JPEG) && defined(QT_IMAGEFORMAT_JPEG)
# undef QT_NO_IMAGEFORMAT_JPEG
#elif !defined(QT_NO_IMAGEFORMAT_JPEG) && !defined(QT_IMAGEFORMAT_JPEG)
# define QT_NO_IMAGEFORMAT_JPEG
#endif

#if defined(QT_NO_IMAGEFORMAT_MNG) && defined(QT_IMAGEFORMAT_MNG)
# undef QT_NO_IMAGEFORMAT_MNG
#elif !defined(QT_NO_IMAGEFORMAT_MNG) && !defined(QT_IMAGEFORMAT_MNG)
# define QT_NO_IMAGEFORMAT_MNG
#endif

#if defined(QT_NO_IMAGEFORMATPLUGIN) && defined(QT_IMAGEFORMATPLUGIN)
# undef QT_NO_IMAGEFORMATPLUGIN
#elif !defined(QT_NO_IMAGEFORMATPLUGIN) && !defined(QT_IMAGEFORMATPLUGIN)
# define QT_NO_IMAGEFORMATPLUGIN
#endif

#if defined(QT_NO_IMAGEFORMAT_PPM) && defined(QT_IMAGEFORMAT_PPM)
# undef QT_NO_IMAGEFORMAT_PPM
#elif !defined(QT_NO_IMAGEFORMAT_PPM) && !defined(QT_IMAGEFORMAT_PPM)
# define QT_NO_IMAGEFORMAT_PPM
#endif

#if defined(QT_NO_IMAGEFORMAT_TIFF) && defined(QT_IMAGEFORMAT_TIFF)
# undef QT_NO_IMAGEFORMAT_TIFF
#elif !defined(QT_NO_IMAGEFORMAT_TIFF) && !defined(QT_IMAGEFORMAT_TIFF)
# define QT_NO_IMAGEFORMAT_TIFF
#endif

#if defined(QT_NO_IMAGEFORMAT_XBM) && defined(QT_IMAGEFORMAT_XBM)
# undef QT_NO_IMAGEFORMAT_XBM
#elif !defined(QT_NO_IMAGEFORMAT_XBM) && !defined(QT_IMAGEFORMAT_XBM)
# define QT_NO_IMAGEFORMAT_XBM
#endif

#if defined(QT_NO_IMAGEFORMAT_XPM) && defined(QT_IMAGEFORMAT_XPM)
# undef QT_NO_IMAGEFORMAT_XPM
#elif !defined(QT_NO_IMAGEFORMAT_XPM) && !defined(QT_IMAGEFORMAT_XPM)
# define QT_NO_IMAGEFORMAT_XPM
#endif

#if defined(QT_NO_IMAGE_HEURISTIC_MASK) && defined(QT_IMAGE_HEURISTIC_MASK)
# undef QT_NO_IMAGE_HEURISTIC_MASK
#elif !defined(QT_NO_IMAGE_HEURISTIC_MASK) && !defined(QT_IMAGE_HEURISTIC_MASK)
# define QT_NO_IMAGE_HEURISTIC_MASK
#endif

#if defined(QT_NO_IMAGE_TEXT) && defined(QT_IMAGE_TEXT)
# undef QT_NO_IMAGE_TEXT
#elif !defined(QT_NO_IMAGE_TEXT) && !defined(QT_IMAGE_TEXT)
# define QT_NO_IMAGE_TEXT
#endif

#if defined(QT_NO_LIBRARY) && defined(QT_LIBRARY)
# undef QT_NO_LIBRARY
#elif !defined(QT_NO_LIBRARY) && !defined(QT_LIBRARY)
# define QT_NO_LIBRARY
#endif

#if defined(QT_NO_MDIAREA) && defined(QT_MDIAREA)
# undef QT_NO_MDIAREA
#elif !defined(QT_NO_MDIAREA) && !defined(QT_MDIAREA)
# define QT_NO_MDIAREA
#endif

#if defined(QT_NO_MOVIE) && defined(QT_MOVIE)
# undef QT_NO_MOVIE
#elif !defined(QT_NO_MOVIE) && !defined(QT_MOVIE)
# define QT_NO_MOVIE
#endif

#if defined(QT_NO_MULTIMEDIA) && defined(QT_MULTIMEDIA)
# undef QT_NO_MULTIMEDIA
#elif !defined(QT_NO_MULTIMEDIA) && !defined(QT_MULTIMEDIA)
# define QT_NO_MULTIMEDIA
#endif

#if defined(QT_NO_NAS) && defined(QT_NAS)
# undef QT_NO_NAS
#elif !defined(QT_NO_NAS) && !defined(QT_NAS)
# define QT_NO_NAS
#endif

#if defined(QT_NO_NETWORKDISKCACHE) && defined(QT_NETWORKDISKCACHE)
# undef QT_NO_NETWORKDISKCACHE
#elif !defined(QT_NO_NETWORKDISKCACHE) && !defined(QT_NETWORKDISKCACHE)
# define QT_NO_NETWORKDISKCACHE
#endif

#if defined(QT_NO_NETWORKINTERFACE) && defined(QT_NETWORKINTERFACE)
# undef QT_NO_NETWORKINTERFACE
#elif !defined(QT_NO_NETWORKINTERFACE) && !defined(QT_NETWORKINTERFACE)
# define QT_NO_NETWORKINTERFACE
#endif

#if defined(QT_NO_NETWORKPROXY) && defined(QT_NETWORKPROXY)
# undef QT_NO_NETWORKPROXY
#elif !defined(QT_NO_NETWORKPROXY) && !defined(QT_NETWORKPROXY)
# define QT_NO_NETWORKPROXY
#endif

#if defined(QT_NO_NIS) && defined(QT_NIS)
# undef QT_NO_NIS
#elif !defined(QT_NO_NIS) && !defined(QT_NIS)
# define QT_NO_NIS
#endif

#if defined(QT_NO_OPENGL) && defined(QT_OPENGL)
# undef QT_NO_OPENGL
#elif !defined(QT_NO_OPENGL) && !defined(QT_OPENGL)
# define QT_NO_OPENGL
#endif

#if defined(QT_NO_OPENSSL) && defined(QT_OPENSSL)
# undef QT_NO_OPENSSL
#elif !defined(QT_NO_OPENSSL) && !defined(QT_OPENSSL)
# define QT_NO_OPENSSL
#endif

#if defined(QT_NO_OPENVG) && defined(QT_OPENVG)
# undef QT_NO_OPENVG
#elif !defined(QT_NO_OPENVG) && !defined(QT_OPENVG)
# define QT_NO_OPENVG
#endif

#if defined(QT_NO_PHONON) && defined(QT_PHONON)
# undef QT_NO_PHONON
#elif !defined(QT_NO_PHONON) && !defined(QT_PHONON)
# define QT_NO_PHONON
#endif

#if defined(QT_NO_PHONON_PLATFORMPLUGIN) && defined(QT_PHONON_PLATFORMPLUGIN)
# undef QT_NO_PHONON_PLATFORMPLUGIN
#elif !defined(QT_NO_PHONON_PLATFORMPLUGIN) && !defined(QT_PHONON_PLATFORMPLUGIN)
# define QT_NO_PHONON_PLATFORMPLUGIN
#endif

#if defined(QT_NO_PICTURE) && defined(QT_PICTURE)
# undef QT_NO_PICTURE
#elif !defined(QT_NO_PICTURE) && !defined(QT_PICTURE)
# define QT_NO_PICTURE
#endif

#if defined(QT_NO_PRINTDIALOG) && defined(QT_PRINTDIALOG)
# undef QT_NO_PRINTDIALOG
#elif !defined(QT_NO_PRINTDIALOG) && !defined(QT_PRINTDIALOG)
# define QT_NO_PRINTDIALOG
#endif

#if defined(QT_NO_PRINTER) && defined(QT_PRINTER)
# undef QT_NO_PRINTER
#elif !defined(QT_NO_PRINTER) && !defined(QT_PRINTER)
# define QT_NO_PRINTER
#endif

#if defined(QT_NO_PRINTPREVIEWDIALOG) && defined(QT_PRINTPREVIEWDIALOG)
# undef QT_NO_PRINTPREVIEWDIALOG
#elif !defined(QT_NO_PRINTPREVIEWDIALOG) && !defined(QT_PRINTPREVIEWDIALOG)
# define QT_NO_PRINTPREVIEWDIALOG
#endif

#if defined(QT_NO_PRINTPREVIEWWIDGET) && defined(QT_PRINTPREVIEWWIDGET)
# undef QT_NO_PRINTPREVIEWWIDGET
#elif !defined(QT_NO_PRINTPREVIEWWIDGET) && !defined(QT_PRINTPREVIEWWIDGET)
# define QT_NO_PRINTPREVIEWWIDGET
#endif

#if defined(QT_NO_PROCESS) && defined(QT_PROCESS)
# undef QT_NO_PROCESS
#elif !defined(QT_NO_PROCESS) && !defined(QT_PROCESS)
# define QT_NO_PROCESS
#endif

#if defined(QT_NO_PULSEAUDIO) && defined(QT_PULSEAUDIO)
# undef QT_NO_PULSEAUDIO
#elif !defined(QT_NO_PULSEAUDIO) && !defined(QT_PULSEAUDIO)
# define QT_NO_PULSEAUDIO
#endif

#if defined(QT_NO_QUUID_STRING) && defined(QT_QUUID_STRING)
# undef QT_NO_QUUID_STRING
#elif !defined(QT_NO_QUUID_STRING) && !defined(QT_QUUID_STRING)
# define QT_NO_QUUID_STRING
#endif

#if defined(QT_NO_QWS_DIRECTFB) && defined(QT_QWS_DIRECTFB)
# undef QT_NO_QWS_DIRECTFB
#elif !defined(QT_NO_QWS_DIRECTFB) && !defined(QT_QWS_DIRECTFB)
# define QT_NO_QWS_DIRECTFB
#endif

#if defined(QT_NO_QWS_KBD_LINUXINPUT) && defined(QT_QWS_KBD_LINUXINPUT)
# undef QT_NO_QWS_KBD_LINUXINPUT
#elif !defined(QT_NO_QWS_KBD_LINUXINPUT) && !defined(QT_QWS_KBD_LINUXINPUT)
# define QT_NO_QWS_KBD_LINUXINPUT
#endif

#if defined(QT_NO_QWS_KBD_QNX) && defined(QT_QWS_KBD_QNX)
# undef QT_NO_QWS_KBD_QNX
#elif !defined(QT_NO_QWS_KBD_QNX) && !defined(QT_QWS_KBD_QNX)
# define QT_NO_QWS_KBD_QNX
#endif

#if defined(QT_NO_QWS_KBD_QVFB) && defined(QT_QWS_KBD_QVFB)
# undef QT_NO_QWS_KBD_QVFB
#elif !defined(QT_NO_QWS_KBD_QVFB) && !defined(QT_QWS_KBD_QVFB)
# define QT_NO_QWS_KBD_QVFB
#endif

#if defined(QT_NO_QWS_KBD_TTY) && defined(QT_QWS_KBD_TTY)
# undef QT_NO_QWS_KBD_TTY
#elif !defined(QT_NO_QWS_KBD_TTY) && !defined(QT_QWS_KBD_TTY)
# define QT_NO_QWS_KBD_TTY
#endif

#if defined(QT_NO_QWS_KBD_UM) && defined(QT_QWS_KBD_UM)
# undef QT_NO_QWS_KBD_UM
#elif !defined(QT_NO_QWS_KBD_UM) && !defined(QT_QWS_KBD_UM)
# define QT_NO_QWS_KBD_UM
#endif

#if defined(QT_NO_QWS_MANAGER) && defined(QT_QWS_MANAGER)
# undef QT_NO_QWS_MANAGER
#elif !defined(QT_NO_QWS_MANAGER) && !defined(QT_QWS_MANAGER)
# define QT_NO_QWS_MANAGER
#endif

#if defined(QT_NO_QWS_MOUSE_QNX) && defined(QT_QWS_MOUSE_QNX)
# undef QT_NO_QWS_MOUSE_QNX
#elif !defined(QT_NO_QWS_MOUSE_QNX) && !defined(QT_QWS_MOUSE_QNX)
# define QT_NO_QWS_MOUSE_QNX
#endif

#if defined(QT_NO_QWS_MOUSE_QVFB) && defined(QT_QWS_MOUSE_QVFB)
# undef QT_NO_QWS_MOUSE_QVFB
#elif !defined(QT_NO_QWS_MOUSE_QVFB) && !defined(QT_QWS_MOUSE_QVFB)
# define QT_NO_QWS_MOUSE_QVFB
#endif

#if defined(QT_NO_QWS_MOUSE_TSLIB) && defined(QT_QWS_MOUSE_TSLIB)
# undef QT_NO_QWS_MOUSE_TSLIB
#elif !defined(QT_NO_QWS_MOUSE_TSLIB) && !defined(QT_QWS_MOUSE_TSLIB)
# define QT_NO_QWS_MOUSE_TSLIB
#endif

#if defined(QT_NO_QWS_MULTIPROCESS) && defined(QT_QWS_MULTIPROCESS)
# undef QT_NO_QWS_MULTIPROCESS
#elif !defined(QT_NO_QWS_MULTIPROCESS) && !defined(QT_QWS_MULTIPROCESS)
# define QT_NO_QWS_MULTIPROCESS
#endif

#if defined(QT_NO_QWS_PROPERTIES) && defined(QT_QWS_PROPERTIES)
# undef QT_NO_QWS_PROPERTIES
#elif !defined(QT_NO_QWS_PROPERTIES) && !defined(QT_QWS_PROPERTIES)
# define QT_NO_QWS_PROPERTIES
#endif

#if defined(QT_NO_QWS_QNX) && defined(QT_QWS_QNX)
# undef QT_NO_QWS_QNX
#elif !defined(QT_NO_QWS_QNX) && !defined(QT_QWS_QNX)
# define QT_NO_QWS_QNX
#endif

#if defined(QT_NO_QWS_QVFB) && defined(QT_QWS_QVFB)
# undef QT_NO_QWS_QVFB
#elif !defined(QT_NO_QWS_QVFB) && !defined(QT_QWS_QVFB)
# define QT_NO_QWS_QVFB
#endif

#if defined(QT_NO_QWS_SOUNDSERVER) && defined(QT_QWS_SOUNDSERVER)
# undef QT_NO_QWS_SOUNDSERVER
#elif !defined(QT_NO_QWS_SOUNDSERVER) && !defined(QT_QWS_SOUNDSERVER)
# define QT_NO_QWS_SOUNDSERVER
#endif

#if defined(QT_NO_QWS_TRANSFORMED) && defined(QT_QWS_TRANSFORMED)
# undef QT_NO_QWS_TRANSFORMED
#elif !defined(QT_NO_QWS_TRANSFORMED) && !defined(QT_QWS_TRANSFORMED)
# define QT_NO_QWS_TRANSFORMED
#endif

#if defined(QT_NO_QWS_VNC) && defined(QT_QWS_VNC)
# undef QT_NO_QWS_VNC
#elif !defined(QT_NO_QWS_VNC) && !defined(QT_QWS_VNC)
# define QT_NO_QWS_VNC
#endif

#if defined(QT_NO_S60) && defined(QT_S60)
# undef QT_NO_S60
#elif !defined(QT_NO_S60) && !defined(QT_S60)
# define QT_NO_S60
#endif

#if defined(QT_NO_SCRIPT) && defined(QT_SCRIPT)
# undef QT_NO_SCRIPT
#elif !defined(QT_NO_SCRIPT) && !defined(QT_SCRIPT)
# define QT_NO_SCRIPT
#endif

#if defined(QT_NO_SCRIPTTOOLS) && defined(QT_SCRIPTTOOLS)
# undef QT_NO_SCRIPTTOOLS
#elif !defined(QT_NO_SCRIPTTOOLS) && !defined(QT_SCRIPTTOOLS)
# define QT_NO_SCRIPTTOOLS
#endif

#if defined(QT_NO_SESSIONMANAGER) && defined(QT_SESSIONMANAGER)
# undef QT_NO_SESSIONMANAGER
#elif !defined(QT_NO_SESSIONMANAGER) && !defined(QT_SESSIONMANAGER)
# define QT_NO_SESSIONMANAGER
#endif

#if defined(QT_NO_SHAREDMEMORY) && defined(QT_SHAREDMEMORY)
# undef QT_NO_SHAREDMEMORY
#elif !defined(QT_NO_SHAREDMEMORY) && !defined(QT_SHAREDMEMORY)
# define QT_NO_SHAREDMEMORY
#endif

#if defined(QT_NO_SIZEGRIP) && defined(QT_SIZEGRIP)
# undef QT_NO_SIZEGRIP
#elif !defined(QT_NO_SIZEGRIP) && !defined(QT_SIZEGRIP)
# define QT_NO_SIZEGRIP
#endif

#if defined(QT_NO_SOCKS5) && defined(QT_SOCKS5)
# undef QT_NO_SOCKS5
#elif !defined(QT_NO_SOCKS5) && !defined(QT_SOCKS5)
# define QT_NO_SOCKS5
#endif

#if defined(QT_NO_SOUND) && defined(QT_SOUND)
# undef QT_NO_SOUND
#elif !defined(QT_NO_SOUND) && !defined(QT_SOUND)
# define QT_NO_SOUND
#endif

#if defined(QT_NO_STYLE_GTK) && defined(QT_STYLE_GTK)
# undef QT_NO_STYLE_GTK
#elif !defined(QT_NO_STYLE_GTK) && !defined(QT_STYLE_GTK)
# define QT_NO_STYLE_GTK
#endif

#if defined(QT_NO_STYLE_S60) && defined(QT_STYLE_S60)
# undef QT_NO_STYLE_S60
#elif !defined(QT_NO_STYLE_S60) && !defined(QT_STYLE_S60)
# define QT_NO_STYLE_S60
#endif

#if defined(QT_NO_SXE) && defined(QT_SXE)
# undef QT_NO_SXE
#elif !defined(QT_NO_SXE) && !defined(QT_SXE)
# define QT_NO_SXE
#endif

#if defined(QT_NO_SYNTAXHIGHLIGHTER) && defined(QT_SYNTAXHIGHLIGHTER)
# undef QT_NO_SYNTAXHIGHLIGHTER
#elif !defined(QT_NO_SYNTAXHIGHLIGHTER) && !defined(QT_SYNTAXHIGHLIGHTER)
# define QT_NO_SYNTAXHIGHLIGHTER
#endif

#if defined(QT_NO_SYSTEMSEMAPHORE) && defined(QT_SYSTEMSEMAPHORE)
# undef QT_NO_SYSTEMSEMAPHORE
#elif !defined(QT_NO_SYSTEMSEMAPHORE) && !defined(QT_SYSTEMSEMAPHORE)
# define QT_NO_SYSTEMSEMAPHORE
#endif

#if defined(QT_NO_SYSTEMTRAYICON) && defined(QT_SYSTEMTRAYICON)
# undef QT_NO_SYSTEMTRAYICON
#elif !defined(QT_NO_SYSTEMTRAYICON) && !defined(QT_SYSTEMTRAYICON)
# define QT_NO_SYSTEMTRAYICON
#endif

#if defined(QT_NO_TEXTBROWSER) && defined(QT_TEXTBROWSER)
# undef QT_NO_TEXTBROWSER
#elif !defined(QT_NO_TEXTBROWSER) && !defined(QT_TEXTBROWSER)
# define QT_NO_TEXTBROWSER
#endif

#if defined(QT_NO_TEXTCODECPLUGIN) && defined(QT_TEXTCODECPLUGIN)
# undef QT_NO_TEXTCODECPLUGIN
#elif !defined(QT_NO_TEXTCODECPLUGIN) && !defined(QT_TEXTCODECPLUGIN)
# define QT_NO_TEXTCODECPLUGIN
#endif

#if defined(QT_NO_TEXTODFWRITER) && defined(QT_TEXTODFWRITER)
# undef QT_NO_TEXTODFWRITER
#elif !defined(QT_NO_TEXTODFWRITER) && !defined(QT_TEXTODFWRITER)
# define QT_NO_TEXTODFWRITER
#endif

#if defined(QT_NO_UDPSOCKET) && defined(QT_UDPSOCKET)
# undef QT_NO_UDPSOCKET
#elif !defined(QT_NO_UDPSOCKET) && !defined(QT_UDPSOCKET)
# define QT_NO_UDPSOCKET
#endif

#if defined(QT_NO_UNDOCOMMAND) && defined(QT_UNDOCOMMAND)
# undef QT_NO_UNDOCOMMAND
#elif !defined(QT_NO_UNDOCOMMAND) && !defined(QT_UNDOCOMMAND)
# define QT_NO_UNDOCOMMAND
#endif

#if defined(QT_NO_UNDOGROUP) && defined(QT_UNDOGROUP)
# undef QT_NO_UNDOGROUP
#elif !defined(QT_NO_UNDOGROUP) && !defined(QT_UNDOGROUP)
# define QT_NO_UNDOGROUP
#endif

#if defined(QT_NO_UNDOSTACK) && defined(QT_UNDOSTACK)
# undef QT_NO_UNDOSTACK
#elif !defined(QT_NO_UNDOSTACK) && !defined(QT_UNDOSTACK)
# define QT_NO_UNDOSTACK
#endif

#if defined(QT_NO_UNDOVIEW) && defined(QT_UNDOVIEW)
# undef QT_NO_UNDOVIEW
#elif !defined(QT_NO_UNDOVIEW) && !defined(QT_UNDOVIEW)
# define QT_NO_UNDOVIEW
#endif

#if defined(QT_NO_URLINFO) && defined(QT_URLINFO)
# undef QT_NO_URLINFO
#elif !defined(QT_NO_URLINFO) && !defined(QT_URLINFO)
# define QT_NO_URLINFO
#endif

#if defined(QT_NO_WEBKIT) && defined(QT_WEBKIT)
# undef QT_NO_WEBKIT
#elif !defined(QT_NO_WEBKIT) && !defined(QT_WEBKIT)
# define QT_NO_WEBKIT
#endif

#if defined(QT_NO_WORKSPACE) && defined(QT_WORKSPACE)
# undef QT_NO_WORKSPACE
#elif !defined(QT_NO_WORKSPACE) && !defined(QT_WORKSPACE)
# define QT_NO_WORKSPACE
#endif

#if defined(QT_NO_XMLPATTERNS) && defined(QT_XMLPATTERNS)
# undef QT_NO_XMLPATTERNS
#elif !defined(QT_NO_XMLPATTERNS) && !defined(QT_XMLPATTERNS)
# define QT_NO_XMLPATTERNS
#endif

#if defined(QT_QWS_DEPTH_1) && defined(QT_NO_QWS_DEPTH_1)
# undef QT_QWS_DEPTH_1
#elif !defined(QT_QWS_DEPTH_1) && !defined(QT_NO_QWS_DEPTH_1)
# define QT_QWS_DEPTH_1
#endif

#if defined(QT_QWS_DEPTH_12) && defined(QT_NO_QWS_DEPTH_12)
# undef QT_QWS_DEPTH_12
#elif !defined(QT_QWS_DEPTH_12) && !defined(QT_NO_QWS_DEPTH_12)
# define QT_QWS_DEPTH_12
#endif

#if defined(QT_QWS_DEPTH_15) && defined(QT_NO_QWS_DEPTH_15)
# undef QT_QWS_DEPTH_15
#elif !defined(QT_QWS_DEPTH_15) && !defined(QT_NO_QWS_DEPTH_15)
# define QT_QWS_DEPTH_15
#endif

#if defined(QT_QWS_DEPTH_16) && defined(QT_NO_QWS_DEPTH_16)
# undef QT_QWS_DEPTH_16
#elif !defined(QT_QWS_DEPTH_16) && !defined(QT_NO_QWS_DEPTH_16)
# define QT_QWS_DEPTH_16
#endif

#if defined(QT_QWS_DEPTH_18) && defined(QT_NO_QWS_DEPTH_18)
# undef QT_QWS_DEPTH_18
#elif !defined(QT_QWS_DEPTH_18) && !defined(QT_NO_QWS_DEPTH_18)
# define QT_QWS_DEPTH_18
#endif

#if defined(QT_QWS_DEPTH_24) && defined(QT_NO_QWS_DEPTH_24)
# undef QT_QWS_DEPTH_24
#elif !defined(QT_QWS_DEPTH_24) && !defined(QT_NO_QWS_DEPTH_24)
# define QT_QWS_DEPTH_24
#endif

#if defined(QT_QWS_DEPTH_32) && defined(QT_NO_QWS_DEPTH_32)
# undef QT_QWS_DEPTH_32
#elif !defined(QT_QWS_DEPTH_32) && !defined(QT_NO_QWS_DEPTH_32)
# define QT_QWS_DEPTH_32
#endif

#if defined(QT_QWS_DEPTH_4) && defined(QT_NO_QWS_DEPTH_4)
# undef QT_QWS_DEPTH_4
#elif !defined(QT_QWS_DEPTH_4) && !defined(QT_NO_QWS_DEPTH_4)
# define QT_QWS_DEPTH_4
#endif

#if defined(QT_QWS_DEPTH_8) && defined(QT_NO_QWS_DEPTH_8)
# undef QT_QWS_DEPTH_8
#elif !defined(QT_QWS_DEPTH_8) && !defined(QT_NO_QWS_DEPTH_8)
# define QT_QWS_DEPTH_8
#endif

#if defined(QT_QWS_DEPTH_GENERIC) && defined(QT_NO_QWS_DEPTH_GENERIC)
# undef QT_QWS_DEPTH_GENERIC
#elif !defined(QT_QWS_DEPTH_GENERIC) && !defined(QT_NO_QWS_DEPTH_GENERIC)
# define QT_QWS_DEPTH_GENERIC
#endif

#if defined(QT_QWS_MOUSE) && defined(QT_NO_QWS_MOUSE)
# undef QT_QWS_MOUSE
#elif !defined(QT_QWS_MOUSE) && !defined(QT_NO_QWS_MOUSE)
# define QT_QWS_MOUSE
#endif

#if defined(QT_RUNTIME_XCURSOR) && defined(QT_NO_RUNTIME_XCURSOR)
# undef QT_RUNTIME_XCURSOR
#elif !defined(QT_RUNTIME_XCURSOR) && !defined(QT_NO_RUNTIME_XCURSOR)
# define QT_RUNTIME_XCURSOR
#endif

#if defined(QT_RUNTIME_XFIXES) && defined(QT_NO_RUNTIME_XFIXES)
# undef QT_RUNTIME_XFIXES
#elif !defined(QT_RUNTIME_XFIXES) && !defined(QT_NO_RUNTIME_XFIXES)
# define QT_RUNTIME_XFIXES
#endif

#if defined(QT_RUNTIME_XINERAMA) && defined(QT_NO_RUNTIME_XINERAMA)
# undef QT_RUNTIME_XINERAMA
#elif !defined(QT_RUNTIME_XINERAMA) && !defined(QT_NO_RUNTIME_XINERAMA)
# define QT_RUNTIME_XINERAMA
#endif

#if defined(QT_RUNTIME_XINPUT) && defined(QT_NO_RUNTIME_XINPUT)
# undef QT_RUNTIME_XINPUT
#elif !defined(QT_RUNTIME_XINPUT) && !defined(QT_NO_RUNTIME_XINPUT)
# define QT_RUNTIME_XINPUT
#endif

#if defined(QT_RUNTIME_XRANDR) && defined(QT_NO_RUNTIME_XRANDR)
# undef QT_RUNTIME_XRANDR
#elif !defined(QT_RUNTIME_XRANDR) && !defined(QT_NO_RUNTIME_XRANDR)
# define QT_RUNTIME_XRANDR
#endif

#if defined(QT_TEXTHTMLPARSER) && defined(QT_NO_TEXTHTMLPARSER)
# undef QT_TEXTHTMLPARSER
#elif !defined(QT_TEXTHTMLPARSER) && !defined(QT_NO_TEXTHTMLPARSER)
# define QT_TEXTHTMLPARSER
#endif

#if defined(QT_USE_MATH_H_FLOATS) && defined(QT_NO_USE_MATH_H_FLOATS)
# undef QT_USE_MATH_H_FLOATS
#elif !defined(QT_USE_MATH_H_FLOATS) && !defined(QT_NO_USE_MATH_H_FLOATS)
# define QT_USE_MATH_H_FLOATS
#endif

#if defined(QT_WHEELEVENT) && defined(QT_NO_WHEELEVENT)
# undef QT_WHEELEVENT
#elif !defined(QT_WHEELEVENT) && !defined(QT_NO_WHEELEVENT)
# define QT_WHEELEVENT
#endif

#ifndef Q_WS_QWS
# define Q_WS_QWS
#endif

#endif // QT_BOOTSTRAPPED

#define QT_VISIBILITY_AVAILABLE

