#include "htmlpage.h"
#include <QTextStream>

HtmlPage::HtmlPage(QObject *parent) :
    HtmlTag("html", parent)
{
}

QByteArray HtmlPage::formatTagText() {
    QByteArray text;
    QTextStream stream(&text);
    
    stream << "<!DOCTYPE HTML>\n";
    stream << "<html>\n";
    stream << head.formatTagText() << "\n";
    stream << body.formatTagText() << "\n";
    stream << "</html>";
    
    stream.flush();
    return text;
}

QByteArray HtmlPage::formatPageText() {
    return formatTagText();
}

void HtmlPage::setPageTitle(QByteArray title) {
    head.setPageTitle(title);
}

void HtmlPage::appendToHead(HtmlTag *tag) {
    head.appendChildTag(tag);
}

void HtmlPage::appendToBody(HtmlTag *tag) {
    body.appendChildTag(tag);
}

void HtmlPage::appendToEnd(HtmlTag *tag) {
    body.appendEndTag(tag);
}
