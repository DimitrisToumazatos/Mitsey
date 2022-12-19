#pragma once
#include "button.h"
#include "graphics.h"
#include <iostream>

class Slider : Button
{
	int max_date;
	int min_date;
	int cur_date;
	float max_x;
	float min_x;
	float start_x;
	float start_y;
	std::string name;
	graphics::Brush line;
	
public:
	void draw();
	void init();
	void update(graphics::MouseState ms);
	void setHighlighted(bool h);
	void setPosX(float f);
	int getDate();
	float getPosX() override;
	Slider();
	Slider(float x, float y, float w, float h, int min_d, int max_d, std::string n, graphics::Brush br) :  Button(x, y, w, h, br)
	{
		min_date = min_d;
		max_date = max_d;
		min_x = x - 50.0f;
		max_x = x + 50.0f;
		name = n;
		cur_date = static_cast<int>(std::round(min_date + ((pos_x - min_x) / 100.0f * (max_date - min_date))));
		start_x = x;
		start_y = y;
		line.fill_color[0] = 1.0f;
		line.fill_color[1] = 1.0f;
		line.fill_color[2] = 1.0f;
	}
};
