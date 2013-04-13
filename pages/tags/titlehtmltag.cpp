#include "titlehtmltag.h"

TitleHtmlTag::TitleHtmlTag(QObject *parent) :
    HtmlTag("title", parent)
{
}

void TitleHtmlTag::setPageTitle(QByteArray title) {
    pageTitle = title;
}

QByteArray TitleHtmlTag::formatTagText() {
    return "<title>" + pageTitle + "</title>";
}
