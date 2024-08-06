#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#include <QPushButton>
#include <QString>
#include <string>
class PushButton : public QPushButton
{
    Q_OBJECT
public:
    PushButton();
    PushButton(QString a );

// signals:
//     void clicked();
public slots:
    QString slotValue();
};


/*
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QLabel *m_label;
public slots:
    void slotLabel();
};

*/
#endif // PUSHBUTTON_H
