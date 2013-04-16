#ifndef SCRIPTTAG_H
#define SCRIPTTAG_H

#include "htmltag.h"

class ScriptTag : public HtmlTag
{
    Q_OBJECT
public:
    /**
     * @brief Constructor
     * @param src The "src" attribute of the tag, also the path to the script file
     * @param parent
     */
    explicit ScriptTag(QByteArray src, QObject *parent = 0);
    
    /**
     * @brief Set if this tag should include the attribute type="text/javascript".
     *
     * The default setting is false.
     *
     * @param usesTypeAttr
     */
    void setUsesTypeAttr(bool usesTypeAttr);
    
    bool selfCloses();
    
signals:
    
public slots:
    
};

#endif // SCRIPTTAG_H
