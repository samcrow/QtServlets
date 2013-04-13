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

void HtmlPage::setPageTitle(QByteArray title) {
    head.setPageTitle(title);
}
