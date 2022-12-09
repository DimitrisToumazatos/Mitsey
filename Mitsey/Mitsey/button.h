#pragma once
#include "graphics.h"
#include "widget.h"

class Button : public Widget
{
protected:
	float pos_x;
	float pos_y;
	float height;
	float width;
	graphics::Brush style;
public:
	void setPosX(float x) override;
	void setPosY(float y) override;
	void setH(float h) override;
	void setW(float w) override;
	void setStyle(graphics::Brush br) override;
	float getPosX() override;
	float getPosY() override;
	float getH() override;
	float getW() override;
	void update() override;
	void draw() override;
	void init() override;
	Button(float x, float y, float h, float w, graphics::Brush br)
	{
		setPosX(x);
		setPosY(y);
		setH(h);
		setW(w);
		setStyle(br);
	}
	~Button()
	{
	}
};