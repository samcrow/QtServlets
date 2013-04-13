#include "error404servlet.h"

Error404Servlet::Error404Servlet(QObject *parent) :
    QServlet(QString(), parent)
{
}

void Error404Servlet::processRequest(ParamList &/*params*/, ServletResponse &response) {
    response.setStatusCode(404);
    
    response << "<html><head><title>Not Found</title></head><body>";
    response << "<h1>Not Found</h1><p>The requested resource was not found.</p>";
    response << "</body></html>";
}
