#include <QCoreApplication>
#include <iostream>
#include <mqtt.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MQTT* N1;
    N1 =new MQTT();
    std::cout<<"Ready for MQTT connect...\n";
    system("pause");
    N1->connect();

    return a.exec();
}
