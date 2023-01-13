#pragma once
//#include "widget.h"
//#include "button.h"
#include "slider.h"
#include "checkbox.h"
#include "movie.h"
#include <iostream>

class Interface
{
	Movie* m[12];
	Button* b[2];
	Slider * s[2];
	CheckBox* c[6];
	int iter = 0;
public:
	void init();
	void draw();
	void update();
	Interface(){}
	~Interface()
	{
		for (int i = 0; i < 11; i++)
		{
			delete m[i];
		}
		for (int i = 0; i < 1; i++)
		{
			delete b[i];
		}
		for (int i = 0; i < 1; i++)
		{
			delete s[i];
		}
		for (int i = 0; i < 5; i++)
		{
			delete c[i];
		}
	}

};