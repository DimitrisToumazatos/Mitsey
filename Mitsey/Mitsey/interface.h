#pragma once
#include "widget.h"
#include "button.h"
#include "slider.h"

class Interface
{
	Button* b = nullptr;
	Button* m_active_button = nullptr;
	bool b_init = false;

	Slider* s = nullptr;
	bool s_init = false;
public:
	void init();
	void draw();
	void update();
	~Interface()
	{
		if (b) { delete b; }
		if (s) { delete s; }
	}
};