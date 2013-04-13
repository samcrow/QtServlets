#include "paramtestservlet.h"

ParamTestServlet::ParamTestServlet(QString specifiedPath, QObject *parent) :
    QServlet(specifiedPath, parent)
{
}

void ParamTestServlet::processRequest(ParamList &params, ServletResponse &response) {
    response << "<html><head><title>Parameter Test</title></head><body>";
    response << "<h1>Parameters</h1>";
    response << "<table><tr><th>Key</th><th>Value</th></tr>";
    
    foreach(Param p, params) {
        response << "<tr><td>" << p.key() << "</td><td>" << p.value() << "</td></tr>";
    }
    
    response << "</table></body></html>";
}
