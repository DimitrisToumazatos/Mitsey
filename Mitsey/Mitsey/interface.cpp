#include "interface.h"
#include "graphics.h"
#include "config.h"
#include "button.h"
#include "slider.h"
#include "checkbox.h"
#include <iostream>
#include <list>
#include <iterator>

void Interface::init()
{
	graphics::setFont(std::string(ASSET_PATH) + "RINGM.ttf");
	//graphics::playMusic(std::string(ASSET_PATH) + "background-music.mp3", 0.2f, true, 2000);   // background music 
	graphics::Brush br;
	br.outline_opacity = .0f;

	// Initializing the movie library
	br.texture = std::string(ASSET_PATH) + "love-actually5.png";
	m[0] = new Movie("Love Actually", 2002, "Richard    Curtis", "Romance", "Alan    Rickman", "Hugh    Grant", br);

	br.texture = std::string(ASSET_PATH) + "star_wars.png";
	m[1] = new Movie("Star Wars: Episode V", 1980, "Irvin      Kershner", "Sci-Fi", "Mark      Hamill", "Harrison       Ford", br);
	
	br.texture = std::string(ASSET_PATH) + "Indiana_Jones.png";
	m[2] = new Movie("Indiana Jones III", 1989, "Steven       Spielberg", "Adventure", "Harrison       Ford", "Sean      Connery", br);
	
	br.texture = std::string(ASSET_PATH) + "saw.png";
	m[3] = new Movie("Saw", 2004, "James       Wan", "Horror", "Cary       Elwes", "Cary      Elwes", br);
	
	br.texture = std::string(ASSET_PATH) + "shutter_island.png";
	m[4] = new Movie("Shutter Island", 2010, "Martin       Scorsese", "Drama", "Leonardo      DiCaprio", "Mark      Ruffalo", br);
	
	br.texture = std::string(ASSET_PATH) + "this_is_the_end.png";
	m[5] = new Movie("This Is the End", 2013, "Seth       Rogen", "Comedy", "James       Franco", "Seth      Rogen", br);
	
	br.texture = std::string(ASSET_PATH) + "insterstallar.png";
	m[6] = new Movie("Interstellar", 2014, "Christopher       Nolan", "Sci-Fi", "Matthew       McConaughey", "Anne       Hathaway", br);
	
	br.texture = std::string(ASSET_PATH) + "titanic.png";
	m[7] = new Movie("Titanic", 1997, "James       Cameron", "Drama", "Leonardo       DiCaprio", "Kate       Winslet", br);
	
	br.texture = std::string(ASSET_PATH) + "white_chicks.png";
	m[8] = new Movie("White Chicks", 2004, "Keenen       Ivory       Wayans", "Comedy", "Marlon       Wayans", "Shawn       Wayans", br);
	
	br.texture = std::string(ASSET_PATH) + "pulp_fiction.png";
	m[9] = new Movie("Pulp Fiction", 1994, "Quentin       Tarantino", "Adventure", "John       Travolta", "Uma       Thurman", br);
	
	br.texture = std::string(ASSET_PATH) + "the_shining.png";
	m[10] = new Movie("The Shining", 1980, "Stanley       Kubrick", "Horror", "Jack       Nicholson", "Shelley       Duvall", br);

	br.texture = std::string(ASSET_PATH) + "50_shades.png";
	m[11] = new Movie("Fifty Shades of Grey", 2015, "Sam       Taylor-Johnson", "Romance", "Dakota       Johnson", "Jamie       Dornan", br);
	
	br.texture = "";

	// Initializing the two Sliders
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 0.5f;
	br.fill_color[2] = 0.0f;
	s[0] = new Slider(CANVAS_WIDTH - 70, 40, 10, 10, 1980, 2015, "To:   ", br);		// s[0] is the max date
	s[1] = new Slider(CANVAS_WIDTH - 200, 40, 10, 10, 1980, 2015, "From:   ", br);	// s[1] is the min date
	float temp = s[0]->getPosX();  
	s[0]->setPosX(temp + 50.f);		// set the starting position for each slider
	s[1]->setPosX(temp - 180.f);	

	// Initializing the six Check Boxes
	br.fill_color[0] = 0.2f;
	br.fill_color[1] = 0.2f;
	br.fill_color[2] = 0.2f;
	c[0] = new CheckBox(45, 20, 75, 15, "Drama", br);
	c[1] = new CheckBox(125, 20, 75, 15, "Comedy", br);
	c[2] = new CheckBox(205, 20, 75, 15, "Adventure", br);
	c[3] = new CheckBox(45, 50, 75, 15, "Sci-Fi", br);
	c[4] = new CheckBox(125, 50, 75, 15, "Horror", br);
	c[5] = new CheckBox(205, 50, 75, 15, "Romance", br);

	// Initializing the left and right button
	br.texture = std::string(ASSET_PATH) + "button-left.png";
	b[0] = new Button(CANVAS_WIDTH / 3 - 50, CANVAS_HEIGHT / 2 - 50, 50, 50, br);

	br.texture = std::string(ASSET_PATH) + "button-right.png";
	b[1] = new Button(CANVAS_WIDTH * 2 / 3 + 50, CANVAS_HEIGHT / 2 - 50, 50, 50, br);	
}

