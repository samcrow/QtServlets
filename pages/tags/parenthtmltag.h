#ifndef PARENTHTMLTAG_H
#define PARENTHTMLTAG_H

#include "htmltag.h"

/**
 * @brief The ParentHtmlTag class is a type of HtmlTag that can have
 * child HtmlTags.
 */
class ParentHtmlTag : public HtmlTag
{
    Q_OBJECT
public:
    explicit ParentHtmlTag(QByteArray tagName, QObject *parent = 0);
    
    QList<HtmlTag *> getChildTags();
    
    /**
     * @brief Append a child of this element. This instance
     * will take ownership of the child tag.
     * @param newChild
     * @return Returns this, for method chaining
     */
    virtual ParentHtmlTag* appendChildTag(HtmlTag* newChild);
    
    /**
     * @brief Append text (in the form of a TextNode) to the content of this element
     * @param text
     * @return Returns this, for method chaining
     */
    ParentHtmlTag* appendText(QByteArray text);
    
    bool childrenAllowed();
    
    int getChildTagCount();
    
private:
    
    QList<HtmlTag *> childTags;
    
signals:
    
public slots:
    
};

#endif // PARENTHTMLTAG_H
