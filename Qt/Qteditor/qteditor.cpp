#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QAction>
#include <QApplication>
#include <QFontComboBox>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QStatusBar>
#include <QDockWidget>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QFontDialog>
#include <QInputDialog>
#include <QColorDialog>
#include <QHash>

// help 메뉴를 메뉴 바 슬롯 함수 하나 만들어서 activate될 때 about 창 연결
#include "qteditor.h"

QtEditor::QtEditor(QWidget *parent)
    : QMainWindow(parent)
{
    mdiArea = new QMdiArea(this);
    //setCentralWidget(mdiArea);
    connect(mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)),SLOT(setFontWidget()));
    setCentralWidget(mdiArea);

#if 1				// Edit 메뉴를 수정한 후 0으로 변경
    QTextEdit *textedit = new QTextEdit(this);
    //    setCentralWidget(textedit);
    mdiArea->addSubWindow(textedit);
#else
    newFile( );
#endif

    QMenuBar *menubar = new QMenuBar(this);
    setMenuBar(menubar);

    /* File Menu */
#if 0
    QAction *newAct = new QAction(QIcon("new.png"), "&New", this);
    newAct->setShortcut(tr("Ctrl+N"));
    newAct->setStatusTip(tr("make new file"));
    connect(newAct, SIGNAL(triggered( )), SLOT(newFile( )));
#else
    QAction *newAct = makeAction(":/images/new.png", "&New", "Ctrl+N", \
                                 "make new file", this, SLOT(newFile( )));
