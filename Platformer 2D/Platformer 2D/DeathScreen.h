#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Player.h"
#include "map.h"
class Death_Screen
{
private:
	sf::Font font;
	float timer = 0, delay = 1, time;
	int r, g, b, a;
	void Animation(Player &player, sf::Clock &clock,sf::View &camera,sf::RenderWindow &window);
	bool anim = true;
public:
	sf::Text Play_again;
	sf::Text Exit_to_menu;
	bool death_ss = false;
	void Engine(bool &game, bool &new_game,Map &map);
	void Display(sf::RenderWindow &window,Player &player,sf::Clock &clock,sf::View &camera,Map &map,bool &game,bool &new_game);
	Death_Screen();
};
