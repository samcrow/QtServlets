#ifndef BODYHTMLTAG_H
#define BODYHTMLTAG_H

#include "parenthtmltag.h"

/**
 * @brief The BodyHtmlTag class stores a &lt;body&gt; tag.
 *
 * It can store a set of nodes that will always be output at the end
 * of the body element. This is useful for JavaScript includes.
 *
 */
class BodyHtmlTag : public ParentHtmlTag
{
    Q_OBJECT
public:
    explicit BodyHtmlTag(QObject *parent = 0);
    
    bool selfCloses();
    
    /**
     * @brief Append a child tag to be output after the children
     * of this tag, just before the end of the body element.
     *
     * This instance will take ownership of the child tag.
     *
     * @param child The tag to add
     */
    void appendEndTag(HtmlTag* child);
    
    QByteArray formatTagText();
    
private:
    
    QList<HtmlTag *> endTags;
    
signals:
    
public slots:
    
};

#endif // BODYHTMLTAG_H
