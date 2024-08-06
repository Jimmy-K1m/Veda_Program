#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QLabel* label = new QLabel("0", this);
    resize(140,110);
    buttonGroup = new QButtonGroup(this);
    buttonGroup->setExclusive(false);
    //connect(buttonGroup, SIGNAL(idClicked(int)), SLOT(selectButton(int)));
    connect(buttonGroup, &QButtonGroup::idClicked, [=](int id)mutable{label->setText(QString::number(id+1));});// mutable은 안에서 값을 변경할 수 있게 해줌.
    // mutable로 지정된 변수는 const함수에서 값 변경 가능함.
    for(int i = 0 ; i < 4; i++)
    {
        QString str = QString("CheckBox%1").arg(i+1);
        checkBox[i] = new QCheckBox(str,this);
        checkBox[i]->move(10,10+20*i);
        buttonGroup->addButton(checkBox[i],i);
    }
}

void Widget::selectButton(int id){
    QButtonGroup* buttonGroup = (QButtonGroup*) sender();
    QCheckBox*button = (QCheckBox*)buttonGroup->button(id);
    qDebug("CheckBox%d is selected(%s)", id+1, (button->isChecked())? "On":"Off");
}

Widget::~Widget()
{

}
