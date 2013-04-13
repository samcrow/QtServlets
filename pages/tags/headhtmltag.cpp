#include "headhtmltag.h"
#include "metacharsethtmltag.h"
#include <QDebug>
#include <QTextStream>

HeadHtmlTag::HeadHtmlTag(QObject *parent) :
    ParentHtmlTag("head", parent)
{
    //Add a tag to specify the character set
    appendChildTag(new MetaCharsetHtmlTag("UTF-8", this));
}

void HeadHtmlTag::appendChildTag(HtmlTag *newChild) {
    QByteArray newTagName = newChild->getTagName();
    if(newTagName == "base"
            || newTagName == "link" || newTagName == "style"
            || newTagName == "meta" || newTagName == "script"
            || newTagName == "noscript" || newTagName == "command")
    {
        ParentHtmlTag::appendChildTag(newChild);
    }
    else {
        qWarning() << "Tag of type" << newTagName << "is not allowed inside a head element";
    }
}

void HeadHtmlTag::setPageTitle(QByteArray title) {
    titleTag.setPageTitle(title);
}

bool HeadHtmlTag::selfCloses() {
    return false;
}

QByteArray HeadHtmlTag::formatTagText() {
    QByteArray text;
    QTextStream stream(&text);
    
    stream << "<head>\n";
    //Title tag
    stream << titleTag.formatTagText() << "\n";
    
    //Other child tags
    foreach(HtmlTag* child, getChildTags()) {
        //Recursion: Add the formatted text from each child node
        stream << child->formatTagText();
        //Newline for nicer source formatting
        stream << "\n";
    }
    
    stream << "</head>";
    
    stream.flush();
    return text;
}
