#ifndef QSYNTAXHIGHLIGTHEREX_H
#define QSYNTAXHIGHLIGTHEREX_H

#include <QSyntaxHighlighter>
#include <QRegularExpression>

class QSyntaxHighligtherEx : public QSyntaxHighlighter
{
public:
    explicit QSyntaxHighligtherEx(QObject *parent);
    explicit QSyntaxHighligtherEx(QTextDocument *parent);
    void setEnableHighlight(bool ok = true);
protected:
    virtual void highlightBlock(const QString &text);
private:
    struct HighlightingRule//语法规则结构体，包含正则表达式模式串和匹配的样式
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;//规则的集合，可以定义多个高亮规则

    QRegularExpression commentStartExpression; //注释的高亮，使用highliangBlock()匹配，下文提到
    QRegularExpression commentEndExpression;

    QTextCharFormat keywordFormat;//高亮样式，关键词，一下顾名思义
    QTextCharFormat classFormat;//类
    QTextCharFormat singleLineCommentFormat;//单行注释
    QTextCharFormat multiLineCommentFormat;//多行注释
    QTextCharFormat quotationFormat;//括弧
    QTextCharFormat functionFormat;//函数

    bool m_bHighlight = false;

};

#endif // QSYNTAXHIGHLIGTHEREX_H
