#include "movie.h"
#include "config.h"
void Movie::draw()
{
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, 256, 256, img);
	graphics::drawText(40,CANVAS_HEIGHT * 2.0f / 3.0f, 25, name, img);
	graphics::drawText(40, CANVAS_HEIGHT * 2.0f / 3.0f + 40, 10, text0, img );
	graphics::drawText(40, CANVAS_HEIGHT * 2.0f / 3.0f + 60, 10, text1, img);
	graphics::drawText(40, CANVAS_HEIGHT * 2.0f / 3.0f + 80, 10, text2, img);
	graphics::drawText(40, CANVAS_HEIGHT * 2.0f / 3.0f + 100, 10, text3, img);

};
void Movie::init() 
{
};
