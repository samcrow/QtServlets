#include "textnode.h"
#include <QRegExp>
#include <QDebug>

TextNode::TextNode(QObject *parent) :
    HtmlTag("(text)", parent)
{
}

void TextNode::setText(QString newText) {
    
    QString processedText = newText.toHtmlEscaped();
    //Replace newlines with <br />s
    static const QRegExp newlineRegex("[\n\r]+");
    processedText = processedText.replace(newlineRegex, "<br />");
    
    text = processedText;
}

QByteArray TextNode::formatTagText() {
    QByteArray utf8 = text.toUtf8();
    
    return utf8;
}
