#include "parenthtmltag.h"

ParentHtmlTag::ParentHtmlTag(QByteArray tagName, QObject *parent) :
    HtmlTag(tagName, parent)
{
}

QList<HtmlTag *> ParentHtmlTag::getChildTags() {
    return childTags;
}

void ParentHtmlTag::appendChildTag(HtmlTag *newChild) {
    newChild->setParent(this);
    childTags.append(newChild);
}

bool ParentHtmlTag::childrenAllowed() {
    return true;
}

int ParentHtmlTag::getChildTagCount() {
    return childTags.length();
}
