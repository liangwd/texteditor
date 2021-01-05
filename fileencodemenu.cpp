#include "fileencodemenu.h"
#include "ui_fileencodemenu.h"
#include <QHBoxLayout>
#include <QSettings>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QTextCodec>
#include <QFile>
#include <QTextStream>
#include <QPushButton>
#include <QCursor>

QMap<QString,QStringList> FileEncodeMenu::m_groupEncodeMap;

FileEncodeMenu::FileEncodeMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileEncodeMenu)
{
     ui->setupUi(this);
    //this->setWindowFlag(Qt::FramelessWindowHint);
     //this->setStyleSheet(QString("QWidget{background:transparent;border:0px solid red;}"));
       //this->setWindowOpacity(1.0);
     initFileEncodes();

     if(nullptr == m_pBtn)
     {
         QHBoxLayout *pLayout = new QHBoxLayout;
         m_pBtn = new QPushButton(QStringLiteral("编码格式"),this);
         m_pBtn->setFixedSize(100,25);
         //m_pBtn->setFlat(true);
         pLayout->addWidget(m_pBtn);
         pLayout->setContentsMargins(0,0,0,0);
         this->setLayout(pLayout);


         connect(m_pBtn,&QPushButton::clicked,this,[this](){
            if(m_pMenu){
              QAction* act =  m_pMenu->exec(QCursor::pos());
              if(act){
                  qDebug()<<act->text();
                  emit sigChangeFileEncode(act->text());
              }
            }
         });
     }


   this->setFixedSize(100,25);
}

FileEncodeMenu::~FileEncodeMenu()
{
    delete ui;
    m_pMenu->deleteLater();
}

void FileEncodeMenu::OnSetEncodeName(QString name)
{
    m_pBtn->setText(name);
}

void FileEncodeMenu::initFileEncodes()
{
    if(nullptr == m_pMenu){
        m_pMenu = new QMenu();
         m_pMenu->clear();
    }

    if(m_groupEncodeMap.isEmpty()){
        QFile file(":/file/encodes.ini");
        QString data;
        if(file.open(QIODevice::ReadOnly))
        {
           data = QString::fromUtf8(file.readAll());
           file.close();
        }

        QTextStream readStream(&data,QIODevice::ReadOnly);
        while (!readStream.atEnd()) {
            QString group = readStream.readLine();
            QString key = group.mid(1,group.length()-2);
            QString encodes = readStream.readLine();
            QString value = encodes.mid(8,encodes.length()-2);
            m_groupEncodeMap.insert(key,value.split(","));

            QStringList list = value.split(",");
            QMenu* groupMenu = new QMenu(key);
             foreach(QString var,list)
             {
                groupMenu->addAction(var);
             }

            m_pMenu->addMenu(groupMenu);
        }
    }else {
        QMap<QString,QStringList>::iterator it = m_groupEncodeMap.begin();
        for (;it != m_groupEncodeMap.end();it++) {
            QMenu* groupMenu = new QMenu(it.key());
             foreach(QString var,it.value())
             {
                groupMenu->addAction(var);
             }

            m_pMenu->addMenu(groupMenu);
        }
    }

}
