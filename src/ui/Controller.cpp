#include "Controller.h"

namespace ui {

std::unique_ptr<Controller> Controller::instance_ = nullptr;

Controller* Controller::getInstance()
{
    if (instance_ == nullptr)
    {
        instance_ = std::unique_ptr<Controller>(new Controller());
    }
    return instance_.get();
}

void Controller::freeInstance()
{
    instance_ = nullptr;
}

} // namespace ui
