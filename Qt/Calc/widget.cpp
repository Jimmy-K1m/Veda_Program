#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , m_isFirst(true)
{
    m_label = new QLabel("0", this);
    m_label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    m_label->setGeometry(10,5,230,40);

    const char ButtonChar[4][2] = {"+","-","=","C", "1","2","3","4"};

    for(int y = 0; y < 4; y++)
    {
        for(int x = 0 ; x<2;x++)
        {
            m_buttons.append(new QPushButton(ButtonChar[x+y*4],this));
            m_buttons.at(x+y*4) -> setGeometry(5+60*x, 50+60*y, 60,60);
        }

    }

    connect(m_buttons.at(0), SIGNAL(clicked()), SLOT(setOp()));
    connect(m_buttons.at(1), SIGNAL(clicked()), SLOT(setOp()));
    connect(m_buttons.at(2), SIGNAL(clicked()), [this](){qreal_result = 0; m_isFirst = true; if(m_op == "+") result = m_num1.toDouble()+m_label->text().toDouble();
    else if(m_op == "-") result = m_num1.toDouble()-m_label->text().toDouble();
    else{return;});
    connect(m_buttons.at(3), SIGNAL(clicked()), [=](){m_label->setText("0");});
    connect(m_buttons.at(4), SIGNAL(clicked()), SLOT(setNum()));
    connect(m_buttons.at(5), SIGNAL(clicked()), SLOT(setNum()));
    connect(m_buttons.at(6), SIGNAL(clicked()), SLOT(setNum()));
    connect(m_buttons.at(7), SIGNAL(clicked()), SLOT(setNum()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setNum(){
    QPushButton *button = dynamic_cast <QPushButton*>(sender());
    QString bStr;
    if(button!= nullptr)bStr = button->text();
    if(m_label!=nullptr){
        QString IStr = m_label->text();
        m_label->setText((IStr=="0"|m_isFirst)?bStr:IStr+bStr);
        m_isFirst = false;
    }

//     if(button != nullptr) bStr = button->text();
//     if(m_label!=nullptr){
//         QString IStr = m_label->text();
//     #if 1
//             m_label->setText(IStr == "0"|m_isFirst)?bStr:IStr+bStr);
//     #else
// m_label->setText(QString:number(IStr.toDouble()*10 + bStr.toDouble()));
// #endif
//             m_isFirst = false;}


}

void Widget::setOp(){
    QPushButton *button = dynamic_cast<QPushButton*>(sender());
    if(button!=nullptr) m_op = button->text();
    if(m_label!=nullptr){
        m_num1 = m_label->text();
        m_isFirst = true;
    }
}
