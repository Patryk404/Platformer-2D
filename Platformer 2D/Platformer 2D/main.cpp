#include <SFML\Graphics.hpp>
#include <iostream>
#include "map.h"
#include "Menu.h"
sf::RenderWindow window(sf::VideoMode(1280, 720), "2D Platformer");
Map map;
Menu menu;
sf::View camera;
int main()
{
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);
	map.Make_level1();
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
					if (e.key.code == sf::Keyboard::Z&&map.player1.death==false&&map.player1.grounded==true)
					{
						map.player1.fight = true;
						map.player1.idling = false;
						map.player1.running = false;
						map.player1.able = false;
					}
					if (e.key.code == sf::Keyboard::Space)
					{
						map.player1.moving = 0;
					}
				}
			}
			if (e.type == sf::Event::KeyReleased)
			{
				if (e.key.code == sf::Keyboard::Space)
				{
					map.player1.moving = 0;
				}
			}
		}
		/****************************************************************/
		if (menu.game == true)
		{
			window.clear(sf::Color::Blue);
			window.draw(map.background);
			for (int i = 0; i < map.number_of_spikes; i++)
			{
				window.draw(map.Spikes[i]);
			}
			window.draw(*map.player1.Player_box);
			//window.draw(map.player1.rectangle);
			//window.draw(map.player1.sword);
			window.draw(map.player1.health_bar);
			//window.draw(map.player1.camera_left);
			//window.draw(map.player1.camera_right);
			//window.draw(map.player1.camera_down);
			for (int i = 0; i < map.number_platforms; i++)
			{
				window.draw(map.Real_platforms[i]);
			}
			/*for (int i = 0; i < 4; i++)
			{
				window.draw(map.player1.circle[i]);
			}
			window.draw(map.player1.middlecircle);*/
			map.engine(map.player1, map.enemy1, map.Real_platforms, map.Invisible_walls, map.Spikes, camera);
			window.setView(camera);
			map.player1.animations();
			/********************************************/
			for (int i = 0; i < map.number_of_enemies; i++)
			{
				if (map.be_enemy[i] == true)
				{
					if (map.enemy1[i]->anim == true)
					{
						map.enemy1[i]->animation();
					}
					map.enemy1[i]->draw_Enemy(window);
				}
			}
			window.display();
		}
		/****************************************************************/
		else if (menu.game== false && menu.choose_level==false)
		{
			window.clear(sf::Color::Black);
			menu.draw_menu(window);
			menu.menu_system(window);
			window.display();
		}
		else if (menu.game == false && menu.choose_level == true)
		{
			window.clear(sf::Color::Black);
			menu.draw_menu(window);
			menu.choose_lvl_colission(window);
			menu.update_position(window);
			window.display();
		}
		/****************************************************************/
	}
	 
}