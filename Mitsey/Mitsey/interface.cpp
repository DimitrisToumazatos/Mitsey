#include "interface.h"
#include "graphics.h"
#include "config.h"

void Interface::init()
{
}

void Interface::draw()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "cyan1.png";
	br.outline_opacity = 0.f;
	graphics::drawRect(CANVAS_WIDTH/2, CANVAS_HEIGHT/2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
}

void Interface::update()
{

}

Interface::Interface()
{
}

Interface::~Interface()
{
}
