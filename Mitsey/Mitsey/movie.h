#pragma once
#include <iostream>
#include "graphics.h"

class Movie {
	const char* name;
	const char* date;
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
	Movie(const char n[], const char d[], const char dir[], const char t[], const char a0[], const char a1[], graphics::Brush i)
	{
		name = n;
		date = d;
		director = dir;
		type = t;
		actor0 = a0;
		actor1 = a1;
		img = i;
		sprintf_s(text0, "Category:   %s", *(std::string*)type);
		sprintf_s(text1, "Director:    %s", *(std::string*)director);
		sprintf_s(text2, "Stars:                 %s,    %s", *(std::string*)actor0, *(std::string*)actor1);
		sprintf_s(text3, "Year:                    %s", *(std::string*)date);
	};
	void setVisible(bool v)
	{
		visible = v;
	}
	~Movie();
    void draw();
	void init();
};