#include "checkbox.h"
#include "config.h"

void CheckBox::setActive(bool i)
{
	active = i;
}

bool CheckBox::getActive()
{
	return active;
}

const char* CheckBox::getType()
{
	return type;
}

bool CheckBox::isActive()
{
	return active;
}

void CheckBox::draw()
{
	Button::draw();
	char cat[15];
	sprintf_s(cat, "%s", type);
	graphics::Brush txt;
	graphics::setFont(std::string(ASSET_PATH) + "RINGM.ttf");
	graphics::drawText(pos_x - width/3, pos_y + height/8, 10, cat, txt);
}

void CheckBox::update(graphics::MouseState ms)
{
	float mx = graphics::windowToCanvasX((float)ms.cur_pos_x);
	float my = graphics::windowToCanvasY((float)ms.cur_pos_y);

	if (contains(mx, my) && ms.button_left_pressed)
	{
		setActive(!isActive());
	}

	if (contains(mx, my))
	{
		setHighlighted(true);	
	}
	else
	{
		setHighlighted(isActive());
	}
}

void CheckBox::init()
{
}
