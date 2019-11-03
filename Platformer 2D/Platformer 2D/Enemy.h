#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

class Enemy
{
public:
	/*********************************/
	sf::Sprite Enemy_sp;
	sf::RectangleShape Rectangle[2];//platforms where your enemy see 
	sf::RectangleShape Player_Rect[4];
	sf::RectangleShape hp_bar; 
	/********************************/
	sf::Sound Hit;
	sf::Texture Enemy_txt[6];
	/********************************/
	bool move_right = true;
	bool knockbackbo = false;
	bool gravitationbo = true; 
	bool movingbo = false;
	bool knockright = false;
	bool knockleft = false;
	bool anim = false; 
	bool death = false;
	bool walking = true;
	bool be = true;
	int life = 50;
	int knockback_steps = 0; 
	/********************************/
	Enemy();
	void draw_Enemy(sf::RenderWindow &window);
	void moving();
	void update_position_rect();
	void animation();
	void gravitation();
	void knockbackleft();
	void knockbackright();
	void checklife();
	/********************************/
private:
	sf::SoundBuffer hitbuffer;
	void move();
	int steps = 0;
	int i = 0;
	float gravity = 20;
	double speed;
};