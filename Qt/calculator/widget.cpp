#include "widget.h"
#include "./ui_widget.h"

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

