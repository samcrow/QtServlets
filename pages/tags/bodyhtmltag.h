#ifndef BODYHTMLTAG_H
#define BODYHTMLTAG_H

#include "parenthtmltag.h"

/**
 * @brief The BodyHtmlTag class stores a &lt;body&gt; tag
 */
class BodyHtmlTag : public ParentHtmlTag
{
    Q_OBJECT
public:
    explicit BodyHtmlTag(QObject *parent = 0);
    
    bool selfCloses();
    
signals:
    
public slots:
    
};

#endif // BODYHTMLTAG_H
