#include "pushbutton.h"


PushButton::PushButton()
{

}
QString PushButton::slotValue(){


    return this->text();
}

PushButton::PushButton(QString a ){
    this->setText(a);
}
/*
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

}

Widget::~Widget()
{

}

void Widget::slotLabel(){
    qDebug("slotLabel");
    qApp->quit();
}



*/
