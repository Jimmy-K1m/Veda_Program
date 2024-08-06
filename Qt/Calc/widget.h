#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVector>



class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public:
    QLabel* m_label;
    QVector<QPushButton*> m_buttons;
    QString m_num1, m_op;
    bool m_isFirst;

public slots:
    void setNum();
    void setOp();



};
#endif // WIDGET_H
