#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Enemy.h"
class Player
{
public:
	/***************************************************/
	sf::Sprite* Player_box;
	sf::CircleShape circle[4];
	sf::CircleShape middlecircle;
	sf::RectangleShape sword;
	sf::RectangleShape rectangle;
	sf::RectangleShape health_bar;
	/**************************************************/
	sf::Sound Jump_s;
	sf::Sound Hit_s;
	sf::Sound Miss_s;
	/**************************************************/
	void gravitation();
	void movement();
	void colission(std::vector <sf::Sprite> &Platforms, int number_of_platforms,std::vector<sf::RectangleShape> &Walls,int number_of_invisible_walls,std::vector <sf::Sprite> &Spikes, int number_of_spikes,std::vector <sf::Sprite> &Portals,int number_of_portals, std::vector<Enemy> &Enemies,int number_of_enemies,bool&new_game,bool&game,bool&lvl1,bool&lvl2,bool&lvl3);
	void Update_position_circle();
	void jump();
	void animations();
	void knockback_fun(); 
	void fighting();
	void check_life();
    void restart();
	/**************************************************/
	bool jumping = false;
	bool grounded=false;
	bool rectangleb = true;
	bool idling = true;
	bool running = false;
	bool colissionb = true; 
	bool knockback = false; 
	bool upper = false;
	bool rightr = false; 
	bool able = true;
	bool gravitationbo = true;
	bool fight = false;
	bool fight_two = false;
	bool death = false;
	/***************************************************/
	float gravity = 20;
	/***************************************************/
	int knockknock;
	int knockback_steps = 0;
	int life = 125;
	int moving = 0;
	int start_pos_x;
	int start_pos_y;
	Player();
private:
	sf::Texture idle[6];
	sf::Texture Run[8];
	sf::Texture Jump[6];
	sf::Texture Attack[10];
	sf::Texture Die[19];
	/*****************************/
	sf::SoundBuffer jumpbuffer;
	sf::SoundBuffer hitbuffer;
	sf::SoundBuffer misshitbuffer;
	/****************************/
	int steps = 0;
	int i=0; //animation of idling 
	int j = 0;// animation of running
	int n = 0;//animation of jumping
	int a = -1;//animation of attack
	int d = -1;//animation of dying
	bool left;
	bool be = true;
	float velocity = 20;
	float speed=7.5;
	void knockback_detection();
};

#endif
