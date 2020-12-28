#ifndef MQTT_H
#define MQTT_H
#pragma once
#include<qmqtt/qmqttDepends>
#include<qmqtt_client.h>
#include<qmqtt_global.h>
#include<qmqtt.h>
class MQTT
{
  // Q_OBJECT
public:

    QMQTT::Client* Client;
    MQTT();
    void connect();

};

#endif // MQTT_H
