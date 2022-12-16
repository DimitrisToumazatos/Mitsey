#include "slider.h"
#include"graphics.h"
#include <cstdio>
#include "config.h"

void Slider::draw()
{
	graphics::drawRect(start_x, start_y, 100, 2, line);		// draw slider line
	char date_start[5];
	sprintf_s(date_start, "%d", min_date);
	char date_end[5];
	sprintf_s(date_end, "%d", max_date);
	char date_cur[15];
	sprintf_s(date_cur, "%s%d",name, cur_date);

	Button::draw();										// draw slider button

	graphics::Brush txt;
	graphics::drawText(min_x - 4, pos_y + 20, 13, date_start, txt);		// draw minimum date
	graphics::drawText(max_x - 22, pos_y + 20, 13, date_end, txt);		// draw maximum date
	graphics::drawText(min_x + 20, pos_y - 20, 13, date_cur, txt);		// draw maximum date



}

void Slider::init()
{
}

void Slider::update(graphics::MouseState ms)
{
	float mx = graphics::windowToCanvasX((float)ms.cur_pos_x);
	float my = graphics::windowToCanvasY((float)ms.cur_pos_y);

	if (contains(mx, my))
	{
		setHighlighted(true);
		if (ms.dragging)
		{
			setPosX(mx);
			if (pos_x < min_x)
			{
				pos_x = min_x;
			}
			else if (pos_x > max_x)
			{
				pos_x = max_x;
			}

		}
	}
	else
	{
		setHighlighted(false);
	}
	cur_date = static_cast<int>(std::round(min_date + ((pos_x - min_x) / 100.0f * (max_date - min_date))));
}

void Slider::setHighlighted(bool h)
{
	m_highlighted = h;
}

void Slider::setPosX(float f)
{
	Button::setPosX(f);
}

float Slider::getPosX()
{
	return Button::getPosX();
}