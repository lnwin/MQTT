#include "mqtt.h"
#include"iostream"
using namespace QMQTT;
MQTT::MQTT()
{

}
void MQTT::connect()
{

    QString password = "3758F96EE1B85A547B0CE93A19A87F9ED6EF364C";
    Client =new QMQTT::Client();
    Client->setHostName("110");
    Client->setClientId("MyAli|securemode=3,signmethod=hmacsha1|");
    Client->setHost(QHostAddress("mqtt://g3naB3HCqbw.iot-as-mqtt.cn-shanghai.aliyuncs.com"));

    Client->setPort(static_cast<quint16>(1883));
    Client->setPassword(password.toLocal8Bit());
    Client->setUsername("u01B6E9fU9WWA1KLVANB&g3naB3HCqbw");
    Client->setKeepAlive(60);
    Client->connectToHost();

};
