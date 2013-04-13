#ifndef TITLEHTMLTAG_H
#define TITLEHTMLTAG_H

#include "htmltag.h"

/**
 * @brief The TitleHtmlTag class represents the &lt;title&gt; tag
 */
class TitleHtmlTag : public HtmlTag
{
    Q_OBJECT
public:
    explicit TitleHtmlTag(QObject *parent = 0);
    
    QByteArray formatTagText();
    
    /**
     * @brief Set the page title
     * @param title
     */
    void setPageTitle(QByteArray title);
    
private:
    
    /**
     * @brief The page title to display
     */
    QByteArray pageTitle;
    
signals:
    
public slots:
    
};

#endif // TITLEHTMLTAG_H
