#pragma once
#include "widget.h"
#include "button.h"
#include "slider.h"
#include "checkbox.h"
#include <iostream>
#include "movie.h"

class Interface
{
	//Button* b = nullptr;
	//Button* m_active_button = nullptr;
	//bool b_init = false;

	Movie* m[12];

	Slider * s1 = nullptr;
	Slider * s2= nullptr;
	bool s_init = false;

	CheckBox* c[6];
	bool c_init = false;
public:
	void init();
	void draw();
	void update();
	~Interface()
	{
		//if (b) { delete b; }
		delete s1;
		delete s2;
	}
};