#include <memory>
#include "View.h"
#include "MessageHandler.h"

int main()
{
    ui::View::getInstance()->run();
    ui::View::freeInstance();
    ui::MessageHandler::freeInstance();
}