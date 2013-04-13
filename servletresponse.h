#ifndef SERVLETRESPONSE_H
#define SERVLETRESPONSE_H

#include "qtservlet_global.h"
#include <QTextStream>
#include <QHash>

/**
 * @brief The ServletResponse class contains everything that can be sent
 * in an HTTP response.
 *
 * Text in the response body should be inserted directly with the
 * QTextStream functionality
 */
class QTSERVLETSHARED_EXPORT ServletResponse : public QTextStream
{
public:
    ServletResponse();
    
    void setResponseHeader(QString name, QString value);
    
    void setContentType(QString newType);
    
    void setStatusCode(int newCode);
    
    /**
     * @brief getFullResponseText returns the complete text
     * of the response, including headers and the body
     * @return 
     */
    QByteArray getFullResponseText();
    
    /**
     * @brief statusCodes maps between HTTP status codes and their
     * corresponding messages.
     *
     * For example, 200 => "OK" and 404 => "Not Found"
     *
     * This is initialized statically.
     */
    static const QHash<int, QString> statusCodes;
    
private:
    
    /**
     * @brief The response body
     */
    QString body;
    
    /**
     * @brief headers contains the set of HTTP response
     * headers to be send.
     */
    QHash<QString, QString> headers;
    
    /**
     * @brief statusCode is the HTTP status code that will be sent
     */
    int statusCode;
    
    /**
     * @brief makeStatusCodeMap creates a map that is stored as statusCodes.
     *
     * This only runs once, when the class is loaded.
     *
     * @return 
     */
    static QHash<int, QString> makeStatusCodeMap();
};

#endif // SERVLETRESPONSE_H
