#ifndef METACHARSETHTMLTAG_H
#define METACHARSETHTMLTAG_H

#include "htmltag.h"

/**
 * @brief The MetaCharsetHtmlTag class represents a meta element that is used to define the character set.
 */
class MetaCharsetHtmlTag : public HtmlTag
{
    Q_OBJECT
public:
    /**
     * @brief Constructor
     * @param charset The character set that the document uses. This is usually "UTF-8".
     * @param parent
     */
    explicit MetaCharsetHtmlTag(QByteArray charset, QObject *parent = 0);
    
private:
    
signals:
    
public slots:
    
};

#endif // METACHARSETHTMLTAG_H
