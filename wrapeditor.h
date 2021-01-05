#ifndef WRAPEDITOR_H
#define WRAPEDITOR_H

#include <QWidget>
#include "texteditex.h"
#include "fileencodemenu.h"

class WrapEditor : public QWidget
{
    Q_OBJECT
public:
    explicit WrapEditor(QWidget *parent = nullptr);
    explicit WrapEditor(QString filename,QWidget *parent = nullptr);
signals:
    void sigOpenFileName(QString filename);
public slots:
    void OnSetFileName(QString filename);
private:
    TextEditEx* m_pTextEdit= nullptr;
    FileEncodeMenu* m_pEncodeMenu =nullptr;
};

#endif // WRAPEDITOR_H
