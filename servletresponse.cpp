#include "servletresponse.h"
#include <QDebug>

const QHash<int, QString> ServletResponse::statusCodes = ServletResponse::makeStatusCodeMap();

ServletResponse::ServletResponse() :
    QTextStream()
{
    QTextStream::setString(&body);
    
    //Defaults: HTML and 200 OK
    setContentType("text/html");
    setStatusCode(200);
}

void ServletResponse::setResponseHeader(QString name, QString value) {
    headers.insert(name, value);
}

void ServletResponse::setContentType(QString newType) {
    setResponseHeader("Content-Type", newType);
}

QByteArray ServletResponse::getFullResponseText() {
    //Ensure that everything that has been added to the body
    //has been added to the string
    QTextStream::flush();
    
    //Set the content length
    int contentLength = body.length();
    setResponseHeader("Content-Length", QString::number(contentLength));
    
    QString response;
    QTextStream stream(&response);
    
    stream << "HTTP/1.1 " << QString::number(statusCode) << ' ' << statusCodes.value(statusCode) << "\r\n";
    //Add the remaining headers
    QList<QString> keys = headers.keys();
    foreach(QString key, keys) {
        QString value = headers[key];
        stream << key << ": " << value << "\r\n";
    }
    //Final \r\n before the body
    stream << "\r\n";
    
    stream << body;
    
    stream.flush();
    
    QByteArray responseBytes = response.toUtf8();
    
    return responseBytes;
}

QHash<int, QString> ServletResponse::makeStatusCodeMap() {
    QHash<int, QString> codes;
    
    codes.insert(100, "Continue");
    codes.insert(101, "Switching Protocols");
    codes.insert(102, "Processing");
    
    codes.insert(200, "OK");
    codes.insert(201, "Created");
    codes.insert(202, "Accepted");
    codes.insert(203, "Non-Authoritative Information");
    codes.insert(204, "No Content");
    codes.insert(205, "Reset Content");
    codes.insert(206, "Partial Content");
    codes.insert(207, "Multi-Status");
    codes.insert(208, "Already Reported");
    codes.insert(226, "IM Used");
    
    codes.insert(300, "Multiple Choices");
    codes.insert(301, "Moved Permanently");
    codes.insert(302, "Found");
    codes.insert(303, "See Other");
    codes.insert(304, "Not Modified");
    codes.insert(305, "Use Proxy");
    codes.insert(307, "Temporary Redirect");
    codes.insert(308, "Permanent Redirect");
    
    codes.insert(400, "Bad Request");
    codes.insert(401, "Unauthorized");
    codes.insert(402, "Payment Required");
    codes.insert(403, "Forbidden");
    codes.insert(404, "Not Found");
    codes.insert(405, "Method Not Allowed");
    codes.insert(406, "Not Acceptable");
    codes.insert(407, "Proxy Authentication Required");
    codes.insert(408, "Request Timeout");
    codes.insert(409, "Conflict");
    codes.insert(410, "Gone");
    codes.insert(411, "Length Required");
    codes.insert(412, "Precondition Failed");
    codes.insert(413, "Request Entity Too Large");
    codes.insert(414, "Request-URI Too Long");
    codes.insert(415, "Unsupported Media Type");
    codes.insert(416, "Requested Range Not Satisfiable");
    codes.insert(417, "Expectation Failed");
    codes.insert(418, "I'm a teapot");       // :-)
    
    codes.insert(500, "Internal Server Error");
    codes.insert(501, "Not Implemented");
    codes.insert(502, "Bad Gateway");
    codes.insert(503, "Service Unavailable");
    codes.insert(504, "Gateway Timeout");
    codes.insert(505, "HTTP Version Not Supported");
    
    return codes;
}

void ServletResponse::setStatusCode(int newCode) {
    
    if(!statusCodes.contains(newCode)) {
        qWarning() << "Invalid status code" << newCode;
        return;
    }
    
    statusCode = newCode;
}
