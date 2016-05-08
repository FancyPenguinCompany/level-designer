#ifndef RENDERER_H
#define RENDERER_H

namespace renderer {

class Renderer
{
public:
    Renderer() = default;
    ~Renderer() = default;

    void render();

private:
    void initialize();
};

}
#endif // RENDERER_H
