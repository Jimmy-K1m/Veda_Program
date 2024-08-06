#include "widget.h"

#include <QApplication>
#include <QLineEdit>
#include <QString>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QLineEdit *lineEdit = new QLineEdit();
    //lineEdit->setEchoMode(QLineEdit::Password);
    lineEdit->setEchoMode(QLineEdit::Normal);
    lineEdit->setInputMask("0000");
    lineEdit->setPlaceholderText("input the number");
    // int ix=0;
    // QObject::connect(lineEdit, &QLineEdit::textChanged, [&](){ str; for(int i = 0 ;i<=ix; i++ )str.append("*");lineEdit->setEchoMode(str);ix++;});
    QObject::connect(lineEdit, &QLineEdit::editingFinished, [&](){qDebug()<< lineEdit->text();});

    lineEdit->show();

    return a.exec();
}
