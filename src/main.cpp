#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.h"
#include "Menu.h"
sf::RenderWindow window(sf::VideoMode(1280, 720), "2D Platformer");
Menu menu;
Map *map;
sf::View camera;
int main()
{
	map = new Map();
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
			if (menu.game == true)
			{
				if (e.type == sf::Event::KeyPressed)
				{
					if (e.key.code == sf::Keyboard::Z && map->player1.death == false && map->player1.grounded == true)
					{
						map->player1.fight = true;
						map->player1.idling = false;
						map->player1.running = false;
						map->player1.able = false;
					}
					if (e.key.code == sf::Keyboard::Space)
					{
						map->player1.moving = 0;
					}
				}
			}
			if (e.type == sf::Event::KeyReleased)
			{
				if (e.key.code == sf::Keyboard::Space)
				{
					map->player1.moving = 0;
				}
			}
		}
		/****************************************************************/
		if (menu.game == true)
		{
			camera.setSize(1000, 1000);
			camera.setCenter(map->player1.Player_box->getPosition());
			window.clear(sf::Color::Black);
			window.draw(map->background);
			for (int i = 0; i < map->number_of_spikes; i++)
			{
				window.draw(map->Spikes[i]);
			}
			window.draw(*map->player1.Player_box);
			// window.draw(map.player1.rectangle);
			// window.draw(map.player1.sword);
			window.draw(map->player1.health_bar);
			// window.draw(map.player1.camera_left);
			// window.draw(map.player1.camera_right);
			// window.draw(map.player1.camera_down);
			for (int i = 0; i < map->number_platforms; i++)
			{
				window.draw(map->Real_platforms[i]);
			}
			for (int i = 0; i < map->number_of_portals; i++)
			{
				window.draw(map->Portals[i]);
			}
			/*for (int i = 0; i < 4; i++)
			{
				window.draw(map.player1.circle[i]);
			}
			window.draw(map.player1.middlecircle);*/
			map->engine(map->player1, map->Enemies, map->Real_platforms, map->Invisible_walls, map->Spikes, map->Portals, menu.game);
			window.setView(camera);
			map->player1.animations();
			/********************************************/
			for (int i = 0; i < map->number_of_enemies; i++)
			{
				if (map->be_enemy[i] == true)
				{
					if (map->Enemies[i].anim == true)
					{
						map->Enemies[i].animation();
					}
					if (map->Enemies[i].be == true)
					{
						map->Enemies[i].draw_Enemy(window);
					}
				}
			}
			if (map->player1.death == true && menu.dead_ss.death_ss == false)
			{
				menu.dead_ss.Exit_to_menu.setPosition(sf::Vector2f(camera.getCenter().x + 600, camera.getCenter().y + 300));
				menu.dead_ss.Play_again.setPosition(sf::Vector2f(camera.getCenter().x + 600, camera.getCenter().y));
				menu.dead_ss.death_ss = true;
				map->count_death++;
			}
			else if (map->player1.death == true && menu.dead_ss.death_ss == true)
			{
				menu.dead_ss.Display(window, map->player1, clock, camera, *map, menu.game, map->new_game);
			}
			window.display();
		}
		else if (map->new_game == true)
		{
			delete map;
			map = new Map();
			map->player1.restart();

			if (map->lvl1 == true)
			{
				map->Make_level1();
			}
			else if (map->lvl2 == true)
			{
				map->Make_level2();
			}
			else if (map->lvl3 == true)
			{
				map->Make_level3();
			}
			map->player1.death = false;
			menu.dead_ss.death_ss = false;
			menu.dead_ss.Play_again.setColor(sf::Color::White);
			menu.dead_ss.Exit_to_menu.setColor(sf::Color::White);
			map->background.setColor(sf::Color::White);
			map->set_player1 = 0;
			map->new_game = false;
			menu.game = true;
		}
		/****************************************************************/
		else if (menu.game == false && menu.choose_level == false && map->new_game == false)
		{
			window.clear(sf::Color::Black);
			camera.setSize(1280, 720);
			camera.setCenter(sf::Vector2f(640, 360));
			window.setView(camera);
			menu.draw_menu(window);
			menu.menu_system(window, *map);
			window.display();
		}
		else if (menu.game == false && menu.choose_level == true)
		{
			window.clear(sf::Color::Black);
			menu.draw_menu(window);
			menu.choose_lvl_colission(window, map->new_game, map->count_death, *map);
			/*	if (map.count_death == 0)
				{
					if (map.lvl1 == true)
					{
						map.Make_level1();
					}
					else if (map.lvl2 == true)
					{
						map.Make_level2();
					}
					else if (map.lvl3 == true)
					{
						map.Make_level3();
					}
				}*/
			menu.update_position(window);
			window.display();
		}
		/****************************************************************/
	}
}
