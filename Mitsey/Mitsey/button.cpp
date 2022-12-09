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
	graphics::drawRect(getPosX(), getPosY(), getH(), getW(), style);
}

void Button::init()
{
}
