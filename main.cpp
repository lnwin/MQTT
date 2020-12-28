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
   // int input ;
   // scanf_s("%d", &input);//等待输入判断获取的数字
    N1->connect();
    return a.exec();
}
