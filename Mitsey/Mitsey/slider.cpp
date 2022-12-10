#include "slider.h"
#include"graphics.h"
#include <cstdio>
#include "config.h"

void Slider::draw()
{
	graphics::drawRect(pos_x, pos_y, 100, 2, line);		// draw slider line
	char date_start[5];
	sprintf_s(date_start, "%d", min_date);
	char date_end[5];
	sprintf_s(date_end, "%d", max_date);
	char date_cur[15];
	sprintf_s(date_cur, "%s%d",name, cur_date);

	Button::draw();										// draw slider button

	graphics::Brush txt;
	graphics::setFont(std::string(ASSET_PATH) + "RINGM.ttf");
	graphics::drawText(min_x - 4, pos_y + 20, 13, date_start, txt);		// draw minimum date
	graphics::drawText(max_x - 22, pos_y + 20, 13, date_end, txt);		// draw maximum date
	graphics::drawText(min_x + 20, pos_y - 20, 13, date_cur, txt);		// draw maximum date



}

void Slider::init()
{
}

void Slider::update()
{

}

bool Slider::contains(float x, float y)
{
	return Button::contains(x, y);
}

void Slider::setHighlighted(bool h)
{
	Button::m_highlighted = h;
}