#include "MainWindow.h"
#include "MessageHandler.h"

namespace ui {

MainWindow::MainWindow()
{
    initialize();
}

void MainWindow::initialize()
{
    hInstance_ = GetModuleHandle(nullptr);
    WNDCLASSEX winClass = {};

    // Register window class
    winClass.cbSize = sizeof(WNDCLASSEX);
    winClass.style = CS_HREDRAW | CS_VREDRAW;
    winClass.lpfnWndProc = MessageHandler::getInstance()->handleMessage;
    winClass.hInstance = hInstance_;
    winClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
    winClass.lpszClassName = WINDOW_CLASS;
    RegisterClassEx(&winClass);

    // Adjust window dimensions.
    RECT winRect = {0, 0, INITIAL_WIDTH, INITIAL_HEIGHT};
    AdjustWindowRect(&winRect, WINDOW_STYLE, false);

    // Create the window
    hwnd_ = CreateWindowEx(WS_EX_APPWINDOW,
                           WINDOW_CLASS,
                           WINDOW_NAME,
                           WINDOW_STYLE,
                           0,
                           0,
                           winRect.right - winRect.left,
                           winRect.bottom - winRect.top,
                           nullptr,
                           nullptr,
                           hInstance_,
                           nullptr);
    SetForegroundWindow(hwnd_);
    SetWindowLongPtr(hwnd_, GWLP_USERDATA, (LONG_PTR)this);
}

}
