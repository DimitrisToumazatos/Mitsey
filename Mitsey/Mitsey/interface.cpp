#include "interface.h"
#include "graphics.h"
#include "config.h"
#include "button.h"
#include "slider.h"

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
	
}

void Interface::update()
{
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
		graphics::MouseState ms;
		graphics::getMouseState(ms);

		float mx = graphics::windowToCanvasX((float)ms.cur_pos_x);
		float my = graphics::windowToCanvasY((float)ms.cur_pos_y);
		b->update();

		Button* curr_button = nullptr;
		if (b->contains(mx, my))
		{
			b->setHighlighted(true);
			curr_button = b;
		}
		else
		{
			b->setHighlighted(false);
		}
		//if (m_active_button) m_active_button->setActive(false);
		if (ms.button_left_pressed && curr_button)
		{
			m_active_button = curr_button;
			m_active_button->setActive(true);
		}

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
		graphics::MouseState ms;
		graphics::getMouseState(ms);

		float mx = graphics::windowToCanvasX((float)ms.cur_pos_x);
		float my = graphics::windowToCanvasY((float)ms.cur_pos_y);
		s1->update();

		Button* curr_button = nullptr;
		if (s1->contains(mx, my))
		{
			s1->setHighlighted(true);
		}
		else
		{
			s1->setHighlighted(false);
		}

		s2->update();

		curr_button = nullptr;
		if (s2->contains(mx, my))
		{
			s2->setHighlighted(true);
		}
		else
		{
			s2->setHighlighted(false);
		}
	}
}