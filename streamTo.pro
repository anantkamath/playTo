TEMPLATE = app

QT += qml quick widgets dbus

SOURCES += main.cpp \
    dbus/ManagerIface.cpp \
    dbus/MediaPlayer2Iface.cpp \
    dbus/PlayerIface.cpp \
    dbus/PushHostIface.cpp \
    dbus/RendererDeviceIface.cpp \
    manager.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    dbus/ManagerIface.h \
    dbus/MediaPlayer2Iface.h \
    dbus/PlayerIface.h \
    dbus/PushHostIface.h \
    dbus/RendererDeviceIface.h \
    manager.h \
    dbus/dbus.h
