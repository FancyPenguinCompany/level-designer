#ifndef VIEW_H
#define VIEW_H

#include <windows.h>
#include <MainWindow.h>
#include <memory>
#include "Renderer.h"

namespace ui {

class View
{
public:
    View(); 
    ~View() = default;

    static View* getInstance();
    static void freeInstance();

    inline HWND getMainWindowHandle();

    void run();
    void stop();
    
private:
    static std::unique_ptr<View> instance_;

    MainWindow mainWindow_;
    renderer::Renderer renderer_;
    bool isRunning_;

    void querryMessages();

};

inline HWND View::getMainWindowHandle()
{
    return mainWindow_.getHandle();
}

}
#endif // VIEW_H
