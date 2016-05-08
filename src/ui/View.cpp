#include "View.h"

namespace ui {

std::unique_ptr<View> View::instance_ = nullptr;

View* View::getInstance()
{
    if (instance_ == nullptr)
    {
        instance_ = std::unique_ptr<View>(new View());
    }
    return instance_.get();
}

View::View()
    : renderer_(mainWindow_.getHandle())
{
}

void View::freeInstance()
{
    instance_ = nullptr;
}

void View::run()
{
    isRunning_ = true;
    while (isRunning_)
    {
        querryMessages();
        renderer_.render();
    }
}

void View::querryMessages()
{
    MSG msg;
    PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE);
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}

void View::stop()
{
    isRunning_ = false;
}

}