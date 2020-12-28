#ifndef MQTT_H
#define MQTT_H
#pragma once
#include<qmqtt/qmqttDepends>
#include<qmqtt_client.h>
#include<qmqtt_global.h>
#include<qmqtt.h>
#include <QObject>
class MQTT:public QObject
{
   Q_OBJECT
public:

    QMQTT::Client* Client;
    MQTT();
    void connect();
    void ConnectState();


};

#endif // MQTT_H
