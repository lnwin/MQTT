QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle
QT       += core gui network
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        mqtt.cpp \
        mqtt/qmqtt_client.cpp \
        mqtt/qmqtt_client_p.cpp \
        mqtt/qmqtt_frame.cpp \
        mqtt/qmqtt_message.cpp \
        mqtt/qmqtt_network.cpp \
        mqtt/qmqtt_router.cpp \
        mqtt/qmqtt_routesubscription.cpp \
        mqtt/qmqtt_socket.cpp \
        mqtt/qmqtt_ssl_socket.cpp \
        mqtt/qmqtt_timer.cpp \
        mqtt/qmqtt_websocket.cpp \
        mqtt/qmqtt_websocketiodevice.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    mqtt.h \
    mqtt/include/qmqtt/qmqttDepends \
    mqtt/qmqtt.h \
    mqtt/qmqtt_client.h \
    mqtt/qmqtt_client_p.h \
    mqtt/qmqtt_frame.h \
    mqtt/qmqtt_global.h \
    mqtt/qmqtt_message.h \
    mqtt/qmqtt_message_p.h \
    mqtt/qmqtt_network_p.h \
    mqtt/qmqtt_networkinterface.h \
    mqtt/qmqtt_routedmessage.h \
    mqtt/qmqtt_router.h \
    mqtt/qmqtt_routesubscription.h \
    mqtt/qmqtt_socket_p.h \
    mqtt/qmqtt_socketinterface.h \
    mqtt/qmqtt_ssl_socket_p.h \
    mqtt/qmqtt_timer_p.h \
    mqtt/qmqtt_timerinterface.h \
    mqtt/qmqtt_websocket_p.h \
    mqtt/qmqtt_websocketiodevice_p.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/mqtt/lib/ -lqmqtt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/mqtt/lib/ -lqmqttd
else:unix: LIBS += -L$$PWD/mqtt/lib/ -lqmqtt

INCLUDEPATH += $$PWD/mqtt/include
DEPENDPATH += $$PWD/mqtt/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/mqtt/lib/ -lqmqtt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/mqtt/lib/ -lqmqttd
else:unix: LIBS += -L$$PWD/mqtt/lib/ -lqmqtt

INCLUDEPATH += $$PWD/mqtt
DEPENDPATH += $$PWD/mqtt

SUBDIRS += \
    mqtt/qmqtt.pro

DISTFILES += \
    mqtt/lib/cmake/Qt5qmqtt/ExtraSourceIncludes.cmake \
    mqtt/lib/cmake/Qt5qmqtt/Qt5qmqttConfig.cmake \
    mqtt/lib/cmake/Qt5qmqtt/Qt5qmqttConfigVersion.cmake \
    mqtt/lib/libqmqtt.a \
    mqtt/lib/libqmqttd.a \
    mqtt/lib/pkgconfig/qmqtt.pc \
    mqtt/lib/qmqtt.dll \
    mqtt/lib/qmqtt.prl \
    mqtt/lib/qmqttd.dll \
    mqtt/lib/qmqttd.prl \
    mqtt/qmqtt.pri \
    mqtt/qmqtt.qbs \
    mqtt/qmqttModule.qbs

RESOURCES +=


