#ifndef TESTSERVLET_H
#define TESTSERVLET_H

#include "qtservlet_global.h"
#include "qservlet.h"

class QTSERVLETSHARED_EXPORT TestServlet : public QServlet
{
public:
    TestServlet(QString specifiedPath = QString(), QObject* parent = 0);
    
    void processRequest(ParamList &params, ServletResponse &response);
    
};

#endif // TESTSERVLET_H
