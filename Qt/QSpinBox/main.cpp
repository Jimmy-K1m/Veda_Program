#include "widget.h"

#include <QApplication>
#include <QSpinBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSpinBox *spinBox = new QSpinBox();
    spinBox -> setRange(0,10);
    spinBox->setSuffix("%");
    spinBox->setWrapping(true);
    spinBox->setSpecialValueText("Percent");
    QObject::connect(spinBox , &QSpinBox::valueChanged, [](){qDebug( "----");});

    spinBox->show();

    return a.exec();
}