#endif
    QAction *openAct = makeAction(":/images/open.png", "&Open", "Ctrl+O", \
                                  "Open a file", this, SLOT(openFile( )));
    QAction *saveAct = makeAction(":/images/save.png", "&Save", "Ctrl+S", \
                                  "Save this file", this, SLOT(saveFile( )));
    QAction *saveAsAct = makeAction(":/images/saveas.png", "&Save &as...", "Ctrl+Shift+S", \
                                    "Save this file as a new name", this, SLOT(saveAsFile( )));
    QAction *quitAct = makeAction(":/images/qt.png", "&Quit", "Ctrl+Q", \
                                  "Quit this program", qApp, SLOT(quit( )));

    /* Edit Menu */
    QAction *undoAct = makeAction(":/images/undo.png", "&Undo", "Ctrl+Z", \
                                  "Undo", this, SLOT(undo( )));
    QAction *redoAct = makeAction(":/images/redo.png", "&Redo", "Ctrl+Shift+Z", \
                                  "Redo", this, SLOT(redo( )));
    QAction *copyAct = makeAction(":/images/copy.png", "&Copy", "Ctrl+C", \
                                  "Copy", this, SLOT(copy( )));
    QAction *cutAct = makeAction(":/images/cut.png", "C&ut", "Ctrl+X", \
                                 "Cut", this, SLOT(cut( )));
    QAction *pasteAct = makeAction(":/images/paste.png", "&Paste", "Ctrl+V", \
                                   "Paste", this, SLOT(paste( )));
    QAction *zoomInAct = makeAction(":/images/zoomIn.png", "Zoom &in", "Ctrl+=", \
                                    "Zoom In", this, SLOT(zoomIn( )));
    QAction *zoomOutAct = makeAction(":/images/zoomOut.png", "Zoon &out", "Ctrl+-", \
                                     "Zoom Out", this, SLOT(zoomOut( )));

    /* Format Menu */
    QAction *fontAct = makeAction(":/images/font.png", "&Font", "Ctrl+F", \
                                  "Font", this, SLOT(setFont( )));
    QAction *colorAct = makeAction(":/images/color.png", "C&olor", "Ctrl+G", \
                                   "Color", this, SLOT(setColor( )));
    QAction *alignLeftAct = makeAction(":/images/left.png", "&Left", "Ctrl+1", \
                                       "Left", this, SLOT(alignText( )));
    QAction *alignCenterAct = makeAction(":/images/center.png", "&Center", "Ctrl+2", \
                                         "Center", this, SLOT(alignText( )));
    QAction *alignRightAct = makeAction(":/images/right.png", "&Right", "Ctrl+3", \
                                        "Right", this, SLOT(alignText( )));
    QAction *alignJustifyAct = makeAction(":/images/justify.png", "&Justify", "Ctrl+4", \
                                          "Justify", this, SLOT(alignText( )));

    /* Window Menu */
    QAction *cascadeAct = makeAction(":/images/cascade.png", "&Cascade", "Ctrl+9", \
                                     "Cascade", mdiArea, SLOT(cascadeSubWindows( )));
    QAction *tileAct = makeAction(":/images/tile.png", "&Tile", "Ctrl+0", \
                                  "Tile", mdiArea, SLOT(tileSubWindows( )));
    QAction *prevWindowAct = makeAction(":/images/left.png", "&Left", "Ctrl+1", \
                                        "Left", mdiArea, SLOT(activatePreviousSubWindow( )));
    QAction *nextWindowAct = makeAction(":/images/center.png", "&Center", "Ctrl+2", \
                                        "Center", mdiArea, SLOT(activateNextSubWindow( )));
    QAction *helpAct = makeAction(":/images/center.png", "&Help", "Ctrl+h", \
                                  "Help", this, SLOT(Help()));

    QMenu *fileMenu = menubar->addMenu("&File");
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);
    fileMenu->addAction(helpAct);

    QMenu *editMenu = menubar->addMenu("&Edit");
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addSeparator();
    editMenu->addAction(copyAct);
    editMenu->addAction(cutAct);
    editMenu->addAction(pasteAct);
    editMenu->addSeparator();
    editMenu->addAction(zoomInAct);
    editMenu->addAction(zoomOutAct);

    QToolBar *fileToolBar = addToolBar("&File");
    //    fileToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);
    fileToolBar->addAction(saveAsAct);
    fileToolBar->addSeparator();
    fileToolBar->addSeparator();
    fileToolBar->addAction(quitAct);
    fileToolBar->addAction(helpAct);

    QToolBar *editToolBar = addToolBar("&Edit");
    //    editToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    editToolBar->addAction(undoAct);
    editToolBar->addAction(redoAct);
    editToolBar->addSeparator();
    editToolBar->addAction(copyAct);
    editToolBar->addAction(cutAct);
    editToolBar->addAction(pasteAct);
    editToolBar->addSeparator();
    editToolBar->addAction(zoomInAct);
    editToolBar->addAction(zoomOutAct);

    fontComboBox = new QFontComboBox(this);
    connect(fontComboBox, SIGNAL(currentFontChanged(QFont)),
            textedit, SLOT(setTextFont(QFont)));
    sizeSpinBox = new QDoubleSpinBox(this);
    connect(sizeSpinBox, SIGNAL(valueChanged(double)),
            textedit, SLOT(setTextSize(qreal)));

    addToolBarBreak( );      /* 다음 툴바는 아랫 줄로 위치 */

    QToolBar *formatToolbar = addToolBar("&Format");
    formatToolbar->addAction(fontAct);
    formatToolbar->addAction(colorAct);
    formatToolbar->addSeparator( );
    formatToolbar->addWidget(fontComboBox);
    formatToolbar->addWidget(sizeSpinBox);
    formatToolbar->addSeparator( );
    formatToolbar->addAction(alignLeftAct);
    formatToolbar->addAction(alignCenterAct);
    formatToolbar->addAction(alignRightAct);
    formatToolbar->addAction(alignJustifyAct);

    QMenu *formatMenu = menubar->addMenu("&Format");
    formatMenu->addAction(fontAct);
    formatMenu->addAction(colorAct);
    QMenu *alignMenu = formatMenu->addMenu("&Align");
    alignMenu->setIcon(QIcon("align.png"));
    alignMenu->addAction(alignLeftAct);
    alignMenu->addAction(alignCenterAct);
    alignMenu->addAction(alignRightAct);
    alignMenu->addAction(alignJustifyAct);

    QLabel* label = new QLabel("Dock Widget", this);
    QDockWidget *dock = new QDockWidget("Dock Widget", this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    dock->setWidget(label);

    windowMenu = menubar->addMenu("&Window");
    windowMenu->addAction(cascadeAct);
    windowMenu->addAction(tileAct);
    windowMenu->addSeparator( );
    windowMenu->addAction(prevWindowAct);
    windowMenu->addAction(nextWindowAct);
    windowMenu->addSeparator( );
    QMenu *toolbarMenu = windowMenu->addMenu("&Toolbar");
    toolbarMenu->addAction(fileToolBar->toggleViewAction( ));
    toolbarMenu->addAction(formatToolbar->toggleViewAction( ));
    toolbarMenu->addAction(editToolBar->toggleViewAction( ));
    windowMenu->addAction(dock->toggleViewAction( ));

    QStatusBar* statusbar = statusBar( );
    QLabel* statusLabel = new QLabel("Qt Editor", statusbar);
    statusLabel->setObjectName("StautsLabel");
    statusbar->addPermanentWidget(statusLabel);
    statusbar->showMessage("started", 1500);
}

