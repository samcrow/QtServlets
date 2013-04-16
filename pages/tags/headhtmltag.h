#ifndef HEADHTMLTAG_H
#define HEADHTMLTAG_H

#include "parenthtmltag.h"
#include "titlehtmltag.h"

/**
 * @brief The HeadHtmlTag class represents the &lt;head&gt; tag of an HTML page
 */
class HeadHtmlTag : public ParentHtmlTag
{
    Q_OBJECT
public:
    explicit HeadHtmlTag(QObject *parent = 0);
    
    /**
     * @brief Appends a child tag.
     *
     * This function has no effect if the tag is not one of the following tag types:
     * <ul>
     *     <li>&lt;base&gt;</li>
     *     <li>&lt;link&gt;</li>
     *     <li>&lt;style&gt;</li>
     *     <li>&lt;meta&gt;</li>
     *     <li>&lt;script&gt;</li>
     *     <li>&lt;noscript&gt;</li>
     *     <li>&lt;command&gt;</li>
     * </ul>
     *
     * This function should not be used to set the page title. use setPageTitle() instead.
     *
     * @param newChild
     * @return Returns this, for method chaining
     */
    HeadHtmlTag* appendChildTag(HtmlTag *newChild);
    
    bool selfCloses();
    
    QByteArray formatTagText();
    
    /**
     * @brief Set the title of the page
     * @param title the title
     */
    void setPageTitle(QByteArray title);
    
private:
    
    //The title tag
    TitleHtmlTag titleTag;
    
signals:
    
public slots:
    
};

#endif // HEADHTMLTAG_H
