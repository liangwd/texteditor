#include "qsyntaxhighligtherex.h"
#include <QDebug>
#include <QRegularExpression>
#include <QTextDocument>

QSyntaxHighligtherEx::QSyntaxHighligtherEx(QObject *parent):
    QSyntaxHighlighter (parent)
{
    HighlightingRule rule;

      keywordFormat.setForeground(Qt::darkBlue);//设定关键词的高亮样式
      keywordFormat.setFontWeight(QFont::Bold);
      QStringList keywordPatterns; //关键词集合,关键都以正则表达式表示 下面的可以改为我们想要的关键词
      keywordPatterns << "\\bchar\\b" << "\\bclass\\b" << "\\bconst\\b"
                      << "\\bdouble\\b" << "\\benum\\b" << "\\bexplicit\\b"
                      << "\\bfriend\\b" << "\\binline\\b" << "\\bint\\b"
                      << "\\blong\\b" << "\\bnamespace\\b" << "\\boperator\\b"
                      << "\\bprivate\\b" << "\\bprotected\\b" << "\\bpublic\\b"
                      << "\\bshort\\b" << "\\bsignals\\b" << "\\bsigned\\b"
                      << "\\bslots\\b" << "\\bstatic\\b" << "\\bstruct\\b"
                      << "\\btemplate\\b" << "\\btypedef\\b" << "\\btypename\\b"
                      << "\\bunion\\b" << "\\bunsigned\\b" << "\\bvirtual\\b"
                      << "\\bvoid\\b" << "\\bvolatile\\b" << "\\bbool\\b";
      foreach (const QString &pattern, keywordPatterns) {
          rule.pattern = QRegularExpression(pattern);
          rule.format = keywordFormat;
          highlightingRules.append(rule);
 //! [1]
      }

      //! [2]
          classFormat.setFontWeight(QFont::Bold);//添加Qt的类到高亮规则中
          classFormat.setForeground(Qt::darkMagenta);
          rule.pattern = QRegularExpression("\\bQ[A-Za-z]+\\b");
          rule.format = classFormat;
          highlightingRules.append(rule);
      //! [2]

      //! [3]
          singleLineCommentFormat.setForeground(Qt::red);//单行注释
          rule.pattern = QRegularExpression("//[^\n]*");
          rule.format = singleLineCommentFormat;
          highlightingRules.append(rule);

          multiLineCommentFormat.setForeground(Qt::red);//多行注释，只设定了样式，具体匹配在highlightBlock中设置

      //! [4]
          quotationFormat.setForeground(Qt::darkGreen);//字符串
          rule.pattern = QRegularExpression("\".*\"");
          rule.format = quotationFormat;
          highlightingRules.append(rule);

       //! [5]
          functionFormat.setFontItalic(true);//函数
          functionFormat.setForeground(Qt::blue);
          rule.pattern = QRegularExpression("\\b[A-Za-z0-9_]+(?=\\()");
          rule.format = functionFormat;
          highlightingRules.append(rule);

      //! [6]
          commentStartExpression = QRegularExpression("/\\*");//多行注释的匹配正则表达式
          commentEndExpression = QRegularExpression("\\*/");
}

QSyntaxHighligtherEx::QSyntaxHighligtherEx(QTextDocument *parent):
     QSyntaxHighlighter (parent)
{

      HighlightingRule rule;

      keywordFormat.setForeground(Qt::darkBlue);//设定关键词的高亮样式
      keywordFormat.setFontWeight(QFont::Bold);
      QStringList keywordPatterns; //关键词集合,关键都以正则表达式表示 下面的可以改为我们想要的关键词
      keywordPatterns << "\\bchar\\b" << "\\bclass\\b" << "\\bconst\\b"
                      << "\\bdouble\\b" << "\\benum\\b" << "\\bexplicit\\b"
                      << "\\bfriend\\b" << "\\binline\\b" << "\\bint\\b"
                      << "\\blong\\b" << "\\bnamespace\\b" << "\\boperator\\b"
                      << "\\bprivate\\b" << "\\bprotected\\b" << "\\bpublic\\b"
                      << "\\bshort\\b" << "\\bsignals\\b" << "\\bsigned\\b"
                      << "\\bslots\\b" << "\\bstatic\\b" << "\\bstruct\\b"
                      << "\\btemplate\\b" << "\\btypedef\\b" << "\\btypename\\b"
                      << "\\bunion\\b" << "\\bunsigned\\b" << "\\bvirtual\\b"
                      << "\\bvoid\\b" << "\\bvolatile\\b" << "\\bbool\\b";
      foreach (const QString &pattern, keywordPatterns) {
          rule.pattern = QRegularExpression(pattern);
          rule.format = keywordFormat;
          highlightingRules.append(rule);
 //! [1]
      }

      //! [2]
          classFormat.setFontWeight(QFont::Bold);//添加Qt的类到高亮规则中
          classFormat.setForeground(Qt::darkMagenta);
          rule.pattern = QRegularExpression("\\bQ[A-Za-z]+\\b");
          rule.format = classFormat;
          highlightingRules.append(rule);
      //! [2]

      //! [3]
          singleLineCommentFormat.setForeground(Qt::red);//单行注释
          rule.pattern = QRegularExpression("//[^\n]*");
          rule.format = singleLineCommentFormat;
          highlightingRules.append(rule);

          multiLineCommentFormat.setForeground(Qt::red);//多行注释，只设定了样式，具体匹配在highlightBlock中设置

      //! [4]
          quotationFormat.setForeground(Qt::darkGreen);//字符串
          rule.pattern = QRegularExpression("\".*\"");
          rule.format = quotationFormat;
          highlightingRules.append(rule);

       //! [5]
          functionFormat.setFontItalic(true);//函数
          functionFormat.setForeground(Qt::blue);
          rule.pattern = QRegularExpression("\\b[A-Za-z0-9_]+(?=\\()");
          rule.format = functionFormat;
          highlightingRules.append(rule);

      //! [6]
          commentStartExpression = QRegularExpression("/\\*");//多行注释的匹配正则表达式
          commentEndExpression = QRegularExpression("\\*/");


}

void QSyntaxHighligtherEx::setEnableHighlight(bool ok)
{
    m_bHighlight = ok;
}


void QSyntaxHighligtherEx::highlightBlock(const QString &text)
{
    if(!m_bHighlight) return;
  //
    if(currentBlockState() == 0) return;
    qDebug()<<"highlightBlock"<<text<<currentBlock().lineCount()<<currentBlockState();
    foreach (const HighlightingRule &rule, highlightingRules) {//文本采用高亮规则
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
    //以下是多行注释的匹配
//! [8]
    setCurrentBlockState(0);
//! [9]
    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(commentStartExpression);

//! [9] //! [10]
    while (startIndex >= 0) {
//! [10] //! [11]
        QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
        int endIndex = match.capturedStart();
        int commentLength = 0;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + match.capturedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
    }

}
