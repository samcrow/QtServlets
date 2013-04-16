#include "parenthtmltag.h"
#include "textnode.h"

ParentHtmlTag::ParentHtmlTag(QByteArray tagName, QObject *parent) :
    HtmlTag(tagName, parent)
{
}

QList<HtmlTag *> ParentHtmlTag::getChildTags() {
    return childTags;
}

ParentHtmlTag* ParentHtmlTag::appendChildTag(HtmlTag *newChild) {
    newChild->setParent(this);
    childTags.append(newChild);
    return this;
}

ParentHtmlTag* ParentHtmlTag::appendText(QByteArray text) {
    TextNode* textNode = new TextNode(this);
    textNode->setText(text);
    appendChildTag(textNode);
    return this;
}

bool ParentHtmlTag::childrenAllowed() {
    return true;
}

int ParentHtmlTag::getChildTagCount() {
    return childTags.length();
}
