#include "bodyhtmltag.h"

#include "textnode.h"
#include <QTextStream>

BodyHtmlTag::BodyHtmlTag(QObject *parent) :
    ParentHtmlTag("body", parent)
{
}

bool BodyHtmlTag::selfCloses() {
    return false;
}

void BodyHtmlTag::appendEndTag(HtmlTag *child) {
    child->setParent(this);
    endTags.append(child);
}

QByteArray BodyHtmlTag::formatTagText() {
    QByteArray text;
    QTextStream stream(&text);
    
    //First part: <tagName
    stream << "<body";
    
    //Attributes
    if(tagAttributes.size() > 0) {
        QMapIterator<QByteArray, QByteArray> iterator(tagAttributes);
        while(iterator.hasNext()) {
            iterator.next();
            //Add each attribute
            stream << " " << iterator.key() << "=\"" << iterator.value() << "\"";
        }
    }
    //Finish the opening tag
    stream << ">\n";
    
    //Child tags
    if(getChildTagCount() > 0) {
        
        foreach(HtmlTag* child, getChildTags()) {
            //Recursion: Add the formatted text from each child node
            stream << child->formatTagText();
            //Newline for nicer source formatting
            stream << "\n";
        }
    }
    
    //End child tags
    foreach(HtmlTag* child, endTags) {
        stream << child->formatTagText() << "\n";
    }
    
    stream << "</body>";
    
    stream.flush();
    return text;
}