QtEditor::~QtEditor()
{
}
/*
void QtEditor::newFile( )
{
    QTextEdit* textedit = new QTextEdit;
    statusBar()->showMessage("Make New File");
    QTextEdit *textedit = new QTextEdit;
    mdiArea->addSubWindow(textedit);
    textedit->show( );
    //
}
*/
QTextEdit* QtEditor::newFile( )
{
    QAction *windowAct = new QAction("New File", this);
    windowMenu->addAction(windowAct);

    QTextEdit* textedit = new QTextEdit;

    connect(textedit, SIGNAL(cursorPositionChanged()), SLOT(setFontWidget()));
    connect(windowAct, SIGNAL(triggered()), textedit, SLOT(setFocus()));
    connect(textedit, SIGNAL(destroyed(QObject*)), textedit, SLOT(deleteLater()));
    connect(textedit, SIGNAL(destroyed(QObject*)), windowAct, SLOT(deleteLater()));

    mdiArea->addSubWindow(textedit);
    textedit->show();

    windowHash[windowAct] = textedit;
    return textedit;
    //
}


void QtEditor::openFile(){
    QString filename = QFileDialog::getOpenFileName(this, "Select file to open", QDir::home().dirName(), "Text File(*.txt*.html*.c*.cpp*.h)");
    qDebug()<< filename;

    if(!filename.length()) return;

    QFileInfo fileInfo(filename);
    if(fileInfo.isReadable()){
        QFile file(filename);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QByteArray msg = file.readAll();
        file.close();

        QTextEdit*textedit = newFile();
        textedit->setWindowTitle(filename);
        windowHash.key(textedit)->setText(filename);

        if(fileInfo.suffix() == "htm" || fileInfo.suffix() == "html")
            textedit->setPlainText(msg);
        else
            textedit->setPlainText(msg);
    }
    else
        QMessageBox::warning(this, "Error", "Can't Read this file", QMessageBox::Ok);
}
void QtEditor::saveFile(){
    //QString filename = QFileDialog::getSaveFileName(this, "Select file to save",".", "Text File(*.txt*.html*.c*.cpp*.h)");
    // QTextEdit* textedit = new QTextEdit;
    // windowHash.key(textedit)->setText(filename);

    QMdiSubWindow* window = mdiArea->currentSubWindow();
    if(window!=nullptr)
    {
        QTextEdit *textedit = qobject_cast<QTextEdit*>(window->widget());
        QString filename = textedit->windowTitle();
        if(!filename.length()){
            filename = QFileDialog::getSaveFileName(this, "Select a file to save", ".", "Text File(*.txt*.html*.c*.cpp*.h)");

            if(!filename.length()) return;
            textedit->setWindowTitle(filename);
            windowHash.key(textedit)->setText(filename);
        }

        QFile file(filename);
        file.open(QIODevice::WriteOnly|QIODevice::Text);
        QFileInfo fileInfo(filename);

        if(fileInfo.isWritable()){
            QByteArray msg = textedit->toHtml().toUtf8();
            file.write(msg);
        }
        else
        {
            QMessageBox::warning(this, "Error", "Can't Save this file", QMessageBox::Ok);
            file.close();
        }
    }
}
void QtEditor::saveAsFile(){
    QString filename = QFileDialog::getOpenFileName(this, "Select file to save as", ".", "Text File(*.txt*.html*.c*.cpp*.h)");
    qDebug()<< filename;

     QMdiSubWindow* window = mdiArea->currentSubWindow();
      if(window!=nullptr)
     {
           QTextEdit *textedit = qobject_cast<QTextEdit*>(window->widget());
           QString filename = QFileDialog::getSaveFileName(this, "Select a file to save", ".", "Text File(*.txt*.html*.c*.cpp*.h)");//

           if(!filename.length()) return;
           textedit->setWindowTitle(filename);
           QFile *file = new QFile(filename);
           file->open(QIODevice::WriteOnly|QIODevice::Text);
           QFileInfo fileInfo(filename);

           if(fileInfo.isWritable()){
               QByteArray msg = textedit->toHtml().toUtf8();
               file->write(msg);
           }
           else
           {
               QMessageBox::warning(this, "Error", "Can't Save this file", QMessageBox::Ok);
               file->close();
           }
      }

}



