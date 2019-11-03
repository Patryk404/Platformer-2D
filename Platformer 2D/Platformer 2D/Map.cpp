#include "map.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include <vector>
void Map::dont_draw_enemy()
{
	for (int i = 0; i < number_of_enemies; i++)
	{
		if (player1.enemy_be[i]==true&&enemy1[i]->death==true)
		{
			be_enemy[i] = false;
			player1.enemy_be[i] = false;
			delete enemy1[i];
			enemy1[i] = NULL;
		}
	}
}
void Map::Make_level1()
{
		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 30; x++)
			{
				if (level1[y][x] == 1)
				{
					/*sf::Sprite Platform(plat);
					Platform.setScale(sf::Vector2f(0.2f, 0.2f));
					Platform.setPosition(sf::Vector2f((float)position_x,(float) position_y));
					window.draw(Platform);
					/*****************************/
					/****************************************///enemy colission of enemy is in function player1.collision();
					/*engine(player1, enemy1, Platform);*/
					number_platforms++;
				}
				else if (level1[y][x] == 2)
				{
					number_of_invisible_walls++;
				}
				else if (level1[y][x] == 3)
				{
					number_of_spikes++;
				}
				else if (level1[y][x] == 5)
				{
					number_of_portals++;
				}
			}
		}
		/*********************************************************/
		std::cout <<"Platforms: "<< number_platforms << std::endl;//real platforms
		sf::Sprite *Text_plat = new sf::Sprite[number_platforms];
		for (int i = 0; i < number_platforms; i++,*Text_plat++)
		{
			Text_plat->setTexture(plat);
			Text_plat->setScale(sf::Vector2f(0.2f, 0.2f));
			Real_platforms.push_back(*Text_plat);
		}
		/*********************************************************/
		std::cout <<"Walls: "<< number_of_invisible_walls << std::endl;//invisible walls
		sf::RectangleShape *Text_invisible_walls = new sf::RectangleShape[number_of_invisible_walls];
		for (int i = 0; i < number_of_invisible_walls; i++, *Text_invisible_walls++)
		{
			Text_invisible_walls->setSize(sf::Vector2f(102.4f, 102.4f));
			Invisible_walls.push_back(*Text_invisible_walls);
		}
		/*******************************************************/
		std::cout << "Spikes: " << number_of_spikes << std::endl;// spikes
		sf::Sprite *Text_spike = new sf::Sprite[number_of_spikes];
		for (int i = 0; i < number_of_spikes; i++, *Text_spike++)
		{
			Text_spike->setTexture(Spike);
			Text_spike->setScale(sf::Vector2f(0.2f, 0.2f));
			Spikes.push_back(*Text_spike);
		}
		/*******************************************************/
		std::cout << "Portals: " << number_of_portals << std::endl;//portals
		sf::Sprite *Text_portal = new sf::Sprite[number_of_portals];
		for (int i = 0; i < number_of_portals; i++, *Text_portal++)
		{
			Text_portal->setTexture(Portal_txt);
			Text_portal->setScale(sf::Vector2f(0.2f, 0.2f));
			Portals.push_back(*Text_portal);
		}
		/*******************************************************/
		number_of_invisible_walls = 0;
		number_platforms = 0;
		number_of_spikes = 0; 
		number_of_portals = 0;
		double position_x = 0;
		double position_y = 0;
		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 30; x++)
			{
				if (level1[y][x] == 1)
				{
					Real_platforms[number_platforms].setPosition(sf::Vector2f(position_x, position_y));
					number_platforms++;
				}
				else if (level1[y][x] == 2)
				{
					Invisible_walls[number_of_invisible_walls].setPosition(sf::Vector2f(position_x, position_y));
					number_of_invisible_walls++;
				}
				else if (level1[y][x] == 3)
				{
					Spikes[number_of_spikes].setPosition(sf::Vector2f(position_x, position_y));
					number_of_spikes++;
				}
				else if (level1[y][x] == 4)
				{
					player1.start_pos_x = position_x;
					player1.start_pos_y = position_y;
				}
				else if (level1[y][x] == 5)
				{
					Portals[number_of_portals].setPosition(sf::Vector2f(position_x, position_y));
					number_of_portals++;
				}
				position_x += 100;
			}
			position_x = 0;
			position_y += 100;
		}
		//////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////
}
Map::Map()
{
	plat.loadFromFile("World//Grass.png");
	Spike.loadFromFile("World//Spike.png");
	Portal_txt.loadFromFile("World//Portal.png");
	enemy1[0] = new Enemy;
	enemy1[1] = new Enemy;
	text_background.loadFromFile("Background//background_game.png");
	background.setTexture(text_background);
	background.setScale(5, 5);
	background.setPosition(sf::Vector2f(-400.f, -600.f));
	////////////////////////////////////////////////////
	enemy1[0]->Enemy_sp.setPosition(sf::Vector2f(900, 575));//seting position of enemy[0]
	enemy1[1]->Enemy_sp.setPosition(sf::Vector2f(900, 200));//seting position of enemy[1]
	///////////////////////////////////////////////////
	be_enemy[0] = true;
	be_enemy[1] = true;
}
void Map::engine(Player &player1, Enemy *enemy1[], std::vector <sf::Sprite> &Platform, std::vector <sf::RectangleShape> &Wall, std::vector<sf::Sprite> &Spikes, sf::View &camera)
{
	for (int i = 0; i < number_of_enemies; i++)
	{
		if (be_enemy[i] == true)
		{
			if (enemy1[i]->movingbo == true)
			{
				enemy1[i]->moving();
			}
			enemy1[i]->update_position_rect();
			if (enemy1[i]->gravitationbo == true)
			{
				enemy1[i]->gravitation();
			}
			if (enemy1[i]->knockbackbo == true)
			{
				if (enemy1[i]->knockleft == true)
				{
					enemy1[i]->knockbackleft();
				}
				else if (enemy1[i]->knockright == true)
				{
					enemy1[i]->knockbackright();
				}
				enemy1[i]->Enemy_sp.setColor(sf::Color::Red);
				enemy1[i]->knockback_steps++;
				enemy1[i]->anim = false;
				if (enemy1[i]->knockback_steps > 15)
				{
					enemy1[i]->life -= 25;
					enemy1[i]->knockback_steps = 0;
					enemy1[i]->knockbackbo = false;
					enemy1[i]->gravitationbo = true;
					enemy1[i]->knockleft = false;
					enemy1[i]->knockright = false;
				}
			}
			if (enemy1[i]->death == false)
			{
				enemy1[i]->checklife();
			}
			if (enemy1[i]->death == true)
			{
				dont_draw_enemy();
			}
		}
	}
	/****************************/ //this must be in this function because this is not working in main lol
	player1.colission(Platform,number_platforms,Wall,number_of_invisible_walls,Spikes,number_of_spikes,enemy1,number_of_enemies,camera);//enemy colission and everything with what collide player 
	/*****************************************************************************************************/
	if (set_player1 == 0)
	{
		player1.Player_box->setPosition(sf::Vector2f(player1.start_pos_x, player1.start_pos_y));
		set_player1++;
		camera.setCenter(player1.Player_box->getPosition().x, player1.Player_box->getPosition().y);
	}
	/*****************************************************************************************************///this if do only one time because this set camera and position of player lol 
	if (player1.gravitationbo == true)
	{
		player1.gravitation();
	}
	player1.Update_position_circle();
	if (player1.able == true)
	{
		player1.movement();
	}
	if (player1.jumping == true)
	{
		player1.jump();
	}
	if (player1.knockback == true && player1.death == false)
	{
		player1.knockback_fun();
		player1.Player_box->setColor(sf::Color::Red);
		player1.knockback_steps++;
		if (player1.knockback_steps == 1)
		{
			player1.life -= 25;
		}
		if (player1.knockback_steps > 15)
		{
			player1.knockback_steps = 0;
			player1.knockback = false;
			player1.colissionb = true;
			player1.gravitationbo = true;
			player1.upper = false;
			player1.rightr = false;
			player1.knockknock = rand() % 2 + 1;
		}
	}
	sf::FloatRect Player_Box[4];
	for (int i = 0; i < 4; i++)
	{
		Player_Box[i] = player1.circle[i].getGlobalBounds();
	}
	player1.check_life();
	/********************************************************/
}
