#ifndef QSERVLET_H
#define QSERVLET_H

#include "qtservlet_global.h"
#include "servletresponse.h"

#include <QList>
#include <QString>

/**
 * @brief The QServlet class responds to HTTP requests
 */
class QTSERVLETSHARED_EXPORT QServlet : public QObject
{
    Q_OBJECT
public:
    
    class Param {
    public:
        Param(QString key, QString value) :
            key_(key),
            value_(value)
        {
        }
        inline QString key() { return key_; }
        inline QString value() { return value_; }
    private:
        QString key_;
        QString value_;
    };
    
    typedef QList<Param> ParamList;
    
    /**
     * @brief Contructor
     * @param specifiedPath The optional path, starting with a forward
     * slash, that this servlet should match. This is checked before the servlet's
     * implementation of matchesPath() is consulted. To ignore this option,
     * pass in QString().
     * @param parent
     */
    QServlet(QString specifiedPath = QString(), QObject* parent = 0);
    
    /**
     * @brief matchesPath should determine if this servlet should run
     * when a client requests a given path.
     * 
     * This may be called frequently, so it should be fast.
     *
     * The default implementation returns true if the path is equal to
     * the specifiedPath defined in the constructor. If no specifiedPath
     * has been set, it returns false.
     *
     * @param path The requested path, starting with a forward slash
     * @return True if this servlet should run for a request to this path,
     * otherwise false
     */
    virtual bool matchesPath(QString& path);
    
    /**
     * @brief processRequest
     * @param params
     * @param response
     */
    virtual void processRequest(ParamList& params, ServletResponse& response) = 0;
    
    
private:
    
    /**
     * @brief The path for this servlet. This is optionally specified in the constructor.
     * If it is set, it is used in the default implementation of matchesPath().
     * If it is empty, it is ignored.
     */
    QString specifiedPath;
    
};

#endif // QSERVLET_H
