#ifndef HTMLDOCTYPES_H
#define HTMLDOCTYPES_H

#include <QByteArray>

class HtmlDoctypes
{
public:
    /**
     * @brief The Doctype enum defines different DOCTYPEs
     * and HTML versions that a page can conform to
     */
    enum class Doctype {
        /**
         * No DOCTYPE, no charset information in head,
         * but otherwise valid XHTML
         */
        BasicXhtml,
        /**
         * XHTM 1.0 strict
         */
        Xhtml10Strict,
        /**
         * HTML5
         */
        Html5,
    };
    
    /**
     * @brief Get the doctype string for a doctype,
     * for example "<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">"
     * @param type
     * @return 
     */
    static QByteArray doctypeString(Doctype type) {
        switch(type) {
        
        case Doctype::BasicXhtml:
            return "";
            
        case DocType::Xhtml10Strict:
            return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">";
            
        case DocType::Html5:
            return "<!DOCTYPE HTML>";
            
        default:
            qWarning() << "Doctype" << type << "not implemented in doctypeString()";
            Q_ASSERT_X(false, "doctypeString", "The provided document type is not implemented in doctypeString()");
            return "(Doctype error)";
        }
    }
    
    /**
     * @brief Determine if a doctype should close its tags XML-style with &lt;tag /&gt; syntax, or if it should
     * leave them unclosed (classic-HTML-style)
     * @param type
     * @return 
     */
    static bool closesTags(Doctype type) {
        switch(type) {
        
        case Doctype::BasicXhtml:
            return true;
            
        case DocType::Xhtml10Strict:
            return true;
            
        case DocType::Html5:
            return false;
            
        default:
            qWarning() << "Doctype" << type << "not implemented in closesTags()";
            Q_ASSERT_X(false, "closesTags", "The provided document type is not implemented in closesTags()");
            return true;
        }
    }
    
private:
    HtmlDoctypes() {}
};

#endif // HTMLDOCTYPES_H
