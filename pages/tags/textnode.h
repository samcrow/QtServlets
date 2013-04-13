#ifndef TEXTNODE_H
#define TEXTNODE_H

#include "htmltag.h"

/**
 * @brief The TextNode class displays text in an HTML document.
 */
class TextNode : public HtmlTag
{
    Q_OBJECT
public:
    explicit TextNode(QObject *parent = 0);
    
    /**
     * @brief Sets the text to be displayed.
     * @param text The text. Newlines will be replaced with &lt;br /&gt;s
     * and special characters will be replaced with HTML entities.
     */
    void setText(QString newText);
    
    QByteArray formatTagText();
    
private:
    
    QString text;
    
signals:
    
public slots:
    
};

#endif // TEXTNODE_H
