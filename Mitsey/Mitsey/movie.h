#pragma once
#include "graphics.h"
#include <iostream>

class Movie {
	int date;
	const char* name;
	const char* director;
	const char* type;
	const char* actor0;
	const char* actor1;
	bool visible = false;
	graphics::Brush img;
	char text0[100];
	char text1[100];
	char text2[100];
	char text3[100];

public:
	int getDate();
	bool getVisible();
	const char* getType();
	void setVisible(bool v);
	void draw();
	void init();
	Movie(const char n[], int d, const char dir[], const char t[], const char a0[], const char a1[], graphics::Brush i)
	{
		name = n;
		date = d;
		director = dir;
		type = t;
		actor0 = a0;
		actor1 = a1;
		img = i;

		sprintf_s(text0, "Category:   %s", type);
		sprintf_s(text1, "Director:    %s", director);
		sprintf_s(text2, "Stars:                 %s,    %s", actor0, actor1);
		sprintf_s(text3, "Year:                    %d", date);
	}
	Movie();
	~Movie() {}
};