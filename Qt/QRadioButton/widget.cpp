#include "widget.h"
#include "./ui_widget.h"

#include <QRadioButton>
#include <QButtonGroup>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QRadioButton *radioButton[4];
    QButtonGroup *buttonGroup;
    resize(140,110);
    buttonGroup = new QButtonGroup(this);

    for(int i = 0 ; i <4;i++)
    {
        QString str = QString("RadioButton%1").arg(i+1);
        radioButton[i] = new QRadioButton(str,this);
        radioButton[i]->move(10, 10+20*i);
        buttonGroup->addButton(radioButton[i]);
    }

    connect(buttonGroup, &QButtonGroup::buttonClicked,[=](){
        // QButtonGroup* temp = (QButtonGroup*) sender();
        // QRadioButton* temp2 = (QRadioButton*) temp;
        for(int i = 0; i<4; i++)
        {
            if(radioButton[i]->isChecked())
                qDebug() << "===" << radioButton[i]->text();
                 //qDebug() << i << "'s button clicked ";
        }

        //qDebug() <<"---- button clicked ";//<< temp2->text();
    });
}

Widget::~Widget()
{
}
