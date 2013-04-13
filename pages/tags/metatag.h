#ifndef METATAG_H
#define METATAG_H

#include "htmltag.h"

/**
 * @brief The MetaTag class represents an &lt;meta&gt; tag, and supports both the content and http-equiv attributes
 */
class MetaTag : public HtmlTag
{
    Q_OBJECT
public:
    /**
     * @brief Constructor
     * @param name The value of the "name" attribute of this tag
     * @param parent
     */
    explicit MetaTag(QByteArray name, QObject *parent = 0);
    
    /**
     * @brief Sets the "content" attribute of this element
     * @param content
     */
    void setContent(QByteArray content);
    
    /**
     * @brief Sets the "http-equiv" attribute of this element
     * @param content
     */
    void setHttpEquiv(QByteArray content);
    
signals:
    
public slots:
    
};

#endif // METATAG_H
