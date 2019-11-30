#include <iostream>
#include <SFML\Graphics.hpp>
#include "Enemy.h"

Enemy::Enemy()
{
	Enemy_txt[0].loadFromFile("Enemy//Run01.png");
	Enemy_txt[1].loadFromFile("Enemy//Run02.png");
	Enemy_txt[2].loadFromFile("Enemy//Run03.png");
	Enemy_txt[3].loadFromFile("Enemy//Run04.png");
	Enemy_txt[4].loadFromFile("Enemy//Run05.png");
	Enemy_txt[5].loadFromFile("Enemy//Run06.png");
	Enemy_sp.setTexture(Enemy_txt[0]);
	/****************************************************/
	/****************************************************/
	hitbuffer.loadFromFile("Sounds//Enemy_hit.wav");
	Hit.setBuffer(hitbuffer);
	Hit.setVolume(100);
	/****************************************************/
	double iks = Enemy_sp.getGlobalBounds().width;
	double igrek = Enemy_sp.getGlobalBounds().height;
	iks /= 2;
	igrek /= 2;
	Enemy_sp.setOrigin(iks, igrek);
	Enemy_sp.setScale(2, 2);
	for (int i = 0; i <= 1; i++)
	{ 
		Rectangle[i].setSize(sf::Vector2f(10, 300));
	}
	Rectangle[0].setPosition(sf::Vector2f(700, Enemy_sp.getPosition().y-200));
	Rectangle[0].setRotation(90);
	Rectangle[1].setPosition(sf::Vector2f(1100, Enemy_sp.getPosition().y-200));
	Rectangle[1].setRotation(90);
	for (int i = 0; i < 4; i++)
	{
		Player_Rect[i].setSize(sf::Vector2f(10, 100));
		float iks = Player_Rect[i].getGlobalBounds().width;
		float igrek = Player_Rect[i].getGlobalBounds().height;
		iks /= 2;
		igrek /= 2;
		Player_Rect[i].setOrigin(sf::Vector2f(iks, igrek));
		Player_Rect[i].setPosition(sf::Vector2f(300, 300));
	}
	Player_Rect[0].setRotation(90);
	Player_Rect[2].setRotation(90);
	hp_bar.setSize(sf::Vector2f(50.f, 10.f));
	hp_bar.setFillColor(sf::Color::Red);
}
void Enemy::draw_Enemy(sf::RenderWindow &window)
{
	window.draw(Enemy_sp);
	/*for (int i = 0; i <= 1; i++)
	{
		window.draw(Rectangle[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		window.draw(Player_Rect[i]);
	}*/
	window.draw(hp_bar);
}
void Enemy::move()
{
	Enemy_sp.move(speed, 0);
}
void Enemy::moving()
{
	if (move_right == true)
	{
		speed = 5;
	}
	if (move_right == false)
	{
		speed = -5;
	}
	move();
}
void Enemy::animation()
{
	if ((steps++) % 5 == 1)
	{
			i++;
			Enemy_sp.setTexture(Enemy_txt[i]);
			if (i == 5)
			{
				i = -1;
			}
	}
}
void Enemy::update_position_rect()
{
	Player_Rect[0].setPosition(sf::Vector2f(Enemy_sp.getPosition().x-8, Enemy_sp.getPosition().y+35));//dolna platforma
	Player_Rect[1].setPosition(sf::Vector2f(Enemy_sp.getPosition().x+40, Enemy_sp.getPosition().y-20));//prawa platforma
	Player_Rect[2].setPosition(sf::Vector2f(Enemy_sp.getPosition().x, Enemy_sp.getPosition().y-50 ));//gorna platforma
	Player_Rect[3].setPosition(sf::Vector2f(Enemy_sp.getPosition().x-40, Enemy_sp.getPosition().y));//lewa platforma
	//if (gravitationbo == false)
	//{
	Rectangle[0].setPosition(sf::Vector2f(Enemy_sp.getPosition().x-40, Enemy_sp.getPosition().y - 10));//left view
	Rectangle[1].setPosition(sf::Vector2f(Enemy_sp.getPosition().x+335, Enemy_sp.getPosition().y - 10));//right view 
	//}
	hp_bar.setPosition(sf::Vector2f(Enemy_sp.getPosition().x - 30, Enemy_sp.getPosition().y - 60));
}
void Enemy::gravitation()
{
	Enemy_sp.setPosition(sf::Vector2f(Enemy_sp.getPosition().x, Enemy_sp.getPosition().y + gravity));
}
void Enemy::knockbackleft()
{
	Enemy_sp.move(7.5, -7.5);
}
void Enemy::knockbackright()
{
	Enemy_sp.move(-7.5, -7.5);
}
void Enemy::checklife()
{
	if (life == 50)
	{
		hp_bar.setSize(sf::Vector2f(life, 10));
	}
	else if (life == 25)
	{
		hp_bar.setSize(sf::Vector2f(life, 10));
	}
	else if (life <= 0)
	{
		hp_bar.setSize(sf::Vector2f(life, 10));
		death = true;
		movingbo = false;
		anim = false;
		be = false;
	}
}