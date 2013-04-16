#include "textnode.h"
#include <QRegExp>
#include <QDebug>

TextNode::TextNode(QObject *parent) :
    HtmlTag("(text)", parent)
{
}

TextNode::TextNode(QByteArray text, QObject *parent) :
    TextNode(parent)
{
    setText(text);
}

void TextNode::setText(QByteArray newText) {
    
    QString processedText = QString(newText).toHtmlEscaped();
    //Replace newlines with <br />s
    static const QRegExp newlineRegex("[\n\r]+");
    processedText = processedText.replace(newlineRegex, "<br />");
    
    text = processedText.toUtf8();
}

QByteArray TextNode::formatTagText() {
    return text;
}
