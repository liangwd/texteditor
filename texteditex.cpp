#include "texteditex.h"
#include <QPainter>
#include <QDebug>
#include <QVariant>
#include <QApplication>
#include <QClipboard>
#include <QMimeData>
#include <QPaintEvent>
#include <QInputMethodEvent>
#include <QUndoStack>
#include <QTextBlock>
#include <QTextCursor>
#include <QTextDocument>
#include <QSaveFile>
#include <QScrollBar>
#include "third/detectcode.h"
#include "inserttextundocommand.h"
#include "deletetextundocommand.h"
#include "qsyntaxhighligtherex.h"


TextEditEx::TextEditEx(QWidget *parent):    QPlainTextEdit(parent)
{
    //自定义撤销重做栈
    document()->setUndoRedoEnabled(false);
    m_pUndoStack = new QUndoStack(this);

    //占位符
    setPlaceholderText("欢迎使用编辑器");
    m_pSyntaxHighligtherEx = new QSyntaxHighligtherEx(document());
    QScrollBar* pVerScrollBar = this->verticalScrollBar();
    connect(pVerScrollBar,&QScrollBar::valueChanged,this,&TextEditEx::OnScrollBarChanged);
}

TextEditEx::~TextEditEx()
{

}

void TextEditEx::OnScrollBarChanged(int value)
{
    QTextCursor textCursor = this->textCursor();
    QTextBlock block = document()->findBlockByLineNumber(value);
    qDebug()<<"OnScrollBarChanged :"<<value<<block.text();
    m_pSyntaxHighligtherEx->rehighlightBlock(block);
}

void TextEditEx::OnShowBlankChar(bool ok)
{
    if(ok){
          QTextOption opts = document()->defaultTextOption();
          QTextOption::Flags flag = opts.flags();
          flag |= QTextOption::ShowTabsAndSpaces;
          //flag |= QTextOption::ShowLineAndParagraphSeparators;
          //flag |= QTextOption::AddSpaceForLineAndParagraphSeparators;
          opts.setFlags(flag);
          document()->setDefaultTextOption(opts);
      }else {
          QTextOption opts = document()->defaultTextOption();
          QTextOption::Flags flag = opts.flags();
          flag &= ~QTextOption::ShowTabsAndSpaces;
          //flag &= ~QTextOption::ShowLineAndParagraphSeparators;
          //flag &= ~QTextOption::AddSpaceForLineAndParagraphSeparators;
          opts.setFlags(flag);
          document()->setDefaultTextOption(opts);
    }
}

void TextEditEx::OnSetPlainText(QByteArray& content)
{
    this->clear();
    int total = content.length();
    int step = 1*1024*1024;
    int mod = total%step;
    int cnt = total/step;

    QTextCursor cursor = textCursor();
    //QTextDocument *doc = document();

    if(total > 50*1024*1024){
        for (int i = 0;  i< cnt; i++) {
           m_iPos = i*step;
           QString data = content.mid(m_iPos,step);
          // m_textContent.remove(i*step,step);
           cursor.insertText(data);
           QApplication::processEvents();
           if(i == cnt -1 && mod > 0){
               m_iPos = cnt*step;
               QString data = content.mid(m_iPos,mod);
               //m_textContent.remove(i*step,step);
               cursor.insertText(data);
               QApplication::processEvents();
           }
        }
    }else {
        cursor.insertText(content);
        QApplication::processEvents();
    }
}

void TextEditEx::OnSetFileName(QString filename)
{
    m_sFileName = filename;

    m_sTextEncode  = QString::fromLocal8Bit(DetectCode::GetFileEncodingFormat(m_sFileName));

    sigChangeFileEncode(m_sTextEncode);

    QFile file(m_sFileName);

    QApplication::setOverrideCursor(Qt::WaitCursor);

    if(file.open(QFile::OpenModeFlag::ReadOnly))
    {
      QByteArray Indata = file.readAll();
      file.close();

      if(m_sTextEncode.contains("ASCII",Qt::CaseInsensitive) || m_sTextEncode.contains("UTF-8",Qt::CaseInsensitive)){
          OnSetPlainText(Indata);
      }else {
          QByteArray OutData;
          DetectCode::ChangeFileEncodingFormat(Indata,OutData,m_sTextEncode,QString("UTF-8"));
          OnSetPlainText(OutData);
      }
    }
    m_pSyntaxHighligtherEx->setEnableHighlight(true);
    QApplication::restoreOverrideCursor();
}

