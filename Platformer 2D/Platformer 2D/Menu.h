#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "map.h"
class Menu
{
public:
	bool game = false;
	bool credits = false; 
	bool choose_level = false;
	/********************///menu
	sf::Text Start;
	sf::Text Title; 
	sf::Text Exit;
	sf::Text Credits;
	sf::Text Author;
	sf::Text Exit_Button;
	/********************/
	sf::Text Level1;
	sf::Text Level2;
	sf::Text Level3;
	/********************/
	sf::Sprite background;
	sf::Sound Menu_music;
	sf::Sound lvl1;
	Menu();
	void draw_menu(sf::RenderWindow &window);
	void update_position(sf::RenderWindow &window);
	void menu_system(sf::RenderWindow &window);
	void choose_lvl_colission(sf::RenderWindow &window);
	int beka;
private:
	sf::Font font;
	sf::CircleShape circle;
	sf::Texture menu_background;
	sf::SoundBuffer buffer_menu;
	sf::SoundBuffer buffer_lvl1;
	void menu_colission(sf::RenderWindow &window);
	void set_text(sf::Font &font, sf::Text &text, std::string string, float position_x, float position_y);
};

