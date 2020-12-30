#include "mqtt.h"
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

   // QObject::connect(Client,&QMQTT::Client::connected,this,&MQTT::ConnectState);
    QString password = "A99517618411A9B71BAA5C69B9B40A06F334B237";
    Client->setHostName("g3naB3HCqbw.iot-as-mqtt.cn-shanghai.aliyuncs.com");//服务器地址
    Client->setClientId("008|securemode=3,signmethod=hmacsha1|");
   // Client->setHost(QHostAddress("mqtt://g3naB3HCqbw.iot-as-mqtt.cn-shanghai.aliyuncs.com"));
    Client->setPort(static_cast<quint16>(1883));
    Client->setPassword(password.toLocal8Bit());
    Client->setUsername("Izi7VInmeoSOooQwlfJO&g3naB3HCqbw");
    Client->setKeepAlive(60);
    Client->connectToHost();



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
}
void MQTT::PublishState()
 {
     std::cout<<"published success!...\n";
     Listing();
 };
void MQTT::Listing()
{
    std::cout<<"Ready for GET...\n";
    system("pause");
    Client->subscribe("/g3naB3HCqbw/Izi7VInmeoSOooQwlfJO/user/get",1);
}
void MQTT::Received(const QMQTT::Message &message)
{
  std::cout<< QByteArray::fromBase64(message.payload()).toStdString().erase(0,6) ;
  std::cout<< "\n";
}
void MQTT::SubcribeState()
{
    std::cout<< "SubcribeState Successed!!...\n";
    std::cout<< "Waiting for message....";
}