void Interface::draw()
{
	graphics::Brush br;

	br.fill_color[0] = 0.2f;
	br.fill_color[1] = 0.2f;
	br.fill_color[2] = 0.2f;

	// draw background
	br.outline_opacity = 0.f;
	graphics::drawRect(CANVAS_WIDTH/2, CANVAS_HEIGHT/2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	// draw the bar's shadow
	br.texture = std::string(ASSET_PATH) + "bar-shadow1.png";
	graphics::drawRect(CANVAS_WIDTH / 2, 82, CANVAS_WIDTH+300, 40, br);

	// draw the bar
	br.texture = "";
	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.2f;
	br.outline_opacity = 0.0;
	br.fill_opacity = 0.5f;

	graphics::drawRect(CANVAS_WIDTH/2, 40, CANVAS_WIDTH, 80, br);

	for (int i = 0; i <= 11; i++) {	m[i]->draw();	} // draw the visible movie 
	for (int i = 0; i <= 1; i++) { s[i]->draw(); }    // draw the sliders 
	for (int i = 0; i<=5; i++) c[i]->draw();		  // draw the check boxes	
	for (int i = 0; i <= 1; i++) { b[i]->draw(); }    // draw the sliders 
}

void Interface::update()
{
	graphics::MouseState ms;
	graphics::getMouseState(ms);

	for (int i = 0; i <= 1; i++) s[i]->update(ms);		// update the sliders' state
	for (int i = 0; i <= 5; i++) c[i]->update(ms);		// update the check boxes' state	

	std::list<Movie*> movies;							// makes the movie list
	bool flag = false;									// this variable checks if at least 1 checkbox is active 
	for (int i = 0; i <= 11; i++)
	{
		for (int j = 0; j <= 5; j++)
		{
			if (c[j]->getActive())
			{
				flag = true;
				// (ActiveCategory == MovieCategory) && (date <= maxDate) && (date >=minDate)
				if ((strcmp(m[i]->getType(), c[j]->getType()) == 0) && (m[i]->getDate() <= s[0]->getDate()) && (m[i]->getDate() >= s[1]->getDate()))
				{
					movies.push_back(m[i]);
				}
			}
		}

		if (!flag)		// case if no checkboxes are active 
		{
			// (date <= maxDate) && (date >=minDate)
			if ((m[i]->getDate() <= s[0]->getDate()) && (m[i]->getDate() >= s[1]->getDate()))
			{
				movies.push_back(m[i]);
			}
		}
		m[i]->setVisible(false); // set all movies as not visible
	}


	for (int i = 0; i <= 1; i++) b[i]->update(ms);		// update the buttons' state

	if (b[0]->getActive()) iter--;
	if (b[1]->getActive()) iter++;

	if (movies.size() >= 1)
	{
		std::list<Movie*>::iterator it;
		it = movies.begin();

		//if (iter == movies.size()) iter = 0;

		for (int j = 0; j < iter - 1; j++)
		{
			it++;
		}
		(*it)->setVisible(true);	// set a movie visible 

		b[0]->setVisible(false);
		b[1]->setVisible(true);
		if (it != movies.begin()) b[0]->setVisible(true);
		if (iter >= movies.size()) b[1]->setVisible(false);

	}
	else
	{
		graphics::Brush br;
		std::string text = "Sorry, no movie matches the given filters.";
		graphics::drawText(CANVAS_WIDTH / 4 + 5, CANVAS_HEIGHT / 2, 20, text, br);
		b[0]->setVisible(false);
		b[1]->setVisible(false);

	}
}