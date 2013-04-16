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
     * @brief Formats and returns the HTML source code of the page
     * (equivalent to formatTagText() ).
     * @return 
     */
    QByteArray formatPageText();
    
    /**
     * @brief Set the title of the page
     * @param title
     */
    void setPageTitle(QByteArray title);
    
    /**
     * @brief Append a node to the head of the page
     * @param tag
     */
    void appendToHead(HtmlTag* tag);
    
    /**
     * @brief Append a node to the body of the page
     * @param tag
     */
    void appendToBody(HtmlTag* tag);
    
    /**
     * @brief Append a node to the end of the body,
     * just before the &lt;body&gt; tag. This is useful
     * for JavaScript includes.
     * @param tag
     */
    void appendToEnd(HtmlTag* tag);
    
private:
    
    //Head and body
    HeadHtmlTag head;
    BodyHtmlTag body;
    
signals:
    
public slots:
    
};

#endif // HTMLPAGE_H
