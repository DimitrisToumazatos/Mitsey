#pragma once
#include "button.h"

class Interface
{
	Button* b = nullptr;
	bool b_init = false;
public:
	void init();
	void draw();
	void update();
	Interface();
	~Interface();
};