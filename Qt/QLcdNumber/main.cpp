#include "mainwindow.h"
#include <QApplication>
#include <QTextBrowser>
#include <QUrl>
//#include <QLCDNumber>
// #include <QProgressBar>
// #include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextBrowser *tb = new QTextBrowser();
    //tb -> setSource(QUrl("C:\Users\DREAM05\Desktop\QLcdNumber\build\Desktop_Qt_6_5_6_MSVC2019_64bit-Debug\index.html"));
    tb -> setSource(QUrl("index.html"));
    tb->show();


    return a.exec();
}
/*    QLCDNumber *lcd = new QLCDNumber();
    lcd->setBinMode();
    lcd->setSegmentStyle(QLCDNumber::Outline);
    lcd->resize(500, 300);
    lcd -> setDigitCount(15);
    lcd->display(2024);
    lcd->show();*/

/*
    QProgressBar *progBar = new QProgressBar();

    //progBar->setRange(0,50);
    progBar->setValue(0);
    progBar->show();
    QTimer temp_clock;

    int i = 0;

    QObject::connect(&temp_clock,&QTimer::timeout, [&](){progBar->setValue(i++);});
    // 객체의 주소, 시그널 메서드, 슬롯 메서드
    temp_clock.start(500);
*/
