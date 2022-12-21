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
	bool m_highlighted = false;
	bool m_active = false;
	bool visible = true;
public:
	void setPosX(float x) override;
	void setPosY(float y) override;
	void setH(float h) override;
	void setW(float w) override;
	void setStyle(graphics::Brush br) override;
	void setHighlighted(bool h);
	void setActive(bool h);
	void setVisible(bool t);
	float getPosX() override;
	float getPosY() override;
	float getH() override;
	float getW() override;
	bool getActive();
	void update(graphics::MouseState ms) override;
	void draw() override;
	void init() override;
	virtual bool contains(float x, float y);
	Button(float x, float y, float w, float h, graphics::Brush br)
	{
		setPosX(x);
		setPosY(y);
		setH(h);
		setW(w);
		setStyle(br);
	}
};