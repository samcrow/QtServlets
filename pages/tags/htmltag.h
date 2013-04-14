#ifndef HTMLTAG_H
#define HTMLTAG_H

#include <QObject>
#include <QMap>

/**
 * @brief The HtmlTag class represents an HTML tag.
 *
 * Many functions return a pointer to this, so methods can be
 * chained.
 */
class HtmlTag : public QObject
{
    Q_OBJECT
public:
    
    /**
     * @brief Constructor
     * @param tagName The name of this tag, for example "div" or "span"
     * @param parent
     */
    explicit HtmlTag(QByteArray tagName, QObject *parent = 0);
    
    /**
     * @brief Get the value of the given attribute
     * @param key The name of the attribute
     * @return If this element has an attribute set with the given name,
     * returns the value that is set. If the attribute is set but empty,
     * returns an emtpy QByteArray (empty but not null). If the attribute
     * is not set, returns a null QByteArray (empty and null).
     */
    QByteArray attr(QByteArray key);
    
    /**
     * @brief Set the value of a given attribute.
     *
     * If the attribute already exists, its old value will be 
     * replaced by the new value.
     *
     * @param key The name of the attribute to set
     * @param value The value to set
     */
    HtmlTag* attr(QByteArray key, QByteArray value);
    
    /**
     * @brief Removes an attribute from this element
     * @param key The attribute to remove
     * @return true if the attribute was present and was removed successfully,
     * or false if the attribute was already not present.
     */
    bool removeAttr(QByteArray key);
    
    /**
     * @brief Gets all the attributes of this tag
     * @return 
     */
    QMap<QByteArray, QByteArray>& getAllAttributes();
    
    /**
     * @brief Adds a class to this tag
     * @param newClass the class to add
     */
    HtmlTag* addClass(QByteArray newClass);
    
    /**
     * @brief Checks if this tag is allowed to have child tags.
     *
     * The default implementation returns false.
     *
     * @return 
     */
    virtual bool childrenAllowed();
    
    /**
     * @brief Determine if this element can use self-closing tag syntax.
     *
     * For example, &lt;br /&gt; and &lt;br&gt; use self-closing syntax,
     * while &lt;p&gt;&lt/p&gt; has to use an explicit, seperate closing tag.
     *
     * The default implementation returns true.
     *
     * @return 
     */
    virtual bool selfCloses();
    
    /**
     * @brief Get the name of this tag
     * @return 
     */
    QByteArray& getTagName();
    
    /**
     * @brief Get all the children of this tag.
     * @return The default implementation returns an empty list.
     */
    virtual QList<HtmlTag *> getChildTags();
    
    /**
     * @brief Get the number of child tags
     * @return The default implementation returns 0.
     */
    virtual int getChildTagCount();
    
    
    /**
     * @brief Get the HTML text that represents this tag.
     * @return 
     */
    virtual QByteArray formatTagText();
    
protected:
    
    /**
     * @brief Every attribute of this element
     */
    QMap<QByteArray, QByteArray> tagAttributes;
    
    /**
     * @brief The name of this tag, for example "div" or "span"
     */
    QByteArray tagName;
    
signals:
    
public slots:
    
};

#endif // HTMLTAG_H
