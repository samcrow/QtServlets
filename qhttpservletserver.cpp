#include "qhttpservletserver.h"
#include <QTcpSocket>
#include <QBuffer>
#include <QDebug>
#include <QUrl>
#include "error404servlet.h"

QHttpServletServer::QHttpServletServer(QObject *parent) :
    QObject(parent),
    error404Servlet(new Error404Servlet(this))
{
    connect(&server, &QTcpServer::newConnection, this, &QHttpServletServer::newConnection);
}

void QHttpServletServer::bind(quint16 port) {
    bool success = server.listen(QHostAddress::Any, port);
    
    if(!success) {
        qWarning() << "Failed to bind to port" << port << server.serverError() << server.errorString();
    }
}

void QHttpServletServer::newConnection() {
    while(server.hasPendingConnections()) {
        QTcpSocket * newSocket = server.nextPendingConnection();
        
        //Hook up a signal for further operations. Once this socket has received the HTTP request,
        //the request will be read and responded to.
        connect(newSocket, &QTcpSocket::readyRead, this, &QHttpServletServer::onSocketReadyRead);
    }
}

void QHttpServletServer::onSocketReadyRead() {
    QObject* sendingObject = sender();
    QTcpSocket* sendingSocket = qobject_cast<QTcpSocket* >(sendingObject);
    
    Q_ASSERT_X(sendingSocket != 0, "onSocketReadyRead", "Sending QObject could not be cast into a QTcpSocket");
    
    processSocket(sendingSocket);
}

void QHttpServletServer::processSocket(QTcpSocket *socket) {
    //Read the HTTP request
    QByteArray requestText = socket->readAll();
    
    //Parse the HTTP request
    QString path;
    QServlet::ParamList params;
    parseRequest(requestText, &path, &params);
    
    //Find the servlet to run
    QServlet* servlet = servletForPath(path);
    //If this path->servlet mapping is valid and should be cached
    bool validServlet = true;
    
    if(servlet == nullptr) {
        //No servlet found, so send a 404 error
        //Use the servelet that does this
        servlet = error404Servlet;
        //Indicate that this path->servlet mapping is invalid and should not be cached
        validServlet = false;
    }
    //Run the servlet
    ServletResponse response;
    servlet->processRequest(params, response);
    
    //Send the response
    socket->write(response.getFullResponseText());
    //Delete the socket
    socket->flush();
    socket->close();
    socket->deleteLater();
    
    //Cache the mapping, if it should be cached
    if(validServlet) {
        pathCache.insert(path, servlet);
    }
}

void QHttpServletServer::parseRequest(QByteArray& httpRequest, QString* path, QServlet::ParamList* params) {
    QBuffer requestBuffer(&httpRequest);
    requestBuffer.open(QIODevice::ReadOnly);
    
    //First line: GET /path HTTP/1.1
    QByteArray firstLine = requestBuffer.readLine();
    QList<QByteArray> firstLineParts = firstLine.split(' ');
    QByteArray method = firstLineParts[0];
    QByteArray pathWithParams = firstLineParts[1];
    
    if(method != "GET") {
        qWarning() << "Unsupported method" << method;
    }
    
    QList<QByteArray> pathPlusParams = pathWithParams.split('?');
    
    //Use fromPercentEncoding() to convert %20 into space, etc.
    *path = QUrl::fromPercentEncoding(pathPlusParams[0]);
    
    qDebug() << "De-percented path" << *path;
    
    //List has two parts if there is a pre-param and a post-param part
    if(pathPlusParams.length() > 1) {
        QList<QByteArray> paramPairs = pathPlusParams[1].split('&');
        foreach(QByteArray pair, paramPairs) {
            
            QList<QByteArray> keyAndValue = pair.split('=');
            
            QByteArray key = keyAndValue[0];
            QByteArray value;
            if(keyAndValue.length() > 1) {
                value = keyAndValue[1];
            } else {
                value = "";
            }
            
            params->append(QServlet::Param(key, value));
        }
    }
}

QServlet* QHttpServletServer::servletForPath(QString &path) {
    
    //First try the cache
    if(pathCache.contains(path)) {
        return pathCache.value(path);
    }
    //Then ask each servlet
    //Iterate backwards so that the most recently added servlet has priority (but lower priority than the cache)
    for(int i = servlets.length() - 1; i >= 0; i--) {
        QServlet* servlet = servlets.at(i);
        if(servlet->matchesPath(path)) {
            return servlet;
        }
    }
    
    //Nothing left
    return nullptr;
}

void QHttpServletServer::addServlet(QServlet *newServlet) {
    newServlet->setParent(this);
    servlets.append(newServlet);
}
