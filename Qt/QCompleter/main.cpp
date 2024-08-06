#include "widget.h"

#include <QApplication>
#include <QLineEdit>
#include <QCompleter>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QLineEdit *lineEdit = new QLineEdit();
    QStringList CompletionList;

    CompletionList << "Bryan" << "Bart" << "Kelvin" << "Beth" << "Brad" << "Kelly";
    QCompleter *stringCompleter = new QCompleter(CompletionList,lineEdit);
    stringCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    //lineEdit->setEchoMode(QLineEdit::Password);
    lineEdit->setCompleter(stringCompleter);
    lineEdit->show();


    return a.exec();
}
