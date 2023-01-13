#pragma once
#include "button.h"

class CheckBox : Button {
	const char* type;
	bool active = false;
public:
	void setActive(bool i);
	bool getActive();
	const char* getType();
	bool isActive();
	void draw();
	void update(graphics::MouseState ms);
	void init();
	CheckBox(float x, float y, float w, float h, const char t[], graphics::Brush br) : Button(x, y, w, h, br)
	{
		type = t;
	}
	~CheckBox(){}
};