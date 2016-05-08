#ifndef VIEW_H
#define VIEW_H

#include <windows.h>
#include <MainWindow.h>
#include <memory>

namespace ui {

class View
{
public:
    View() = default; 
    ~View() = default;

    static View* getInstance();
    static void freeInstance();

    void run();
    void stop();
    
private:
    static std::unique_ptr<View> instance_;

    MainWindow mainWindow_;
    bool isRunning_;

};

}
#endif // VIEW_H