void QtEditor::print( )
{
    statusBar()->showMessage("Print this File");
}


void QtEditor::setColor( )
{
    QTextEdit*textedit = (QTextEdit*)mdiArea -> currentSubWindow()->widget();
    QColor color = QColorDialog::getColor(textedit->textColor(), this);
    if(color.isValid())textedit->setTextColor(color);
}

QAction *QtEditor::makeAction(QString icon, QString name, \
                              QString shortCut, QString toolTip, \
                              QObject* recv, const char* slot)
{
    QAction *act = new QAction(name, this);
    if(icon.length( ))
        act->setIcon(QIcon(icon));
    act->setShortcut(shortCut);
    act->setStatusTip(toolTip);
    connect(act, SIGNAL(triggered( )), recv, slot);
    return act;
}

void QtEditor::alignText( )
{
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );
    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));
        QAction *action = static_cast<QAction*>(sender( ));
        if(action->text( ) == "&Left")
            textedit->setAlignment(Qt::AlignLeft);
        else if(action->text( ) == "&Center")
            textedit->setAlignment(Qt::AlignCenter);
        else if(action->text( ) == "&Right")
            textedit->setAlignment(Qt::AlignRight);
        else if(action->text( ).contains("Justify", Qt::CaseInsensitive))
            textedit->setAlignment(Qt::AlignJustify);
    }
}

void QtEditor::undo( )
{
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );
    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));
        textedit->undo( );
    }
}

void QtEditor::redo( )
{
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );
    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));
        textedit->redo( );
    }
}

void QtEditor::copy( )
{
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );
    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));
        textedit->copy( );
    }
}

void QtEditor::cut( )
{
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );
    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));
        textedit->cut( );
    }
}

void QtEditor::paste( )
{
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );
    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));
        textedit->paste( );
    }
}

void QtEditor::zoomIn( )
{
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );
    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));
        textedit->zoomIn( );
    }
}

void QtEditor::zoomOut( )
{
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );
    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));
        textedit->zoomOut( );
    }
}


void QtEditor::Help() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Help", "Do you need help?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        bool ok;
        QString text = QInputDialog::getText(this, "Input Dialog", "Type what you want to find", QLineEdit::Normal, "", &ok);
        if (ok && !text.isEmpty()) {
            // Process the text
        }
    }
}


void QtEditor::setTextFont(QFont font) {
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow();
    if (subWindow) {
        QTextEdit* textedit = dynamic_cast<QTextEdit*>(subWindow->widget());
        if (textedit) {
            textedit->setCurrentFont(font);
        }
    }
}

void QtEditor::setTextSize(qreal size) {
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow();
    if (subWindow) {
        QTextEdit* textedit = dynamic_cast<QTextEdit*>(subWindow->widget());
        if (textedit) {
            QFont font = textedit->currentFont();
            font.setPointSizeF(size);
            textedit->setCurrentFont(font);
        }
    }
}


void QtEditor::setFontWidget(){
    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    QFont font = textedit->currentFont();
    fontComboBox->setCurrentFont(font);
    sizeSpinBox->setValue(font.pointSizeF());
}

void QtEditor::setFont()
{
    bool ok;
    QTextEdit*textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    QFont font = QFontDialog::getFont(&ok, textedit->currentFont(),this);
    if(ok)textedit->setCurrentFont(font);
}

void QtEditor::selectWindow()
{
    QTextEdit* textedit = (QTextEdit*)windowHash[(QAction*)sender()];
    textedit->setFocus();
}



