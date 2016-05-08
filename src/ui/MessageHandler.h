#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <windows.h>
#include <memory>

namespace ui {

class MessageHandler
{
public:
    MessageHandler() = default;
    ~MessageHandler() = default;
    static MessageHandler* getInstance();
    static void freeInstance();
    static LRESULT CALLBACK handleMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
    static std::unique_ptr<MessageHandler> instance_;
};

}
#endif // MESSAGEHANDLER_H