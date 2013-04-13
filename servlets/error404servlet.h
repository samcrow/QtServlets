#ifndef ERROR404SERVLET_H
#define ERROR404SERVLET_H

#include "../qservlet.h"

/**
 * @brief The Error404Servlet class provides a response that gives
 * a relatively helpful 404 error message.
 */
class Error404Servlet : public QServlet
{
    Q_OBJECT
public:
    explicit Error404Servlet(QObject *parent = 0);
    
    void processRequest(ParamList &, ServletResponse &response);
    
signals:
    
public slots:
    
};

#endif // ERROR404SERVLET_H
