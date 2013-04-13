#ifndef HTMLPAGE_H
#define HTMLPAGE_H

#include "tags/htmltag.h"
#include "tags/headhtmltag.h"
#include "tags/bodyhtmltag.h"

/**
 * @brief The HtmlPage class stores a page of HTML. Markup is output in HTML5 with self-closing XHTML-style tags.
 */
class HtmlPage : public HtmlTag
{
    Q_OBJECT
public:
    explicit HtmlPage(QObject *parent = 0);
    
    QByteArray formatTagText();
    
    /**
     * @brief Set the title of the page
     * @param title
     */
    void setPageTitle(QByteArray title);
    
private:
    
    //Head and body
    HeadHtmlTag head;
    BodyHtmlTag body;
    
signals:
    
public slots:
    
};

#endif // HTMLPAGE_H
