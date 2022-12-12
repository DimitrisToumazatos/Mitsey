#pragma once
#include "button.h"

class CheckBox : Button {
	std::string type;
	bool active = false;
public:
	CheckBox(float x, float y, float w, float h, std::string t, graphics::Brush br) : Button(x, y, w, h, br)
	{
		type = t;
	}
	~CheckBox();
	void setActive(bool i);
	bool isActive();
	void draw();
	void update(graphics::MouseState ms);
	void init();
};