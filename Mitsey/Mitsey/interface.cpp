#include "interface.h"
#include "graphics.h"
#include "config.h"
#include "button.h"
#include "slider.h"
#include "checkbox.h"
#include <iostream>

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

	if (b) { b->draw(); }
	if (s1) { s1->draw(); }
	if (s2) { s2->draw(); }
	if (c_init)
	{ for (int i = 0; i<=5; i++) c[i]->draw();
	}

	
}

void Interface::update()
{
	graphics::MouseState ms;
	graphics::getMouseState(ms);

	if (!b_init && graphics::getGlobalTime() > 1000)
	{
		graphics::Brush br;
		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 0.5f;
		br.fill_color[2] = 0.5f;
		b = new Button(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, 100, 100, br);
		b_init = true;
	}

	if (b)
	{
		b->update(ms);
	}

	if (!s_init && graphics::getGlobalTime() > 1000)
	{
		graphics::Brush br;
		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 0.5f;
		br.fill_color[2] = 0.0f;
		s1 = new Slider(CANVAS_WIDTH - 70, 40, 10, 10, 2000, 2010, "To:   ", br);		
		s2 = new Slider(CANVAS_WIDTH - 200, 40, 10, 10, 2000, 2010,"From:   ", br);
		s_init = true;
	}

	if (s1 && s2)
	{
		s1->update(); 
		s2->update();
	}

	if (!c_init && graphics::getGlobalTime() > 1000)
	{
		graphics::Brush br;
		br.fill_color[0] = 0.2f;
		br.fill_color[1] = 0.2f;
		br.fill_color[2] = 0.2f;
		c[0] = new CheckBox(40, 20, 70, 15, "Drama", br);
		c[1] = new CheckBox(120, 20, 70, 15, "Comedy", br);
		c[2] = new CheckBox(200, 20, 70, 15, "Adveture", br);
		c[3] = new CheckBox(40, 50, 70, 15, "Sci-Fi", br);
		c[4] = new CheckBox(120, 50, 70, 15, "Horror", br);
		c[5] = new CheckBox(200, 50, 70, 15, "Romance", br);
		c_init = true;
	}

	if (c_init)
	{
		for (int i = 0; i <= 5; i++) c[i]->update(ms);
	}
}