#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QButtonGroup>
#include <QCheckBox>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE
class QCheckBox;
class QButtonGroup;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QCheckBox *checkBox[4];
    QButtonGroup *buttonGroup;

public slots:
    void selectButton(int id);
};
#endif // WIDGET_H


