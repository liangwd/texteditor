#ifndef TEXTEDITEX_H
#define TEXTEDITEX_H

#include <QObject>
#include <QPlainTextEdit>
#include "qsyntaxhighligtherex.h"


class QInputMethodEvent;
class QUndoStack;
class QKeyEvent;
class QMouseEvent;
class QPaintEvent;


class TextEditEx : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit TextEditEx(QWidget *parent = nullptr);
    ~TextEditEx();
public slots:
    //显示空白符
    void OnShowBlankChar(bool ok);
    //设置文本内容
    void OnSetFileName(QString filename);
    //改变文本编码
    void OnChangeEncode(QString encode);
private slots:
    void OnSetPlainText(QByteArray& content);
    void OnScrollBarChanged(int value);
signals:
    void sigChangeFileEncode(QString encode);
protected:
    void paintEvent(QPaintEvent*e);
    void inputMethodEvent(QInputMethodEvent *e);
    void keyPressEvent(QKeyEvent* e);
    void mousePressEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
private:
    QRect m_cursorRect;
    //自定义撤销重做栈
    QUndoStack* m_pUndoStack = nullptr;
    QString m_sTextEncode;
    int m_iPos = -1;
   // bool m_bAltPressed = false;
    bool m_bColumnEdit = false;
    QPoint m_BeginColumnEditPos;//列编辑开始位置
    QPoint m_EndColumnEditPos;//列编辑结束位置
    QList<QTextEdit::ExtraSelection> m_ColumnEditSelectons;
    const QString SELECT_HIGHLIGHT_COLOR = "#2CA7F8";
    QString m_sFileName;
    QSyntaxHighligtherEx* m_pSyntaxHighligtherEx =nullptr;
};

#endif // TEXTEDITEX_H
