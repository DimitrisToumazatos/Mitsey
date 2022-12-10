#include "slider.h"
#include"graphics.h"

void Slider::draw()
{
	graphics::drawRect(pos_x, pos_y, 100, 2, line);
	Button::draw();
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