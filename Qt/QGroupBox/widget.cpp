#include "widget.h"
#include "./ui_widget.h"
#include <iostream>

using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QString answer_ID = "test";
    QString answer_password ="1234";
    QStringList labels;
    labels << "&ID" << "&PASSWORD";
    QLineEdit* lineEdit[2];
    QFormLayout *formLayout = new QFormLayout;
    for(int i = 0 ; i < 2; i++)
    {
        lineEdit[i] = new QLineEdit(this);
        // if(i == 0)
        // {
        //     lineEdit[i]->setInput
        // }
        lineEdit[i]->setMaxLength(10);
        if(i == 1)
            lineEdit[i]->setEchoMode(QLineEdit::Password);
        formLayout->addRow(labels.at(i), lineEdit[i]);
    }


    QGroupBox *groupBox = new QGroupBox("&로그인", this);
    groupBox->move(5,5);
    groupBox->setLayout(formLayout);

    resize(groupBox->sizeHint().width()+10, groupBox->sizeHint().height()+10);

    //connect(lineEdit[0], &QLineEdit::textChanged, [=]()mutable{cout << string(lineEdit[0]->text());});
    QObject::connect(lineEdit[1], &QLineEdit::editingFinished, [=]()mutable{
        if((lineEdit[0]->text() == answer_ID) && (lineEdit[1]->text() == answer_password))
            qDebug()<< "Complete";
                     else qDebug()<<"Fail";
                     });


}

Widget::~Widget()
{
}
