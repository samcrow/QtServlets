#include "metacharsethtmltag.h"

MetaCharsetHtmlTag::MetaCharsetHtmlTag(QByteArray charset, QObject *parent) :
    HtmlTag("meta", parent)
{
    attr("charset", charset);
}
