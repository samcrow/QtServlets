#include "testservlet.h"

#include "pages/htmlpage.h"

TestServlet::TestServlet(QString specifiedPath, QObject* parent) :
    QServlet(specifiedPath, parent)
{
}

void TestServlet::processRequest(ParamList &/*params*/, ServletResponse &response) {
    
    HtmlPage page;
    page.setPageTitle("This is a title");
    
    response << page.formatTagText();
}
