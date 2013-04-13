#include "testservlet.h"

TestServlet::TestServlet(QString specifiedPath, QObject* parent) :
    QServlet(specifiedPath, parent)
{
}

void TestServlet::processRequest(ParamList &/*params*/, ServletResponse &response) {
    response << "Yay!\n";
    response.setContentType("text/plain");
    response << "Pie is good.";
}
