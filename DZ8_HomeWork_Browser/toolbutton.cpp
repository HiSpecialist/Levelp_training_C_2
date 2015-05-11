#include "toolbutton.h"

toolbutton::toolbutton(QWidget *parent) :
    QPushButton(parent)
{
    connect(this, SIGNAL(clicked()),
              parent, SLOT(on_historyTools_clicked()));

}
