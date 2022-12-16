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

	Button* b[2];

	Slider * s[2];

	CheckBox* c[6];
public:
	void init();
	void draw();
	void update();
	~Interface()
	{
		//if (b) { delete b; }
		//delete [] s;
		//delete [] c;
		//delete [] m;
		//delete [] b;
	}
};