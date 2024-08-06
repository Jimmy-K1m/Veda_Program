#include "widget.h"
#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <QString>
#include "pushbutton.h"
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;

    const char ButtonChar[2][4] = {'+', '-', '=','C', '1', '2', '3','4'};



    PushButton *buttons[8];

    for(int y = 0; y < 2; y++)
    {
        for(int x = 0 ; x<4;x++)
        {
            buttons[x+y*2] = new PushButton(ButtonChar[x+y*2]);
            buttons[x+y*2]->setGeometry(5+60*x , 50+60*y, 60,60);
        }
    }


    string temp = "";
    int result;

    string stdtmp;
    while(1)
    {
        QString tmp = connect(*buttons, SIGNAL(clicked()), qApp, SLOT(slotValue()));
//str = qstr.toStdString();
        stdtmp = tmp.toStdString();
        if(stdtmp == '=')
            {break;}
        else if(stdtmp == '+')
        {result += stdtmp.toInt();}
        else if(stdtmp == '-')
        {result -= stdtmp.toInt();}
        else if(stdtmp == 'C')
        {
            result = 0;
            stdtmp ="";
        }
        else{
            temp += temp.toInt();
        }

    }

    QLabel* label = new QLabel(to_string(result));
    label->setGeometry(10,5,230,40);
    label -> setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    label->show();


    // Widget result;
    // QObject(buttons, SIGNALS(clicked()), qApp, SLOT(quit()));


    return a.exec();
}
