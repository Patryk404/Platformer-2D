#include "DeathScreen.h"
#include <iostream>

Death_Screen::Death_Screen()
{
	font.loadFromFile("Text\\Vanjar.ttf");
	Play_again.setFont(font);
	Exit_to_menu.setFont(font);
	Play_again.setString("Play Again");
	Exit_to_menu.setString("Exit to menu");
	double x;
	double y;
	x = Play_again.getGlobalBounds().width;
	y = Play_again.getGlobalBounds().height;
	x /= 2;
	y /= 2;
	Play_again.setOrigin(x, y);
	x = Exit_to_menu.getGlobalBounds().width;
	y = Exit_to_menu.getGlobalBounds().height;
	x /= 2;
	y /= 2;
	Exit_to_menu.setOrigin(x, y);
	Play_again.setCharacterSize(50);
	Exit_to_menu.setCharacterSize(50);
}
void Death_Screen::Display(sf::RenderWindow &window, Player &player, sf::Clock &clock, sf::View &camera, Map &map, bool &game, bool &new_game)
{
	if (anim == true)
	{
		Animation(player, clock, camera, window);
	}
	if ((Play_again.getColor() == sf::Color::Red&&Exit_to_menu.getColor() == sf::Color::White)||(Play_again.getColor() == sf::Color::White&&Exit_to_menu.getColor() == sf::Color::Red))
	{
		Engine(game, new_game,map);
	}
	if (map.background.getColor()!=sf::Color(0,0,0,0))
	{
		r = map.background.getColor().r;
		g = map.background.getColor().g;
		b = map.background.getColor().b;
		a = map.background.getColor().a;
		r--;
		g--;
		b--;
		a--;
		map.background.setColor(sf::Color(r, g, b, a));
	}
	window.draw(Play_again);
	window.draw(Exit_to_menu);
}
void Death_Screen::Animation(Player &player,sf::Clock &clock,sf::View &camera,sf::RenderWindow &window)
{
	time = clock.getElapsedTime().asSeconds();
	clock.restart();
	timer += time;
	if (timer >delay)
	{
		if (Play_again.getPosition().x >= camera.getCenter().x)
		{
			Play_again.move(-5, 0);
			Exit_to_menu.move(-5, 0);
		}
		else 
		{ 
		Play_again.setColor(sf::Color::Red);
		anim = false;
		}
	}
}
void Death_Screen::Engine(bool &game, bool &new_game,Map &map)
{
	if (Play_again.getColor() == sf::Color::Red)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			new_game = true;
			game = false;
			anim = true;
		}
	}
	else if (Exit_to_menu.getColor() == sf::Color::Red)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			game = false;
			new_game = false;
			anim = true;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		Play_again.setColor(sf::Color::White);
		Exit_to_menu.setColor(sf::Color::Red);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		Play_again.setColor(sf::Color::Red);
		Exit_to_menu.setColor(sf::Color::White);
	}
}
