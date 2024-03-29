﻿#include "mqtt.h"
#include"iostream"
using namespace QMQTT;
MQTT::MQTT()
{
    Client =new QMQTT::Client();
    QObject::connect(Client,&QMQTT::Client::connected,this,&MQTT::ConnectState);
    QObject::connect(Client,&QMQTT::Client::published,this,&MQTT::PublishState);
    QObject::connect(Client,&QMQTT::Client::subscribed,this,&MQTT::SubcribeState);
    QObject::connect(Client,&QMQTT::Client::received,this,&MQTT::Received);


//    connect(Client,SIGNAL(connected()),this,SLOT(doprocess_connected()));
//    connect(Client,SIGNAL(subscribed(QString,quint8)),this,SLOT(doprocess_subscribled(QString,quint8)));
//    connect(Client,SIGNAL(received(QMQTT::Message)),this,SLOT(doprocess_receivemessage(QMQTT::Message)));
//    connect(Client,SIGNAL(unsubscribed(QString)),this,SLOT(doprocess_unsubscrbled(QString)));
//    connect(Client,SIGNAL(error(QMQTT::ClientError)),this,SLOT(doprocess_mqtterror(QMQTT::ClientError)));
//    connect(Client,SIGNAL(disconnected()),this,SLOT(doprocess_disconnected()));
}
void MQTT::connect()
{

  ///=================================接收端登录
    QString password = "0EC379642187138440154CF6CDD4F23B711D44CA";
    Client->setHostName("a1GmkhtgJeN.iot-as-mqtt.cn-shanghai.aliyuncs.com");//服务器地址
    Client->setClientId("008|securemode=3,signmethod=hmacsha1|");
    Client->setPort(static_cast<quint16>(1883));
    Client->setPassword(password.toLocal8Bit());
    Client->setUsername("WEIXING&a1GmkhtgJeN");
    Client->setKeepAlive(60);
    Client->connectToHost();
///===================================发射端登陆
//       QString password = "E350E4EDF03861E9BB21B00C2FBD3DF4E1F14138";
//       Client->setHostName("a1GmkhtgJeN.iot-as-mqtt.cn-shanghai.aliyuncs.com");//服务器地址
//       Client->setClientId("001|securemode=3,signmethod=hmacsha1|");
//       Client->setPort(static_cast<quint16>(1883));
//       Client->setPassword(password.toLocal8Bit());
//       Client->setUsername("fashe&a1GmkhtgJeN");
//       Client->setKeepAlive(60);
//       Client->connectToHost();

};

void MQTT::ConnectState()
{
    std::cout<<"connect success!\n";
//    int input =1 ;
//    std::cout<<"Please enter 7 to publish to AliYun ...\n";
//    std::scanf("%d", &input);
//    if(input==7)
//    {
//        std::cout<<"Publishing...\n";
//        const quint16 id         = 110;
//        const QString topic      = "/g3naB3HCqbw/u01B6E9fU9WWA1KLVANB/user/update";
//        const QByteArray payload = "{\"temperature\":35.0, \"time\":\"sometime\"}";
//        const quint8 qos         = 0;
//        const bool retain        = true;
//        const Message message(id, topic, payload, qos, retain);
//       // QMQTT::Message Message("DCWX the second message");
//        Client->publish(message);
//    }
    Listing();
    //Publish();
}
void MQTT::PublishState()
 {
     std::cout<<"published success!...\n";
    // Listing();
 };
void MQTT::Listing()
{
    std::cout<<"Ready for GET...\n";
    system("pause");
    Client->subscribe("/a1GmkhtgJeN/WEIXING/user/get",1);
}
void MQTT::Received(const QMQTT::Message &message)
{
 // std::cout<< QByteArray::fromBase64(message.payload()).toStdString() ;
  std::cout<<message.payload().toHex().toStdString();
}
void MQTT::SubcribeState()
{
    std::cout<< "SubcribeState Successed!!...\n";
    std::cout<< "Waiting for message....";
}
void MQTT::Publish()
{       const quint16 id         = 001;
        const QString topic      = "/a1GmkhtgJeN/fashe/user/update";
        const QByteArray payload = "test update";
        const quint8 qos         = 0;
        const bool retain        = true;
        const Message message(id, topic, payload, qos, retain);
        Client->publish(message);
};
