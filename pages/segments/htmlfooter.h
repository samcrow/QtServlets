#ifndef HTMLFOOTER_H
#define HTMLFOOTER_H

#include <QObject>

class AbstractHtmlPage;

/**
 * @brief The HtmlFooter class stores script tags at the end of the page
 * and the closing body and html tags.
 */
class HtmlFooter : public QObject
{
    Q_OBJECT
public:
    explicit HtmlFooter(AbstractHtmlPage *parent = 0);
    
signals:
    
public slots:
    
};

#endif // HTMLFOOTER_H
