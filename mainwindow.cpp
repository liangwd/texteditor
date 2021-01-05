#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextDocument>
#include <QDebug>
#include <QTextCodec>
#include <QKeyEvent>
#include <qsyntaxhighligtherex.h>
#include <QTextOption>
#include <QFileDialog>
#include <QDebug>
#include <QDateTime>
#include <QPainter>
#include <QStatusBar>
#include "third/detectcode.h"
#include "wrapeditor.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->deleteLater();
    initActions();
    //QSyntaxHighligtherEx* syntaxHighliter = new QSyntaxHighligtherEx(ui->textEdit->document())
    //QTextCodec* codec =QTextCodec::codecForName("UTF-8");
    //QTextCodec::setCodecForLocale(codec);
//    ui->checkBox->setCheckable(true);
//    connect(ui->checkBox,&QCheckBox::toggled,ui->textEdit,&TextEditEx::OnShowBlankChar);
//    m_pEncodeMenu = new FileEncodeMenu(this);

//    connect(m_pEncodeMenu,&FileEncodeMenu::sigChangeFileEncode,m_pEncodeMenu,&FileEncodeMenu::OnSetEncodeName);
//    connect(ui->textEdit,&TextEditEx::sigChangeFileEncode,m_pEncodeMenu,&FileEncodeMenu::OnSetEncodeName);

//    connect(m_pEncodeMenu,&FileEncodeMenu::sigChangeFileEncode,ui->textEdit,&TextEditEx::OnChangeEncode);

 //   ui->statusBar->addWidget(m_pEncodeMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
    m_pEncodeMenu->deleteLater();
}


void MainWindow::initActions()
{
    QAction* openFileAct = new QAction(QObject::tr("打开文件"));

    openFileAct->setChecked(true);
    connect(openFileAct,&QAction::triggered,this,[this](){
        QString fileName = QFileDialog::getOpenFileName(this,QString("Open File"),m_sCurDir);
        if(fileName.isEmpty()) return;
        m_sCurDir = QFileInfo(fileName).absolutePath();
        WrapEditor* pWrapEditor = new WrapEditor(fileName);
        ui->tabWidget->addTab(pWrapEditor,QFileInfo(fileName).fileName());
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
        pWrapEditor->OnSetFileName(fileName);
    });

    QMenu *fileMenu = new QMenu(QObject::tr("文件"));
    fileMenu->addAction(openFileAct);
    ui->menuBar->addMenu(fileMenu);
    ui->mainToolBar->addAction(openFileAct);
}

