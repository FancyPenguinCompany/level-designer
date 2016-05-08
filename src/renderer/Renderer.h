#ifndef RENDERER_H
#define RENDERER_H

#include <windows.h>

namespace renderer {

class Renderer
{
public:
    Renderer(HWND hwnd);
    ~Renderer() = default;

    void render();

private:
    Renderer() = default;

    void initialize();
    void initOpenGLContext();
    void setPixelFormat();
    void createOpenGLContext();

    HWND hwnd_;
    HDC hdc_;
    HGLRC hrc_;
};

}
#endif // RENDERER_H
