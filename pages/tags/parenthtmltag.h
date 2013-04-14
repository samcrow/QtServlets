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
     */
    virtual void appendChildTag(HtmlTag* newChild);
    
    bool childrenAllowed();
    
    int getChildTagCount();
    
private:
    
    QList<HtmlTag *> childTags;
    
signals:
    
public slots:
    
};

#endif // PARENTHTMLTAG_H