void TextEditEx::OnChangeEncode(QString encode)
{
        m_sTextEncode = encode;
        QFile file(m_sFileName);
        if(file.open(QIODevice::ReadOnly))
        {
          QByteArray Indata = file.readAll();
          file.close();
          QByteArray OutData;
          DetectCode::ChangeFileEncodingFormat(Indata,OutData,m_sTextEncode,QString("UTF-8"));
          OnSetPlainText(OutData);
        }
}




//支持输入法文本撤销重做
void TextEditEx::inputMethodEvent(QInputMethodEvent *e)
{
    qDebug()<<e;
    if(!e->commitString().isEmpty()) {
       //列编辑添加撤销重做
       if(m_bColumnEdit && !m_ColumnEditSelectons.isEmpty()){
           QUndoCommand * pInsertStack= new InsertTextUndoCommand(m_ColumnEditSelectons,e->commitString());
           m_pUndoStack->push(pInsertStack);
       }else {
           QUndoCommand * pInsertStack= new InsertTextUndoCommand(textCursor(),e->commitString());
           m_pUndoStack->push(pInsertStack);
       }
    }
}

void TextEditEx::keyPressEvent(QKeyEvent *e)
{
    Qt::KeyboardModifiers modifiers = e->modifiers();

    //重做 ctrl+shift+z
    if(modifiers == (Qt::ControlModifier | Qt::ShiftModifier) && e->key() == Qt::Key_Z){
      m_pUndoStack->redo();
      return;
    //撤销 ctrl+z
    }else if(modifiers == Qt::ControlModifier && e->key() == Qt::Key_Z){
      m_pUndoStack->undo();
      return;
    //键盘可以输入ascii码
    }else if(modifiers == Qt::ControlModifier && e->key() == Qt::Key_V){
       //添加剪切板内容到撤销重做栈
        const QClipboard *clipboard = QApplication::clipboard(); //获取剪切版内容
      qDebug()<<"MimeData Formats:"<<clipboard->mimeData()->formats()<<clipboard->mimeData()->colorData();
      if(!clipboard->text().isEmpty()){

        //列编辑添加撤销重做
        if(m_bColumnEdit && !m_ColumnEditSelectons.isEmpty()){
            QUndoCommand * pInsertStack= new InsertTextUndoCommand(m_ColumnEditSelectons,clipboard->text());
            m_pUndoStack->push(pInsertStack);
        }else {
            QUndoCommand * pInsertStack= new InsertTextUndoCommand(textCursor(),clipboard->text());
            m_pUndoStack->push(pInsertStack);
        }
      }
     //tab return键添加撤销重做栈
    }else if (modifiers == Qt::NoModifier && (e->key() == Qt::Key_Tab || e->key() == Qt::Key_Return)) {
        //列编辑添加撤销重做
        if(m_bColumnEdit && !m_ColumnEditSelectons.isEmpty()){
            QUndoCommand * pInsertStack= new InsertTextUndoCommand(m_ColumnEditSelectons,e->text());
            m_pUndoStack->push(pInsertStack);
        }else {
            QUndoCommand * pInsertStack= new InsertTextUndoCommand(textCursor(),e->text());
            m_pUndoStack->push(pInsertStack);
        }
    }else if((modifiers == Qt::NoModifier || modifiers == Qt::ShiftModifier) && (e->key()<=Qt::Key_ydiaeresis && e->key() >= Qt::Key_Space) && !e->text().isEmpty()){
        //列编辑添加撤销重做
        if(m_bColumnEdit && !m_ColumnEditSelectons.isEmpty()){
            QUndoCommand * pInsertStack= new InsertTextUndoCommand(m_ColumnEditSelectons,e->text());
            m_pUndoStack->push(pInsertStack);
        }else {
            QUndoCommand * pInsertStack= new InsertTextUndoCommand(textCursor(),e->text());
            m_pUndoStack->push(pInsertStack);
        }

    }else if(e->key() == Qt::Key_Backspace){
        //删除撤销重做
        //列编辑
       if(m_bColumnEdit && !m_ColumnEditSelectons.isEmpty()){
            QUndoCommand * pDeleteStack= new DeleteTextUndoCommand(m_ColumnEditSelectons);
            m_pUndoStack->push(pDeleteStack);
        }else {
            QUndoCommand * pDeleteStack= new DeleteTextUndoCommand(textCursor());
            m_pUndoStack->push(pDeleteStack);
        }
    }else{
      qDebug()<<modifiers<<e->key()<<e->text();
      QPlainTextEdit::keyPressEvent(e);
    }
}

