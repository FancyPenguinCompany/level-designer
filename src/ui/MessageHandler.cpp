#include "View.h"

#include "MessageHandler.h"

namespace ui {

std::unique_ptr<MessageHandler> MessageHandler::instance_ = nullptr;

MessageHandler* MessageHandler::getInstance()
{
    if (instance_ == nullptr)
    {
        instance_ = std::unique_ptr<MessageHandler>(new MessageHandler());
    }
    return instance_.get();
}

void MessageHandler::freeInstance()
{
    instance_ = nullptr;
}

LRESULT CALLBACK MessageHandler::handleMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;

    switch (uMsg)
    {
    case WM_DESTROY:
        View::getInstance()->stop();

    default:
        result = DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return result;
}

} // namespace ui
