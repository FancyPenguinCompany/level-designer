#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <windows.h>
#include <memory>

namespace ui {

class Controller
{
public:
    Controller() = default;
    ~Controller() = default;
    static Controller* getInstance();
    static void freeInstance();

private:
    static std::unique_ptr<Controller> instance_;
};

}
#endif // MESSAGEHANDLER_H