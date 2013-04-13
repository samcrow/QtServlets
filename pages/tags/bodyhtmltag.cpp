#include "bodyhtmltag.h"

#include "textnode.h"

BodyHtmlTag::BodyHtmlTag(QObject *parent) :
    ParentHtmlTag("body", parent)
{
    TextNode* tn = new TextNode(this);
    tn->setText("This is some text!\nThat was a newline.\nHere are some special characters: !@#$%^&*()_<<<<<>>><<œ∑´®†¥¨ˆøπ“‘«åß∂ƒ©˙∆˚¬…Ω\\≈ç√∫˜µ≤≥÷\nThat was another newline.\nCake & Pie!");
    appendChildTag(tn);
}

bool BodyHtmlTag::selfCloses() {
    return false;
}
