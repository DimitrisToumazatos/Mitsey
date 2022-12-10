#pragma once
#include "widget.h"
#include "button.h"
#include "slider.h"

class Interface
{
	Button* b = nullptr;
	Button* m_active_button = nullptr;
	bool b_init = false;

	Slider * s1 = nullptr;
	Slider * s2= nullptr;

	bool s_init = false;
public:
	void init();
	void draw();
	void update();
	~Interface()
	{
		if (b) { delete b; }
		delete s1;
		delete s2;
	}
};