void TextEditEx::paintEvent(QPaintEvent *paintEvent)
{
    QPlainTextEdit::paintEvent(paintEvent);

    if (m_bColumnEdit && !m_ColumnEditSelectons.isEmpty()) {
        QColor lineColor = palette().text().color();
        QColor backgrColor = palette().background().color();
        int cursorWidth = this->cursorWidth();

        QPainter painter(viewport());
        QPen pen;
        pen.setColor(lineColor);
        pen.setWidth(cursorWidth);
        painter.setPen(pen);

        QList<int> rowList;
        for (int i = 0 ; i < m_ColumnEditSelectons.size();i++) {
          QRect textCursorRect = cursorRect(m_ColumnEditSelectons[i].cursor);
          painter.drawRect(textCursorRect);
        }
    }
}

void TextEditEx::mousePressEvent(QMouseEvent *e)
{
    if(e->modifiers() == Qt::AltModifier){
        m_bColumnEdit = true;
        m_BeginColumnEditPos = e->pos();
        m_ColumnEditSelectons.clear();
    }else {
        m_bColumnEdit = false;
        m_ColumnEditSelectons.clear();
        setExtraSelections(m_ColumnEditSelectons);
        QPlainTextEdit::mousePressEvent(e);
    }

    //QTextCursor textcursor= cursorForPosition(e->pos());
}

void TextEditEx::mouseMoveEvent(QMouseEvent *e)
{
    if(e->modifiers() == Qt::AltModifier && m_bColumnEdit)
    {
        m_EndColumnEditPos = e->pos();
        m_ColumnEditSelectons.clear();
        QTextCursor beginCursor = cursorForPosition(m_BeginColumnEditPos);
        QTextCursor endCursor= cursorForPosition(m_EndColumnEditPos);

        QTextCharFormat format;
        QPalette palette;
        format.setBackground(QColor(SELECT_HIGHLIGHT_COLOR));
        format.setForeground(palette.highlightedText());

        int beginRow = beginCursor.blockNumber();
        int beginColumn = beginCursor.columnNumber();
        int endRow = endCursor.blockNumber();
        int endColumn = endCursor.columnNumber();

        for (int row = beginRow; (beginRow < endRow ?  row <= endRow : row >= endRow); (beginRow < endRow ? row++:row--)) {
           // for (int col = beginColumn;(beginColumn < endColumn ? col < endColumn : col>= endColumn);(beginColumn < endColumn ? col++ : col--)) {
                QTextEdit::ExtraSelection selection;
                 selection.format = format;
                 selection.cursor = textCursor();
                 selection.cursor.clearSelection();
                 QTextBlock block =document()->findBlockByNumber(row);
                 selection.cursor.setPosition(block.position()+ beginColumn,QTextCursor::MoveAnchor);

                 //位置从0开始
                 int length = block.text().length();

                 if(beginColumn < endColumn){

                     //鼠标x坐标大于当前块最后字符位置　遍历获取最大块长度
                    if(length > endColumn) {
                          int moveLen = endColumn - beginColumn;
                         selection.cursor.movePosition(QTextCursor::Right,QTextCursor::KeepAnchor,moveLen);
                         setTextCursor(selection.cursor);
                         m_ColumnEditSelectons.append(selection);
                     }else if(length >= beginColumn) {
                         int moveLen = length - beginColumn;
                         selection.cursor.movePosition(QTextCursor::Right,QTextCursor::KeepAnchor,moveLen);
                         setTextCursor(selection.cursor);
                         m_ColumnEditSelectons.append(selection);
                     }

                 }else {

                     //鼠标x坐标大于当前块最后字符位置　遍历获取最大块长度
                    if(length > beginColumn) {
                        int moveLen = beginColumn - endColumn;
                        selection.cursor.movePosition(QTextCursor::Left,QTextCursor::KeepAnchor,moveLen);
                        setTextCursor(selection.cursor);
                        m_ColumnEditSelectons.append(selection);
                     }else if(length <= beginColumn && length >= endColumn) {
                         int moveLen = length - endColumn;
                         selection.cursor.movePosition(QTextCursor::Left,QTextCursor::KeepAnchor,moveLen);
                         setTextCursor(selection.cursor);
                         m_ColumnEditSelectons.append(selection);
                     }

                 }
           // }
        }

        setExtraSelections(m_ColumnEditSelectons);
    }else {
        //m_bColumnEdit = false;
        //m_ColumnEditSelectons.clear();
        //setExtraSelections(m_ColumnEditSelectons);
        QPlainTextEdit::mouseMoveEvent(e);
    }
}

void TextEditEx::mouseReleaseEvent(QMouseEvent *e)
{
    //m_bColumnEdit = false;
    //m_ColumnEditSelectons.clear();
    //setExtraSelections(m_ColumnEditSelectons);
    QPlainTextEdit::mouseReleaseEvent(e);
}
