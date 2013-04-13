#ifndef QHTTPSERVLETSERVER_H
#define QHTTPSERVLETSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QNetworkRequest>
#include <QHash>
#include "qtservlet_global.h"
#include "qservlet.h"

/**
 * @brief The QHttpServletServer class sets up an HTTP
 * server on a given port and routes requests to QServlets.
 *
 * 
 */
class QTSERVLETSHARED_EXPORT QHttpServletServer : public QObject
{
    Q_OBJECT
public:
    explicit QHttpServletServer(QObject *parent = 0);
    
    /**
     * @brief binds to the given port and prepares to accept connections
     * @param port
     */
    void bind(quint16 port);
    
    /**
     * @brief addServlet Adds a servlet to this server.
     * 
     * The new servlet will be used to handle requests.
     * This server instance will take ownership of the servlet,
     * so you do not have to worry about deleting it.
     *
     * @param newServlet The servlet to add
     */
    void addServlet(QServlet* newServlet);
    
private:
    
    QTcpServer server;
    
    /**
     * @brief processSocket reads a request and sends a response.
     * After this method completes, the socket can be deleted later.
     * @param socket
     */
    void processSocket(QTcpSocket* socket);
    
    /**
     * @brief parseRequest parses the text of an HTTP request and extracts the path and parameters
     * @param httpRequest
     * @param path
     * @param params
     */
    void parseRequest(QByteArray& httpRequest, QString* path, QServlet::ParamList* params);
    
    /**
     * @brief servletForPath finds the servlet to run for a given path.
     * @param path
     * @return the servlet to run, or nullptr if no servlet for this path exists
     */
    QServlet* servletForPath(QString& path);
    
    /**
     * @brief pathCache maps paths to servlets.
     *
     * When a path is requested that is not in the cache,
     * each servlet is asked if it matches the path. If one does, the mapping between the path
     * and that servlet instance is added to this cache so that future requests to this path
     * will be faster.
     */
    QHash<QString, QServlet* > pathCache;
    
    /**
     * @brief All the servlets that have been added to this server
     */
    QList<QServlet * > servlets;
    
    /**
     * @brief The servlet used to send 404 errors
     */
    QServlet* error404Servlet;
    
signals:
    
private slots:
    
    void newConnection();
    
    /**
     * @brief Connected to readyRead() of each socket. Reads data and responds.
     */
    void onSocketReadyRead();
    
public slots:
    
};

#endif // QHTTPSERVLETSERVER_H
