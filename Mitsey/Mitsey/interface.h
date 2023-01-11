#pragma once
#include "widget.h"
#include "button.h"
#include "slider.h"
#include "checkbox.h"
#include <iostream>
#include "movie.h"

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
};