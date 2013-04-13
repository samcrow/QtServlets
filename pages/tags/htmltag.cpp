#include "htmltag.h"
#include <QTextStream>

HtmlTag::HtmlTag(QByteArray tagName, QObject *parent) :
    QObject(parent),
    tagName(tagName)
{
}

QByteArray HtmlTag::attr(QByteArray key) {
    return tagAttributes.value(key);
}

void HtmlTag::attr(QByteArray key, QByteArray value) {
    tagAttributes[key] = value;
}

bool HtmlTag::removeAttr(QByteArray key) {
    int removedCount = tagAttributes.remove(key);
    //Return true if an attribute was removed
    return removedCount > 0;
}

bool HtmlTag::childrenAllowed() {
    return false;
}

bool HtmlTag::selfCloses() {
    return true;
}

QByteArray HtmlTag::getTagName() {
    return tagName;
}

QList<HtmlTag *> HtmlTag::getChildTags() {
    return QList<HtmlTag *>();
}

int HtmlTag::getChildTagCount() {
    return 0;
}

QMap<QByteArray, QByteArray> HtmlTag::getAllAttributes() {
    return tagAttributes;
}

QByteArray HtmlTag::formatTagText() {
    QByteArray text;
    QTextStream stream(&text);
    
    //First part: <tagName
    stream << "<" << getTagName();
    
    //Attributes
    if(tagAttributes.size() > 0) {
        QMapIterator<QByteArray, QByteArray> iterator(tagAttributes);
        while(iterator.hasNext()) {
            iterator.next();
            //Add each attribute
            stream << " " << iterator.key() << "=\"" << iterator.value() << "\"";
        }
    }
    //Child tags
    if(getChildTagCount() > 0) {
        //Finish the opening tag
        stream << ">";
        
        foreach(HtmlTag* child, getChildTags()) {
            //Recursion: Add the formatted text from each child node
            stream << child->formatTagText();
            //Newline for nicer source formatting
            stream << "\n";
        }
        
        //Add a closing tag to close this element
        stream << "</" << getTagName() << ">";
    }
    else {
        //No child tags
        if(selfCloses()) {
            // <tagName />
            stream << " />";
        }
        else {
            // <tagName></tagName>
            stream << "></" << getTagName() << ">";
        }
    }
    
    stream.flush();
    return text;
}
