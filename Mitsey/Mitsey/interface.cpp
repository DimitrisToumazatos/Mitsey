#include "interface.h"
#include "graphics.h"
#include "config.h"

void Interface::init()
{
	graphics::playMusic(std::string(ASSET_PATH) + "background-music.mp3", 0.2f, true, 2000);   // background music 
}

void Interface::draw()
{
	graphics::Brush br;

	br.fill_color[0] = 0.2f;
	br.fill_color[1] = 0.2f;
	br.fill_color[2] = 0.2f;

	br.outline_opacity = 0.f;
	graphics::drawRect(CANVAS_WIDTH/2, CANVAS_HEIGHT/2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	br.texture = std::string(ASSET_PATH) + "bar-shadow1.png";
	graphics::drawRect(CANVAS_WIDTH / 2, 82, CANVAS_WIDTH+300, 40, br);

	br.texture = "";

	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.2f;

	br.outline_opacity = 0.0;

	br.fill_opacity = 0.5f;

	graphics::drawRect(CANVAS_WIDTH/2, 40, CANVAS_WIDTH, 80, br);
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
