#include "testservlet.h"

#include "pages/htmlpage.h"
#include "pages/tags/scripttag.h"
#include "pages/tags/textnode.h"
#include "pages/tags/divhtmltag.h"

TestServlet::TestServlet(QString specifiedPath, QObject* parent) :
    QServlet(specifiedPath, parent)
{
}

void TestServlet::processRequest(ParamList &/*params*/, ServletResponse &response) {
    
    HtmlPage page;
    page.setPageTitle("This is a title");
    
    page.appendToHead(new ScriptTag("http://code.jquery.com/jquery-1.9.1.min.js"));
    
    TextNode* tn = new TextNode(this);
    tn->setText("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque vitae tincidunt risus. Sed et iaculis metus. Aenean ut tortor leo, ac molestie eros. Cras id mi odio. Maecenas at nisi ut risus ullamcorper hendrerit vitae sed ante. Cras dictum urna eget diam posuere sit amet malesuada sapien suscipit. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Sed eu augue aliquam massa ornare bibendum id non tellus. Phasellus iaculis nulla vel nunc hendrerit suscipit non sed nibh. Vestibulum pharetra sem ut est commodo id placerat mauris scelerisque."
                "Aliquam ac nibh at erat vulputate tincidunt. Proin dictum pulvinar lacus, ac imperdiet est bibendum vitae. Nulla vehicula, tortor a dictum commodo, metus neque gravida nulla, eu pharetra mauris urna vitae neque. Pellentesque interdum, enim in suscipit cursus, nibh orci iaculis orci, a adipiscing odio nunc et risus. Etiam ornare neque in est ultrices eleifend. Curabitur ullamcorper consectetur urna ut volutpat. Morbi eros turpis, interdum et venenatis ac, sodales sit amet elit. Quisque tortor nibh, convallis non vulputate sit amet, faucibus nec est. Aliquam id velit a purus pellentesque sodales. Praesent nunc metus, vulputate vel rhoncus sit amet, sollicitudin et mauris. Suspendisse ante nisi, gravida sit amet rutrum vitae, rutrum id leo. Maecenas sagittis nunc eu dolor luctus id faucibus metus pulvinar. Praesent tincidunt, massa vel faucibus consectetur, ipsum lacus sollicitudin arcu, ac suscipit elit leo ut nibh. Morbi viverra leo eget eros vestibulum suscipit."
                "Sed sed leo non est tempor condimentum. Pellentesque vestibulum, nisl sed pharetra vulputate, lorem est euismod arcu, mattis faucibus augue mauris non eros. Nunc eleifend, mi sit amet pharetra vehicula, nibh purus eleifend turpis, vel mattis sem urna et felis. Quisque suscipit porttitor varius. Vestibulum mattis nisi turpis, nec tristique arcu. Sed tempus, tortor in semper sagittis, sapien dolor placerat erat, consectetur commodo lacus sapien eu dolor. Donec nec quam eget mi convallis suscipit. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Aenean sagittis nisl nec velit porttitor dapibus."
                "Sed fermentum nulla sit amet felis tincidunt viverra rhoncus eros dictum. Morbi a nibh ipsum, vel luctus odio. Curabitur eleifend pharetra turpis id luctus. Praesent scelerisque pretium enim, non elementum libero gravida eget. Sed hendrerit accumsan nisl sed aliquam. Nullam faucibus nulla in tellus dictum posuere. Sed sodales, sapien nec eleifend viverra, metus velit consequat ante, lobortis semper nisi ipsum sed tellus. Duis blandit sem tristique justo ullamcorper sagittis. Aenean quis ante sagittis ligula rhoncus fermentum. Etiam in metus at velit feugiat vehicula. Cras tempus tristique nisi, a vulputate urna pretium nec. Donec sit amet tempus mi. Praesent tempus tincidunt arcu quis lacinia. Praesent sem velit, aliquam eget porta a, viverra convallis leo."
                "Nunc tempus viverra leo vitae imperdiet. Vivamus eget adipiscing tellus. Aenean posuere vestibulum mi ut posuere. Aenean molestie diam ut quam hendrerit sed commodo velit porta. Phasellus tempus bibendum molestie. Sed non odio vel eros consequat posuere ut vel felis. Suspendisse vulputate turpis nibh. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam purus sem, suscipit vel mattis at, congue in purus. Cras facilisis lacinia pulvinar. Sed vel justo nec nibh rutrum dictum. Sed vestibulum metus lobortis nulla auctor nec sollicitudin quam viverra. Donec tellus diam, sollicitudin luctus suscipit at, tristique et mi. Phasellus ac elit ut elit sollicitudin dictum eu a nibh.");
    
    page.appendToBody(tn->wrapped<DivHtmlTag>());
    
    page.appendToEnd(new ScriptTag("http://code.jquery.com/jquery-1.9.1.min.js"));
    
    response << page.formatTagText();
}
