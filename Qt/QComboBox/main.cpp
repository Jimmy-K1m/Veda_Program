#include "widget.h"

#include <QApplication>
#include <QComboBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QComboBox *comboBox = new QComboBox();
    comboBox->addItem("KDE");
    comboBox->addItem("Gnome");
    comboBox->addItem("FVWM");
    comboBox->addItem("CDE");
    comboBox->setEditable(true);
    comboBox->show();

    QObject::connect(comboBox,&QComboBox::editTextChanged,[&](){qDebug()<< comboBox->currentText();});

    return a.exec();
}
