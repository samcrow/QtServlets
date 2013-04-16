#ifndef DIVHTMLTAG_H
#define DIVHTMLTAG_H

#include "parenthtmltag.h"

/**
 * @brief The DivHtmlTag class represents a &lt;div&gt; tag
 */
class DivHtmlTag : public ParentHtmlTag
{
    Q_OBJECT
public:
    explicit DivHtmlTag(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // DIVHTMLTAG_H
