#include "interface.h"
#include "graphics.h"
#include "config.h"
#include "button.h"
#include "slider.h"
#include "checkbox.h"
#include <iostream>

void Interface::init()
{
	graphics::setFont(std::string(ASSET_PATH) + "RINGM.ttf");
	graphics::playMusic(std::string(ASSET_PATH) + "background-music.mp3", 0.2f, true, 2000);   // background music 
	graphics::Brush bru;
	bru.outline_opacity = .0f;

	bru.texture = std::string(ASSET_PATH) + "love-actually5.png";
	m[0] = new Movie("Love Actually", "2002", "Richard    Curtis", "Romance", "Alan    Rickman", "Hugh    Grant", bru);

	bru.texture = std::string(ASSET_PATH) + "star_wars.png";
	m[1] = new Movie("Star Wars: Episode V - The Empire Strikes Back", "1980", "Irvin	Kershner", "Sci-Fi", "Mark	 Hamill", "Harrison		Ford", bru);
	
	bru.texture = std::string(ASSET_PATH) + "Indiana_Jones.png";
	m[2] = new Movie("Indiana Jones and the Last Crusade", "1989", "Steven		Spielberg", "Adventure", "Harrison		Ford", "Sean	Connery", bru);
	
	bru.texture = std::string(ASSET_PATH) + "saw.png";
	m[3] = new Movie("Saw", "2004", "James		Wan", "Horror", "Cary	   	Elwes", "Cary		Elwes", bru);
	
	bru.texture = std::string(ASSET_PATH) + "shutter_island.png";
	m[4] = new Movie("Shutter Island", "2010", "Martin		Scorsese", "Drama", "Leonardo		 DiCaprio", "Mark		Ruffalo", bru);
	
	bru.texture = std::string(ASSET_PATH) + "this_is_the_end.png";
	m[5] = new Movie("This Is the End", "2013", "Seth		 Rogen", "Comedy", "James		 Franco", "Seth		 Rogen", bru);
	
	bru.texture = std::string(ASSET_PATH) + "insterstallar.png";
	m[6] = new Movie("Interstellar", "2014", "Christopher		 Nolan", "Sci-Fi", "Matthew			McConaughey", "Anne			Hathaway", bru);
	
	bru.texture = std::string(ASSET_PATH) + "titanic.png";
	m[7] = new Movie("Titanic", "1997", "James		 Cameron", "Drama", "Leonardo		 DiCaprio", "Kate		 Winslet", bru);
	
	bru.texture = std::string(ASSET_PATH) + "white_chicks.png";
	m[8] = new Movie("White Chicks", "2004", "Keenen		 Ivory		Wayans", "Comedy", "Marlon		Wayans", "Shawn		Wayans", bru);
	
	bru.texture = std::string(ASSET_PATH) + "pulp_fiction.png";
	m[9] = new Movie("Pulp Fiction", "1994", "Quentin		Tarantino", "Adveture", "John		Travolta", "Uma			Thurman", bru);
	
	bru.texture = std::string(ASSET_PATH) + "the_shining.png";
	m[10] = new Movie("The Shining", "1980", "Stanley		Kubrick", "Horror", "Jack		Nicholson", "Shelley		 Duvall", bru);

	bru.texture = std::string(ASSET_PATH) + "50_shades.png";
	m[11] = new Movie("Fifty Shades of Grey", "2015", "Sam		Taylor-Johnson", "Romance", "Dakota		 Johnson", "Jamie		Dornan", bru);
	
	m[0]->setVisible(true);
}

void Interface::draw()
{
	graphics::Brush br;

	br.fill_color[0] = 0.2f;
	br.fill_color[1] = 0.2f;
	br.fill_color[2] = 0.2f;

	br.outline_opacity = 0.f;
	graphics::drawRect(CANVAS_WIDTH/2, CANVAS_HEIGHT/2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	br.texture = std::string(ASSET_PATH) + "bar-shadow1.png";
	graphics::drawRect(CANVAS_WIDTH / 2, 82, CANVAS_WIDTH+300, 40, br);

	br.texture = "";

	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.2f;

	br.outline_opacity = 0.0;

	br.fill_opacity = 0.5f;

	graphics::drawRect(CANVAS_WIDTH/2, 40, CANVAS_WIDTH, 80, br);

	//if (b) { b->draw(); }
	for (int i = 0; i <= 11; i++) {	m[i]->draw();	}
	if (s1) { s1->draw(); }
	if (s2) { s2->draw(); }
	if (c_init) { for (int i = 0; i<=5; i++) c[i]->draw();	}

	
}

void Interface::update()
{
	graphics::MouseState ms;
	graphics::getMouseState(ms);

	/*if (!b_init && graphics::getGlobalTime() > 1000)
	{
		graphics::Brush br;
		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 0.5f;
		br.fill_color[2] = 0.5f;
		b = new Button(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, 100, 100, br);
		b_init = true;
	}

	if (b)
	{
		b->update(ms);
	}*/

	if (!s_init)
	{
		graphics::Brush br;
		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 0.5f;
		br.fill_color[2] = 0.0f;
		s1 = new Slider(CANVAS_WIDTH - 70, 40, 10, 10, 1980, 2015, "To:   ", br);
		s2 = new Slider(CANVAS_WIDTH - 200, 40, 10, 10, 1980, 2015,"From:   ", br);
		s_init = true;
	}

	if (s1 && s2)
	{
		s1->update(); 
		s2->update();
	}

	if (!c_init)
	{
		graphics::Brush br;
		br.fill_color[0] = 0.2f;
		br.fill_color[1] = 0.2f;
		br.fill_color[2] = 0.2f;
		c[0] = new CheckBox(40, 20, 70, 15, "Drama", br);
		c[1] = new CheckBox(120, 20, 70, 15, "Comedy", br);
		c[2] = new CheckBox(200, 20, 70, 15, "Adveture", br);
		c[3] = new CheckBox(40, 50, 70, 15, "Sci-Fi", br);
		c[4] = new CheckBox(120, 50, 70, 15, "Horror", br);
		c[5] = new CheckBox(200, 50, 70, 15, "Romance", br);
		c_init = true;
	}

	if (c_init)
	{
		for (int i = 0; i <= 5; i++) c[i]->update(ms);
	}
}