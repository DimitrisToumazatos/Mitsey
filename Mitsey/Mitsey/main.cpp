#include "graphics.h"
#include "config.h"
#include "interface.h"

// The custom callback function that the library calls 
// to check for and set the current application state.
void update(float ms)
{
    Interface* mitsey = reinterpret_cast<Interface *>(graphics::getUserData());
    mitsey->update();
   
}

// The window content drawing function.
void draw()
{
    Interface* mitsey = reinterpret_cast<Interface*>(graphics::getUserData());
    mitsey->draw();
}


int main()
{   
    Interface mitsey;

    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Mitsey+");

    graphics::setUserData(&mitsey);

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);                 // (width, height)
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);             // CANVAS_SCALE_FIT == not streching the pixels

    mitsey.init();

    graphics::startMessageLoop();

    return 0;
}
