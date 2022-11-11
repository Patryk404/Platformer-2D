#include "Map.h"
#include <iostream>
#include <vector>
void Map::dont_draw_enemy()
{
	for (int i = 0; i < number_of_enemies; i++)
	{
		if (Enemies[i].death == true)
		{
			Enemies[i].be = false; 
		}
	}
}

void Map::restart()
{
	plat.loadFromFile("World/Grass.png");
	Spike.loadFromFile("World/Spike.png");
	Portal_txt.loadFromFile("World/Portal.png");
	text_background.loadFromFile("Background/background_game.png");
	background.setTexture(text_background);
	background.setScale(5, 5);
	background.setPosition(sf::Vector2f(-400.f, -600.f));
	number_of_enemies = 0;
} 

void Map::Make_level1()
{
	int x, y;
	lvl1 = false;
	lvl2 = false;
	lvl3 = false;
	number_of_portals = 0;
	number_of_spikes = 0;
	number_platforms = 0;
	number_of_invisible_walls = 0;
	number_of_enemies = 0;
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
				else if (level1[y][x] == 6)
				{
					number_of_enemies++;
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
		std::cout << "Enemies: " << number_of_enemies << std::endl;
		Enemy *Text_Enemy = new Enemy[number_of_enemies];
		for (int i = 0; i < number_of_enemies; i++,*Text_Enemy++)
		{
			Enemies.push_back(*Text_Enemy);
			be_enemy.push_back(true);
		}
		/*******************************************************/
		std::cout << "Portals: " << number_of_portals << std::endl;//portals
		sf::Sprite *Text_portal = new sf::Sprite[number_of_portals];
		for (int i = 0; i < number_of_portals; i++, *Text_portal++)
		{
			Text_portal->setTexture(Portal_txt);
			x=Text_portal->getGlobalBounds().width;
			y = Text_portal->getGlobalBounds().height;
			x /= 2;
			y /= 2;
			Text_portal->setOrigin(x, y);
			Text_portal->setScale(sf::Vector2f(0.3f, 0.5f));
			Portals.push_back(*Text_portal);
		}
		/*******************************************************/
		number_of_invisible_walls = 0;
		number_platforms = 0;
		number_of_spikes = 0; 
		number_of_portals = 0;
		number_of_enemies = 0;
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
				else if (level1[y][x] == 6)
				{
					Enemies[number_of_enemies].Enemy_sp.setPosition(sf::Vector2f(position_x, position_y));
					number_of_enemies++;
				}
				position_x += 100;
			}
			position_x = 0;
			position_y += 100;
		}
		lvl1 = true;
		//////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////
}
void Map::Make_level2()
{
	int x, y;
	lvl1 = false;
	lvl2 = false;
	lvl3 = false;
	number_of_portals = 0;
	number_of_spikes = 0;
	number_platforms = 0;
	number_of_invisible_walls = 0;
	number_of_enemies = 0;
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 30; x++)
		{
			if (level2[y][x] == 1)
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
			else if (level2[y][x] == 2)
			{
				number_of_invisible_walls++;
			}
			else if (level2[y][x] == 3)
			{
				number_of_spikes++;
			}
			else if (level2[y][x] == 5)
			{
				number_of_portals++;
			}
			else if (level2[y][x] == 6)
			{
				number_of_enemies++;
			}
		}
	}
	/*********************************************************/
	std::cout << "Platforms: " << number_platforms << std::endl;//real platforms
	sf::Sprite *Text_plat = new sf::Sprite[number_platforms];
	for (int i = 0; i < number_platforms; i++, *Text_plat++)
	{
		Text_plat->setTexture(plat);
		Text_plat->setScale(sf::Vector2f(0.2f, 0.2f));
		Real_platforms.push_back(*Text_plat);
	}
	/*********************************************************/
	std::cout << "Walls: " << number_of_invisible_walls << std::endl;//invisible walls
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
	/******************************************************/
	std::cout << "Enemies: " << number_of_enemies << std::endl;
	Enemy *Text_Enemy = new Enemy[number_of_enemies];
	for (int i = 0; i < number_of_enemies; i++, *Text_Enemy++)
	{
		Enemies.push_back(*Text_Enemy);
		be_enemy.push_back(true);
	}
	/*******************************************************/
	std::cout << "Portals: " << number_of_portals << std::endl;//portals
	sf::Sprite *Text_portal = new sf::Sprite[number_of_portals];
	for (int i = 0; i < number_of_portals; i++, *Text_portal++)
	{
		Text_portal->setTexture(Portal_txt);
		x = Text_portal->getGlobalBounds().width;
		y = Text_portal->getGlobalBounds().height;
		x /= 2;
		y /= 2;
		Text_portal->setOrigin(x, y);
		Text_portal->setScale(sf::Vector2f(0.3f, 0.5f));
		Portals.push_back(*Text_portal);
	}
	/*******************************************************/
	number_of_invisible_walls = 0;
	number_platforms = 0;
	number_of_spikes = 0;
	number_of_portals = 0;
	number_of_enemies = 0;
	double position_x = 0;
	double position_y = 0;
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 30; x++)
		{
			if (level2[y][x] == 1)
			{
				Real_platforms[number_platforms].setPosition(sf::Vector2f(position_x, position_y));
				number_platforms++;
			}
			else if (level2[y][x] == 2)
			{
				Invisible_walls[number_of_invisible_walls].setPosition(sf::Vector2f(position_x, position_y));
				number_of_invisible_walls++;
			}
			else if (level2[y][x] == 3)
			{
				Spikes[number_of_spikes].setPosition(sf::Vector2f(position_x, position_y));
				number_of_spikes++;
			}
			else if (level2[y][x] == 4)
			{
				player1.start_pos_x = position_x;
				player1.start_pos_y = position_y;
			}
			else if (level2[y][x] == 5)
			{
				Portals[number_of_portals].setPosition(sf::Vector2f(position_x, position_y));
				number_of_portals++;
			}
			else if (level2[y][x] == 6)
			{
				Enemies[number_of_enemies].Enemy_sp.setPosition(sf::Vector2f(position_x, position_y));
				number_of_enemies++;
			}
			position_x += 100;
		}
		position_x = 0;
		position_y += 100;
	}
	lvl2 = true;
	//////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////
}
void Map::Make_level3()
{
	int x, y;
	lvl1 = false;
	lvl2 = false;
	lvl3 = false;
	number_of_portals = 0;
	number_of_spikes = 0;
	number_platforms = 0;
	number_of_invisible_walls = 0;
	number_of_enemies = 0;
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 30; x++)
		{
			if (level3[y][x] == 1)
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
			else if (level3[y][x] == 2)
			{
				number_of_invisible_walls++;
			}
			else if (level3[y][x] == 3)
			{
				number_of_spikes++;
			}
			else if (level3[y][x] == 5)
			{
				number_of_portals++;
			}
			else if (level3[y][x] == 6)
			{
				number_of_enemies++;
			}
		}
	}
	/*********************************************************/
	std::cout << "Platforms: " << number_platforms << std::endl;//real platforms
	sf::Sprite *Text_plat = new sf::Sprite[number_platforms];
	for (int i = 0; i < number_platforms; i++, *Text_plat++)
	{
		Text_plat->setTexture(plat);
		Text_plat->setScale(sf::Vector2f(0.2f, 0.2f));
		Real_platforms.push_back(*Text_plat);
	}
	/*********************************************************/
	std::cout << "Walls: " << number_of_invisible_walls << std::endl;//invisible walls
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
	/******************************************************/
	std::cout << "Enemies: " << number_of_enemies << std::endl;
	Enemy *Text_Enemy = new Enemy[number_of_enemies];
	for (int i = 0; i < number_of_enemies; i++, *Text_Enemy++)
	{
		Enemies.push_back(*Text_Enemy);
		be_enemy.push_back(true);
	}
	/*******************************************************/
	std::cout << "Portals: " << number_of_portals << std::endl;//portals
	sf::Sprite *Text_portal = new sf::Sprite[number_of_portals];
	for (int i = 0; i < number_of_portals; i++, *Text_portal++)
	{
		Text_portal->setTexture(Portal_txt);
		x = Text_portal->getGlobalBounds().width;
		y = Text_portal->getGlobalBounds().height;
		x /= 2;
		y /= 2;
		Text_portal->setOrigin(x, y);
		Text_portal->setScale(sf::Vector2f(0.3f, 0.5f));
		Portals.push_back(*Text_portal);
	}
	/*******************************************************/
	number_of_invisible_walls = 0;
	number_platforms = 0;
	number_of_spikes = 0;
	number_of_portals = 0;
	number_of_enemies = 0;
	double position_x = 0;
	double position_y = 0;
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 30; x++)
		{
			if (level3[y][x] == 1)
			{
				Real_platforms[number_platforms].setPosition(sf::Vector2f(position_x, position_y));
				number_platforms++;
			}
			else if (level3[y][x] == 2)
			{
				Invisible_walls[number_of_invisible_walls].setPosition(sf::Vector2f(position_x, position_y));
				number_of_invisible_walls++;
			}
			else if (level3[y][x] == 3)
			{
				Spikes[number_of_spikes].setPosition(sf::Vector2f(position_x, position_y));
				number_of_spikes++;
			}
			else if (level3[y][x] == 4)
			{
				player1.start_pos_x = position_x;
				player1.start_pos_y = position_y;
			}
			else if (level3[y][x] == 5)
			{
				Portals[number_of_portals].setPosition(sf::Vector2f(position_x, position_y));
				number_of_portals++;
			}
			else if (level3[y][x] == 6)
			{
				Enemies[number_of_enemies].Enemy_sp.setPosition(sf::Vector2f(position_x, position_y));
				number_of_enemies++;
			}
			position_x += 100;
		}
		position_x = 0;
		position_y += 100;
	}
	lvl3 = true;
	//////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////
}
Map::Map()
{
	plat.loadFromFile("World/Grass.png");
	Spike.loadFromFile("World/Spike.png");
	Portal_txt.loadFromFile("World/Portal.png");
	text_background.loadFromFile("Background/background_game.png");
	background.setTexture(text_background);
	background.setScale(5, 5);
	background.setPosition(sf::Vector2f(-400.f, -600.f));
	number_of_enemies = 0;
	////////////////////////////////////////////////////
}
void Map::engine(Player &player1, std::vector<Enemy> &Enemies, std::vector <sf::Sprite> &Platform, std::vector <sf::RectangleShape> &Wall, std::vector<sf::Sprite> &Spikes,std::vector<sf::Sprite> &Portals,bool &menu_game)
{
	for (int i = 0; i < number_of_enemies; i++)
	{
		if (Enemies[i].be == true)
		{
			if (Enemies[i].movingbo == true)
			{
				Enemies[i].moving();
			}
			Enemies[i].update_position_rect();
			if (Enemies[i].gravitationbo == true)
			{
				Enemies[i].gravitation();
			}
			if (Enemies[i].knockbackbo == true)
			{
				if (Enemies[i].knockleft == true)
				{
					Enemies[i].knockbackleft();
				}
				else if (Enemies[i].knockright == true)
				{
					Enemies[i].knockbackright();
				}
				Enemies[i].Enemy_sp.setColor(sf::Color::Red);
				Enemies[i].knockback_steps++;
				Enemies[i].anim = false;
				if (Enemies[i].knockback_steps > 15)
				{
					Enemies[i].life -= 25;
					Enemies[i].knockback_steps = 0;
					Enemies[i].knockbackbo = false;
					Enemies[i].gravitationbo = true;
					Enemies[i].knockleft = false;
					Enemies[i].knockright = false;
				}
			}
			if (Enemies[i].death == false)
			{
				Enemies[i].checklife();
			}
			if (Enemies[i].death == true)
			{
				dont_draw_enemy();
			}
		}
	}
	/****************************/ //this must be in this function because this is not working in main lol
	player1.colission(Platform, number_platforms, Wall, number_of_invisible_walls, Spikes, number_of_spikes, Portals, number_of_portals, Enemies, number_of_enemies, new_game, menu_game, lvl1, lvl2, lvl3);//enemy colission and everything with what collide player 
	/*****************************************************************************************************/
	if (set_player1 == 0)
	{
		player1.Player_box->setPosition(sf::Vector2f(player1.start_pos_x, player1.start_pos_y));
		set_player1++;
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
				player1.jumping = false;
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
