#include <cassert>
#include <GL/glew.h>
#include "Renderer.h"

namespace renderer {

Renderer::Renderer(HWND hwnd)
    : hwnd_(hwnd)
{
    initialize();
}

void Renderer::initialize()
{
    initOpenGLContext();
    glewInit();
    glClearColor(0.f, 0.f, 0.f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

void Renderer::initOpenGLContext()
{
    hdc_ = GetDC(hwnd_);
    setPixelFormat();
    createOpenGLContext();
}

void Renderer::setPixelFormat()
{
    PIXELFORMATDESCRIPTOR pfd = {};
    ZeroMemory(&pfd, sizeof(pfd));
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.cStencilBits = 1;
    pfd.iLayerType = PFD_MAIN_PLANE;
    int format = ChoosePixelFormat(hdc_, &pfd);

    assert(format);
    BOOL success = SetPixelFormat(hdc_, format, &pfd);
    assert(success);
}

void Renderer::createOpenGLContext()
{
    hrc_ = wglCreateContext(hdc_);
    assert(hrc_);
    BOOL success = wglMakeCurrent(hdc_, hrc_);
    assert(success);
}

void Renderer::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, 10.0, -10.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(0.0, 1.0, 1.0);

    glBegin(GL_QUADS);
    glVertex3f(5.0, 5.0, -1.0);
    glVertex3f(-5.0, 5.0, -1.0);
    glVertex3f(-5.0, -5.0, -1.0);
    glVertex3f(5.0, -5.0, -1.0);
    glEnd();

    SwapBuffers(hdc_);
}

}
