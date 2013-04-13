#ifndef HTMLHEADER_H
#define HTMLHEADER_H

#include <QObject>

/**
 * @brief The HtmlHeader class contains the &lt;head&gt;
 * of the page and the beginning of the &lt;body&gt;.
 */
class HtmlHeader : public QObject
{
    Q_OBJECT
public:
    explicit HtmlHeader(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // HTMLHEADER_H
