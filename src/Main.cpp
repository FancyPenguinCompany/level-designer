#include <cassert>
#include <memory>
#include "View.h"

int main()
{
    ui::View* view = ui::View::getInstance();
    assert(view != nullptr);
    view->run();
    ui::View::freeInstance();
}