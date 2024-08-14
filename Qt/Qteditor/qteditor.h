#ifndef QTEDITOR_H
#define QTEDITOR_H

#include <QMainWindow>

class QAction;
class QMdiArea;
class QTextEdit;
class QFontComboBox;
class QDoubleSpinBox;

class QtEditor : public QMainWindow
{
    Q_OBJECT

public:
    QtEditor(QWidget *parent = nullptr);
    ~QtEditor();

private:
    QAction *makeAction(QString icon, QString name, QString shortCut, \
                        QString toolTip, QObject* recv, const char* slot);

    QMdiArea* mdiArea;
    //    QTextEdit *textedit;
    QFontComboBox* fontComboBox;
    QDoubleSpinBox* sizeSpinBox;
    QHash<QAction*, QWidget*> windowHash;
    QMenu *windowMenu;

public slots:
    /* File Menu */
    //void newFile( );
    void openFile( );
    void saveFile( );
    void saveAsFile( );
    void print( );

    /* Edit Menu */
    void undo( );
    void redo( );
    void copy( );
    void cut( );
    void paste( );
    void zoomIn( );
    void zoomOut( );

    /* Format Menu */
    void setFont( );
    void setColor( );
    void alignText( );
    void setTextFont(QFont font);
    void setTextSize(qreal size);
    void setFontWidget();

    void Help();
    void selectWindow();

    QTextEdit* newFile();


};
#endif // QTEDITOR_H
