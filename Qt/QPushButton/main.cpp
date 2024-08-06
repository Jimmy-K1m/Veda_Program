#include "widget.h"

#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPushButton *pushButton = new QPushButton("Push&Button", 0);
    pushButton->setShortcut(QKeySequence("ctrl+c")); // 단축키 설정
    QIcon rsrc = QIcon(":/resource/cat.png");
    pushButton->setIconSize(QSize(200,200));
    pushButton->setIcon(rsrc);

    pushButton->setCheckable(true); // 토글키로 설정
    QObject::connect(pushButton, &QPushButton::toggled, [&](bool flag){qDebug() << "toggled"; if(!flag) a.quit();});


    pushButton->show();
    // Widget w;
    // w.show();
    return a.exec();
}
