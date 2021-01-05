#include "wrapeditor.h"
#include <QVBoxLayout>

WrapEditor::WrapEditor( QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *pV = new QVBoxLayout;
    m_pTextEdit = new TextEditEx(this);
    m_pEncodeMenu = new FileEncodeMenu(this);
    pV->setContentsMargins(0,0,0,0);
    pV->addWidget(m_pTextEdit);
    pV->addWidget(m_pEncodeMenu);
    setLayout(pV);

    connect(m_pTextEdit,&TextEditEx::sigChangeFileEncode,m_pEncodeMenu,&FileEncodeMenu::OnSetEncodeName);
    connect(m_pEncodeMenu,&FileEncodeMenu::sigChangeFileEncode,m_pTextEdit,&TextEditEx::OnChangeEncode);
    connect(m_pEncodeMenu,&FileEncodeMenu::sigChangeFileEncode,m_pEncodeMenu,&FileEncodeMenu::OnSetEncodeName);
    connect(this,&WrapEditor::sigOpenFileName,this,&WrapEditor::OnSetFileName);
}

WrapEditor::WrapEditor(QString filename, QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *pV = new QVBoxLayout;
    m_pTextEdit = new TextEditEx(this);
    m_pEncodeMenu = new FileEncodeMenu(this);
    pV->setContentsMargins(0,0,0,0);
    pV->addWidget(m_pTextEdit);
    pV->addWidget(m_pEncodeMenu);
    setLayout(pV);

    connect(m_pTextEdit,&TextEditEx::sigChangeFileEncode,m_pEncodeMenu,&FileEncodeMenu::OnSetEncodeName);
    connect(m_pEncodeMenu,&FileEncodeMenu::sigChangeFileEncode,m_pTextEdit,&TextEditEx::OnChangeEncode);
    connect(m_pEncodeMenu,&FileEncodeMenu::sigChangeFileEncode,m_pEncodeMenu,&FileEncodeMenu::OnSetEncodeName);
    connect(this,&WrapEditor::sigOpenFileName,this,&WrapEditor::OnSetFileName);

    //emit sigOpenFileName(filename);
    //m_pTextEdit->OnSetFileName(filename);
}

void WrapEditor::OnSetFileName(QString filename)
{
    m_pTextEdit->OnSetFileName(filename);
}
