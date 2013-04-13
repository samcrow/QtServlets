#include "metatag.h"

MetaTag::MetaTag(QByteArray name, QObject *parent) :
    HtmlTag("meta", parent)
{
    attr("name", name);
}

void MetaTag::setContent(QByteArray content) {
    attr("content", content);
}

void MetaTag::setHttpEquiv(QByteArray content) {
    attr("http-equiv", content);
}
