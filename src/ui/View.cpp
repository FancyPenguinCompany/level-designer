#include "View.h"
#include "MessageHandler.h"

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

void View::freeInstance()
{
    instance_ = nullptr;
}

void View::run()
{
    isRunning_ = true;
    while (isRunning_)
    {
        MSG msg;
        PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE);
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void View::stop()
{
    isRunning_ = false;
}

}



