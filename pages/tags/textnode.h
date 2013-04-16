#ifndef TEXTNODE_H
#define TEXTNODE_H

#include "htmltag.h"

/**
 * @brief The TextNode class displays text in an HTML document.
 *
 * All text that is provided to it is filtered to remove &amp;s, &lt;s, and &gt;s
 * so that the HTML structure will not be compromised.
 */
class TextNode : public HtmlTag
{
    Q_OBJECT
public:
    explicit TextNode(QObject *parent = 0);
    
    /**
     * @brief Constructor
     * @param text The text to display
     * @param parent
     */
    TextNode(QByteArray text, QObject* parent = 0);
    
    /**
     * @brief Sets the text to be displayed.
     * @param text The text. Newlines will be replaced with &lt;br /&gt;s
     * and special characters will be replaced with HTML entities.
     */
    void setText(QByteArray newText);
    
    QByteArray formatTagText();
    
private:
    
    QByteArray text;
    
signals:
    
public slots:
    
};

#endif // TEXTNODE_H
