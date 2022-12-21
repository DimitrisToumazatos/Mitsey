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

void Button::setVisible(bool t)
{
	visible = t;
}

void Button::update(graphics::MouseState ms)
{
	float mx = graphics::windowToCanvasX((float)ms.cur_pos_x);
	float my = graphics::windowToCanvasY((float)ms.cur_pos_y);

	if (contains(mx, my))
	{
		setHighlighted(true);
		if (ms.button_left_pressed)
		{
			setActive(true);
		}
		else
		{
			setActive(false);

		}
	}
	else
	{
		setHighlighted(false);
	}
}

bool Button::getActive()
{
	return m_active;
}

void Button::draw()
{
	if (visible)
	{
		style.outline_opacity = .0f;
		if (m_highlighted)
		{
			style.outline_opacity = 1.0f;
		}

		graphics::drawRect(getPosX(), getPosY(), getW(), getH(), style);
	}
}

void Button::init()
{
}
