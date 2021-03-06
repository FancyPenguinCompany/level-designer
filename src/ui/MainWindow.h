#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <windows.h>

class MessageHandler;

namespace ui {

class MainWindow
{
public:
    MainWindow();
    ~MainWindow() = default;

    inline HWND getHandle();

private:
    HINSTANCE hInstance_;
    HWND hwnd_;

    const char* WINDOW_CLASS = "WindowClass";
    const char* WINDOW_NAME = "Level Designer";

    static LRESULT CALLBACK handleMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    const DWORD WINDOW_STYLE = WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_VISIBLE | WS_OVERLAPPEDWINDOW;
    const int INITIAL_WIDTH = 800;
    const int INITIAL_HEIGHT = 600;

    void initialize();
};

inline HWND MainWindow::getHandle()
{
    return hwnd_;
}

}

#endif // MAINWINDOW_H
