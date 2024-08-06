#include "widget.h"
#include <QDial>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDial *dial = new QDial();
    dial->setWrapping(true);
    dial->setNotchesVisible(true);
    dial->setNotchTarget(10);
    dial->show();

    QObject::connect(dial, &QDial::valueChanged ,[=](){qDebug() << dial->value();});

    return a.exec();
}
