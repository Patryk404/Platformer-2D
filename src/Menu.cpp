#include "Menu.h"
#include <iostream>

Menu::Menu()
{
	font.loadFromFile("Text/Vanjar.ttf");
	menu_background.loadFromFile("Background/background.png");
	/*************************************/
	set_text(font, Title, "Classic Platformer", 640, 50);
	/*************************************/
	set_text(font, Start, "Play", 640, 350);
	/*************************************/
	set_text(font, Credits, "Credits", 640, 450);
	/*************************************/
	set_text(font, Exit, "Exit", 640, 550);
	/************************************/
	set_text(font, Author, "Patryk Kurek", 640, 400);
	/************************************/
	set_text(font, Exit_Button, "Back to menu", 150, 600);
	/************************************/
	set_text(font, Level1, "Level1", 240, 400);
	/************************************/
	set_text(font, Level2, "Level2", 600, 400);
	/************************************/
	set_text(font, Level3, "Level3", 1040, 400);
	/************************************/
	background.setTexture(menu_background);
	background.setScale(5, 5);
	background.setPosition(sf::Vector2f(-40, 0));
	circle.setRadius(2);
	buffer_menu.loadFromFile("Music/Menu.wav");
	Menu_music.setBuffer(buffer_menu);
	Menu_music.setVolume(25);
	Menu_music.setLoop(true);
	// Menu_music.play();
	buffer_lvl1.loadFromFile("Music/Level1.wav");
	lvl1.setBuffer(buffer_lvl1);
	lvl1.setVolume(25);
	lvl1.setLoop(true);
}
void Menu::draw_menu(sf::RenderWindow &window)
{
	if (credits == false && choose_level == false)
	{
		window.draw(background);
		window.draw(Title);
		window.draw(Start);
		window.draw(Credits);
		window.draw(Exit);
	}
	else if (credits == true && choose_level == false)
	{
		window.draw(background);
		window.draw(Author);
		window.draw(Exit_Button);
	}
	else if (credits == false && choose_level == true)
	{
		window.draw(background);
		window.draw(Level1);
		window.draw(Level2);
		window.draw(Level3);
		window.draw(Exit_Button);
	}
}
void Menu::set_text(sf::Font &font, sf::Text &text, std::string string, float position_x = 640, float position_y = 20)
{
	text.setFont(font);
	text.setString(string);
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::White);
	float iks = text.getGlobalBounds().width;
	float igrek = text.getGlobalBounds().height;
	iks /= 2;
	igrek /= 2;
	text.setOrigin(sf::Vector2f(iks, igrek));
	text.setPosition(sf::Vector2f(position_x, position_y));
}
void Menu::update_position(sf::RenderWindow &window)
{
	circle.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
}
void Menu::menu_colission(sf::RenderWindow &window, Map &map)
{
	sf::FloatRect Start_box = Start.getGlobalBounds();
	sf::FloatRect Credits_box = Credits.getGlobalBounds();
	sf::FloatRect Exit_box = Exit.getGlobalBounds();
	sf::FloatRect Circle_box = circle.getGlobalBounds();
	sf::FloatRect Exit_Button_box = Exit_Button.getGlobalBounds();
	/**************************************************/
	if (Circle_box.intersects(Start_box))
	{
		if (credits == false)
		{
			Start.setColor(sf::Color::Red);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				game = false;
				credits = false;
				choose_level = true;
				map.lvl1 = false;
				map.lvl2 = false;
				map.lvl3 = false;
				// lvl1.play();
			}
		}
	}
	else
	{
		Start.setColor(sf::Color::White);
	}
	/*************************************************/
	if (Circle_box.intersects(Credits_box))
	{
		Credits.setColor(sf::Color::Red);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			game = false;
			credits = true;
		}
	}
	else
	{
		Credits.setColor(sf::Color::White);
	}
	/**************************************************/
	if (Circle_box.intersects(Exit_box))
	{
		if (credits == false)
		{
			Exit.setColor(sf::Color::Red);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				window.close();
			}
		}
	}
	else
	{
		Exit.setColor(sf::Color::White);
	}
	/*************************************************/
	if (Circle_box.intersects(Exit_Button_box))
	{
		Exit_Button.setColor(sf::Color::Red);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			credits = false;
		}
	}
	else
	{
		Exit_Button.setColor(sf::Color::White);
	}
	/************************************************/
}
void Menu::menu_system(sf::RenderWindow &window, Map &map)
{
	menu_colission(window, map);
	update_position(window);
}
void Menu::choose_lvl_colission(sf::RenderWindow &window, bool &new_game, int &count_death, Map &map)
{
	sf::FloatRect Level1box = Level1.getGlobalBounds();
	sf::FloatRect Level2box = Level2.getGlobalBounds();
	sf::FloatRect Level3box = Level3.getGlobalBounds();
	sf::FloatRect Exit_Button_box = Exit_Button.getGlobalBounds();
	sf::FloatRect Circle_box = circle.getGlobalBounds();

	if (Circle_box.intersects(Level1box))
	{
		Level1.setColor(sf::Color::Red);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			new_game = true;
			game = false;
			map.lvl1 = true;
			choose_level = false;
		}
	}
	else
	{
		Level1.setColor(sf::Color::White);
	}
	/******************************************/
	if (Circle_box.intersects(Level2box))
	{
		Level2.setColor(sf::Color::Red);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			new_game = true;
			game = false;
			map.lvl2 = true;
			choose_level = false;
		}
	}
	else
	{
		Level2.setColor(sf::Color::White);
	}
	/******************************************/
	if (Circle_box.intersects(Level3box))
	{
		Level3.setColor(sf::Color::Red);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			new_game = true;
			game = false;
			map.lvl3 = true;
			choose_level = false;
		}
	}
	else
	{
		Level3.setColor(sf::Color::White);
	}
	/******************************************/
	if (Circle_box.intersects(Exit_Button_box))
	{
		Exit_Button.setColor(sf::Color::Red);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			choose_level = false;
			game = false;
		}
	}
	else
	{
		Exit_Button.setColor(sf::Color::White);
	}
}
