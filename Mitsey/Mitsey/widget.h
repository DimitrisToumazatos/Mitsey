#pragma once

#include "graphics.h"

class Widget
{
protected:
	float pos_x;
	float pos_y;
	float height;
	float width;
	graphics::Brush style;
public:
	virtual void setPosX(float x)=0;
	virtual void setPosY(float y) = 0;
	virtual void setH(float h) = 0;
	virtual void setW(float w) = 0;
	virtual void setStyle(graphics::Brush br) = 0;
	virtual float getPosX() = 0;
	virtual float getPosY() = 0;
	virtual float getH() = 0;
	virtual float getW() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void init() = 0;
	Widget() {}
	~Widget() {}
};
