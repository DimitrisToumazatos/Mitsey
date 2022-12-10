#include "button.h"
#include "widget.h"

void Button::setPosX(float x)
{
	pos_x = x;
}

void Button::setPosY(float y)
{
	pos_y = y;
}

void Button::setH(float h)
{
	height = h;
}

void Button::setW(float w)
{
	width = w;
}

void Button::setStyle(graphics::Brush br)
{
	style = br;
}

void Button::setHighlighted(bool h) 
{
	m_highlighted = h;
}

void Button::setActive(bool h)
{
	m_active = h;
}

bool Button::contains(float x, float y)
{
	return (x < pos_x + width / 2) && (x > pos_x - width / 2) && (y < pos_y + height / 2) && (y > pos_y - height / 2);
}

float Button::getPosX()
{
	return pos_x;
}

float Button::getPosY()
{
	return pos_y;
}

float Button::getH()
{
	return height;
}

float Button::getW()
{
	return width;
}

void Button::update()
{

}

void Button::draw()
{
	style.outline_opacity = .0f;
	if (m_highlighted)
	{
		style.outline_opacity = 1.0f;
	}

	graphics::drawRect(getPosX(), getPosY(), getH(), getW(), style);
}

void Button::init()
{
}
