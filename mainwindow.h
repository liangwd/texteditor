#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QRubberBand>
#include <QTextCursor>
#include "fileencodemenu.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initActions();

private:
    Ui::MainWindow *ui;
    QRubberBand *m_pRubberBand = nullptr;
    QPoint m_originPoint;
    QTextCursor m_originTextCursor;
private:
    QRect m_cursorRect;
    QString m_sCurDir;
    FileEncodeMenu* m_pEncodeMenu = nullptr;
};

#endif // MAINWINDOW_H
