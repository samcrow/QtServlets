#include "scripttag.h"

ScriptTag::ScriptTag(QByteArray src, QObject *parent) :
    HtmlTag("script", parent)
{
    attr("src", src);
}

void ScriptTag::setUsesTypeAttr(bool usesTypeAttr) {
    if(usesTypeAttr) {
        attr("type", "text/javascript");
    }
    else {
        removeAttr("type");
    }
}
