#include "Player.h"
#include <iostream>

Player::Player()
{
	idle[0].loadFromFile("Idle/Idle_01.png");
	idle[1].loadFromFile("Idle/Idle_02.png");
	idle[2].loadFromFile("Idle/Idle_03.png");
	idle[3].loadFromFile("Idle/Idle_04.png");
	idle[4].loadFromFile("Idle/Idle_05.png");
	idle[5].loadFromFile("Idle/Idle_06.png");
	Run[0].loadFromFile("Run/Run_01.png");
	Run[1].loadFromFile("Run/Run_02.png");
	Run[2].loadFromFile("Run/Run_03.png");
	Run[3].loadFromFile("Run/Run_04.png");
	Run[4].loadFromFile("Run/Run_05.png");
	Run[5].loadFromFile("Run/Run_06.png");
	Run[6].loadFromFile("Run/Run_07.png");
	Run[7].loadFromFile("Run/Run_08.png");
	Jump[0].loadFromFile("Jump/Jump_01.png");
	Jump[1].loadFromFile("Jump/Jump_02.png");
	Jump[2].loadFromFile("Jump/Jump_03.png");
	Jump[3].loadFromFile("Jump/Jump_04.png");
	Jump[4].loadFromFile("Jump/Jump_05.png");
	Jump[5].loadFromFile("Jump/Jump_06.png");
	Attack[0].loadFromFile("Attack/Attack_01.png");
	Attack[1].loadFromFile("Attack/Attack_02.png");
	Attack[2].loadFromFile("Attack/Attack_03.png");
	Attack[3].loadFromFile("Attack/Attack_04.png");
	Attack[4].loadFromFile("Attack/Attack_05.png");
	Attack[5].loadFromFile("Attack/Attack_06.png");
	Attack[6].loadFromFile("Attack/Attack_07.png");
	Attack[7].loadFromFile("Attack/Attack_08.png");
	Attack[8].loadFromFile("Attack/Attack_09.png");
	Attack[9].loadFromFile("Attack/Attack_10.png");
	Die[0].loadFromFile("Death/Death_01.png");
	Die[1].loadFromFile("Death/Death_02.png");
	Die[2].loadFromFile("Death/Death_03.png");
	Die[3].loadFromFile("Death/Death_04.png");
	Die[4].loadFromFile("Death/Death_05.png");
	Die[5].loadFromFile("Death/Death_06.png");
	Die[6].loadFromFile("Death/Death_07.png");
	Die[7].loadFromFile("Death/Death_08.png");
	Die[8].loadFromFile("Death/Death_09.png");
	Die[9].loadFromFile("Death/Death_10.png");
	Die[10].loadFromFile("Death/Death_11.png");
	Die[11].loadFromFile("Death/Death_12.png");
	Die[12].loadFromFile("Death/Death_13.png");
	Die[13].loadFromFile("Death/Death_14.png");
	Die[14].loadFromFile("Death/Death_15.png");
	Die[15].loadFromFile("Death/Death_16.png");
	Die[16].loadFromFile("Death/Death_17.png");
	Die[17].loadFromFile("Death/Death_18.png");
	Die[18].loadFromFile("Death/Death_19.png");
	/*******************************************************/
	jumpbuffer.loadFromFile("Sounds/Jump.wav");
	Jump_s.setBuffer(jumpbuffer);
	Jump_s.setVolume(100);
	hitbuffer.loadFromFile("Sounds/Hit.wav");
	Hit_s.setBuffer(hitbuffer);
	Hit_s.setVolume(100);
	misshitbuffer.loadFromFile("Sounds/Miss_hit.wav");
	Miss_s.setBuffer(misshitbuffer);
	Miss_s.setVolume(100);
	/*******************************************************/
	Player_box = new sf::Sprite;
	Player_box->setTexture(idle[0]);
	float iks = Player_box->getGlobalBounds().width;
	float igrek = Player_box->getGlobalBounds().height;
	iks /= 2;
	igrek /= 2;
	Player_box->setOrigin(sf::Vector2f(iks, igrek));
	Player_box->setScale(3, 3);
	for (int i = 0; i < 4; i++)
	{
		circle[i].setRadius(3);
		circle[i].setFillColor(sf::Color::Yellow);
	}
	middlecircle.setRadius(3);
	middlecircle.setFillColor(sf::Color::Yellow);
	middlecircle.setPosition(Player_box->getPosition().x, Player_box->getPosition().y);
	rectangle.setSize(sf::Vector2f(300, 10));
	double ex = rectangle.getGlobalBounds().width;
	double ygrek = rectangle.getGlobalBounds().height;
	ex /= 2;
	ygrek /= 2;
	rectangle.setOrigin(sf::Vector2f((float)ex, (float)ygrek));
	sword.setSize(sf::Vector2f(100, 15));
	ex = sword.getGlobalBounds().width;
	ygrek = sword.getGlobalBounds().height;
	ex /= 2;
	ygrek /= 2;
	sword.setOrigin(sf::Vector2f((float)ex, (float)ygrek));
	sword.rotate(90);
	knockknock = rand() % 2 + 1;
	gravitationbo = true;
	health_bar.setSize(sf::Vector2f(125, 10));
	health_bar.setFillColor(sf::Color::Red);
	life = 125;
	death = false;
}

void Player::restart()
{
	Player_box = new sf::Sprite;
	Player_box->setTexture(idle[0]);
	float iks = Player_box->getGlobalBounds().width;
	float igrek = Player_box->getGlobalBounds().height;
	iks /= 2;
	igrek /= 2;
	Player_box->setOrigin(sf::Vector2f(iks, igrek));
	Player_box->setScale(3, 3);
	for (int i = 0; i < 4; i++)
	{
		circle[i].setRadius(3);
		circle[i].setFillColor(sf::Color::Yellow);
	}
	middlecircle.setRadius(3);
	middlecircle.setFillColor(sf::Color::Yellow);
	middlecircle.setPosition(Player_box->getPosition().x, Player_box->getPosition().y);
	rectangle.setSize(sf::Vector2f(300, 10));
	double ex = rectangle.getGlobalBounds().width;
	double ygrek = rectangle.getGlobalBounds().height;
	ex /= 2;
	ygrek /= 2;
	rectangle.setOrigin(sf::Vector2f((float)ex, (float)ygrek));
	sword.setSize(sf::Vector2f(100, 15));
	ex = sword.getGlobalBounds().width;
	ygrek = sword.getGlobalBounds().height;
	ex /= 2;
	ygrek /= 2;
	sword.setOrigin(sf::Vector2f((float)ex, (float)ygrek));
	sword.rotate(90);
	knockknock = rand() % 2 + 1;
	gravitationbo = true;
	health_bar.setSize(sf::Vector2f(125, 10));
	health_bar.setFillColor(sf::Color::Red);
	life = 125;
	death = false;
}

void Player::gravitation()
{
	Player_box->setPosition(sf::Vector2f(Player_box->getPosition().x, Player_box->getPosition().y + gravity));
}
void Player::movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		Player_box->move(speed, 0);
		left = false;
		running = true;
		idling = false;
		fight = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		Player_box->move(-speed, 0);
		left = true;
		running = true;
		idling = false;
		fight = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == false && sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == false)
	{
		idling = true;
		running = false;
	}
	else if ((!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && fight == false)
	{
		idling = true;
		running = false;
	}
	if (moving == 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && grounded == true)
		{
			jumping = true;
			idling = false;
			running = false;
			rectangleb = false;
			fight = false;
			grounded = false;
			gravitationbo = false;
			Jump_s.play();
		}
	}
}
void Player::Update_position_circle()
{
	circle[0].setPosition(sf::Vector2f(Player_box->getPosition().x, Player_box->getPosition().y + 60)); // bottom cicle
	circle[1].setPosition(sf::Vector2f(Player_box->getPosition().x + 40, Player_box->getPosition().y)); // right circle
	circle[2].setPosition(sf::Vector2f(Player_box->getPosition().x, Player_box->getPosition().y - 40)); // top circle
	circle[3].setPosition(sf::Vector2f(Player_box->getPosition().x - 40, Player_box->getPosition().y)); // left circle
	if (grounded == true)
	{
		middlecircle.setPosition(sf::Vector2f(Player_box->getPosition().x, Player_box->getPosition().y)); // middle circle
	}
	if (rectangleb == true)
	{
		rectangle.setPosition(sf::Vector2f(Player_box->getPosition().x, Player_box->getPosition().y - 300));
	}
	if (left == false)
	{
		sword.setPosition(sf::Vector2f(Player_box->getPosition().x + 35, Player_box->getPosition().y));
	}
	else
	{
		sword.setPosition(sf::Vector2f(Player_box->getPosition().x - 35, Player_box->getPosition().y));
	}
	health_bar.setPosition(sf::Vector2f(Player_box->getPosition().x - 60, Player_box->getPosition().y - 60));
}
void Player::jump()
{
	Player_box->move(0, -velocity);
}
void Player::colission(std::vector<sf::Sprite> &Platforms, int number_of_platforms, std::vector<sf::RectangleShape> &Walls, int number_of_invisible_walls, std::vector<sf::Sprite> &Spikes, int number_of_spikes, std::vector<sf::Sprite> &Portals, int number_of_portals, std::vector<Enemy> &Enemies, int number_of_enemies, bool &new_game, bool &game, bool &lvl1, bool &lvl2, bool &lvl3)
{
	std::vector<sf::FloatRect> Platform_box(number_of_platforms);
	std::vector<sf::FloatRect> Invisible_wall_box(number_of_invisible_walls);
	std::vector<sf::FloatRect> Spike_box(number_of_spikes);
	std::vector<sf::FloatRect> Portal_box(number_of_portals);
	sf::FloatRect Rectangle_Box = rectangle.getGlobalBounds();
	sf::FloatRect Player_Boxs[4];
	sf::FloatRect Middle_Box = middlecircle.getGlobalBounds();
	sf::FloatRect Excalibur = sword.getGlobalBounds();
	for (int i = 0; i < 4; i++)
	{
		Player_Boxs[i] = circle[i].getGlobalBounds();
		/*
		Player_Boxs[0] is bottom point
		Player_Boxs[1] is right point
		Player_Boxs[2] is upper point
		Player_Boxs[3] is left point
		*/
	}
	for (int i = 0; i < number_of_platforms; i++)
	{
		Platform_box[i] = Platforms[i].getGlobalBounds(); // Platforms
	}
	for (int i = 0; i < number_of_invisible_walls; i++)
	{
		Invisible_wall_box[i] = Walls[i].getGlobalBounds(); // Invisible walls
	}
	for (int i = 0; i < number_of_spikes; i++)
	{
		Spike_box[i] = Spikes[i].getGlobalBounds(); // Spikes
	}
	for (int i = 0; i < number_of_portals; i++)
	{
		Portal_box[i] = Portals[i].getGlobalBounds(); // Portals
	}
	/***************************************************************************************************************************/
	for (int i = 0; i < number_of_platforms; i++)
	{
		if (Player_Boxs[0].intersects(Platform_box[i]))
		{
			if (jumping == false)
			{
				grounded = true;
				if (colissionb == true)
				{
					rectangleb = true;
					jumping = false;
					if (fight == false && death == false)
					{
						able = true;
					}
					Player_box->setPosition(sf::Vector2f(Player_box->getPosition().x, Platforms[i].getPosition().y - 70));
					Player_box->setColor(sf::Color::White);
				}
			}
		}
		if (Player_Boxs[1].intersects(Platform_box[i]))
		{
			Player_box->move(sf::Vector2f(-7.5, 0));
		}
		if (Player_Boxs[2].intersects(Platform_box[i]))
		{
			Player_box->setPosition(sf::Vector2f(Player_box->getPosition().x, Platforms[i].getPosition().y + 135));
		}
		if (Player_Boxs[3].intersects(Platform_box[i]))
		{
			Player_box->move(sf::Vector2f(7.5, 0));
		}
		if (Player_Boxs[2].intersects(Rectangle_Box) || Player_Boxs[2].intersects(Platform_box[i]))
		{
			jumping = false;
			moving = 1;
			gravitationbo = true;
			// gravitation();
		}
		/*if (!Player_Boxs[0].intersects(Platform_box[i]))
		{
			gravitationbo = true;
		}*/
	}
	/************************************************************************/
	int notground = 0;
	for (int i = 0; i < number_of_platforms; i++)
	{
		if (!Player_Boxs[0].intersects(Platform_box[i]))
		{
			notground++;
		}
	}
	if (notground == number_of_platforms)
	{
		grounded = false;
	}
	/******************************************************************************************************************************/
	for (int i = 0; i < number_of_invisible_walls; i++)
	{
		if (Player_Boxs[0].intersects(Invisible_wall_box[i]))
		{
			if (jumping == false)
			{
				grounded = true;
				if (colissionb == true)
				{
					rectangleb = true;
					jumping = false;
					if (fight == false && death == false)
					{
						able = true;
					}
					Player_box->setPosition(sf::Vector2f(Player_box->getPosition().x, Walls[i].getPosition().y - 70));
					Player_box->setColor(sf::Color::White);
				}
			}
		}
		if (Player_Boxs[1].intersects(Invisible_wall_box[i]))
		{
			Player_box->move(sf::Vector2f(-7.5, 0));
		}
		if (Player_Boxs[2].intersects(Invisible_wall_box[i]))
		{
			Player_box->setPosition(sf::Vector2f(Player_box->getPosition().x, Walls[i].getPosition().y + 135));
		}
		if (Player_Boxs[3].intersects(Invisible_wall_box[i]))
		{
			Player_box->move(sf::Vector2f(7.5, 0));
		}
		if (Player_Boxs[2].intersects(Rectangle_Box) || Player_Boxs[2].intersects(Invisible_wall_box[i]))
		{
			jumping = false;
			moving = 1;
			gravitationbo = true;
		}
	}
	/******************************************************************************************************************************/
	for (int i = 0; i < number_of_spikes; i++)
	{
		if (Player_Boxs[0].intersects(Spike_box[i]))
		{
			life = 0;
		}
		else if (Player_Boxs[1].intersects(Spike_box[i]))
		{
			life = 0;
		}
		else if (Player_Boxs[2].intersects(Spike_box[i]))
		{
			life = 0;
		}
		else if (Player_Boxs[3].intersects(Spike_box[i]))
		{
			life = 0;
		}
	}
	for (int i = 0; i < number_of_portals; i++)
	{
		if (Player_Boxs[0].intersects(Portal_box[i]))
		{
			game = false;
			new_game = true;
			if (lvl1 == true)
			{
				lvl1 = false;
				lvl2 = true;
			}
			else if (lvl2 == true)
			{
				lvl2 = false;
				lvl3 = true;
			}
			else if (lvl3 == true)
			{
				lvl3 = false;
				new_game = false;
				game = false;
			}
		}
		if (Player_Boxs[1].intersects(Portal_box[i]))
		{
			game = false;
			new_game = true;
			if (lvl1 == true)
			{
				lvl3 = false;
				lvl1 = false;
				lvl2 = true;
			}
			else if (lvl2 == true)
			{
				lvl2 = false;
				lvl3 = true;
			}
			else if (lvl3 == true)
			{
				lvl3 = false;
				new_game = false;
				game = false;
			}
		}
		if (Player_Boxs[2].intersects(Portal_box[i]))
		{
			game = false;
			new_game = true;
			if (lvl1 == true)
			{
				lvl1 = false;
				lvl2 = true;
			}
			else if (lvl2 == true)
			{
				lvl2 = false;
				lvl3 = true;
			}
			else if (lvl3 == true)
			{
				lvl3 = false;
				new_game = false;
				game = false;
			}
		}
		if (Player_Boxs[3].intersects(Portal_box[i]))
		{
			game = false;
			new_game = true;
			if (lvl1 == true)
			{
				lvl1 = false;
				lvl2 = true;
			}
			else if (lvl2 == true)
			{
				lvl2 = false;
				lvl3 = true;
			}
			else if (lvl3 == true)
			{
				lvl3 = false;
				new_game = false;
				game = false;
			}
		}
	}
	for (int i = 0; i < number_of_enemies; i++)
	{
		if (Enemies[i].be == true) // enemy colission
		{
			if (Middle_Box.intersects(Enemies[i].Rectangle[0].getGlobalBounds()))
			{
				Enemies[i].move_right = false;
				Enemies[i].Enemy_sp.setScale(-2.f, 2.f);
				Enemies[i].movingbo = true;
				Enemies[i].anim = true;
			}
			else if (Middle_Box.intersects(Enemies[i].Rectangle[1].getGlobalBounds()))
			{
				Enemies[i].move_right = true;
				Enemies[i].Enemy_sp.setScale(2.f, 2.f);
				Enemies[i].movingbo = true;
				Enemies[i].anim = true;
			}
			else
			{
				Enemies[i].movingbo = false;
				Enemies[i].anim = false;
				Enemies[i].Enemy_sp.setTexture(Enemies[i].Enemy_txt[0]);
			}
			if (Player_Boxs[1].intersects(Enemies[i].Player_Rect[3].getGlobalBounds()) || Player_Boxs[0].intersects(Enemies[i].Player_Rect[3].getGlobalBounds()))
			{
				knockback = true;
				grounded = false;
				Enemies[i].Hit.play();
			}
			if (Player_Boxs[0].intersects(Enemies[i].Player_Rect[2].getGlobalBounds()))
			{
				knockback = true;
				grounded = false;
				upper = true;
				Enemies[i].Hit.play();
			}
			if (Player_Boxs[3].intersects(Enemies[i].Player_Rect[1].getGlobalBounds()))
			{
				knockback = true;
				grounded = false;
				rightr = true;
				Enemies[i].Hit.play();
			}
			if (Excalibur.intersects(Enemies[i].Player_Rect[3].getGlobalBounds()))
			{
				if (fight_two == true)
				{
					Enemies[i].knockbackbo = true;
					Enemies[i].knockleft = true;
					Enemies[i].gravitationbo = false;
					Enemies[i].movingbo = false;
					Hit_s.play();
				}
			}
			if (Excalibur.intersects(Enemies[i].Player_Rect[1].getGlobalBounds()))
			{
				if (fight_two == true)
				{
					Enemies[i].knockbackbo = true;
					Enemies[i].knockright = true;
					Enemies[i].gravitationbo = false;
					Enemies[i].movingbo = false;
					Hit_s.play();
				}
			}
			for (int j = 0; j < number_of_platforms; j++)
			{
				if (Enemies[i].Player_Rect[0].getGlobalBounds().intersects(Platform_box[j]))
				{
					Enemies[i].gravitationbo = false;
					Enemies[i].Enemy_sp.setPosition(sf::Vector2f(Enemies[i].Enemy_sp.getPosition().x, Enemies[i].Enemy_sp.getPosition().y - 20));
					Enemies[i].Enemy_sp.setColor(sf::Color::White);
				}
			}
		}
	}
}
void Player::animations()
{
	if (idling == true)
	{
		if ((steps++) % 5 == 1)
		{
			i++;
			Player_box->setTexture(idle[i]);
			if (i == 5)
			{
				i = -1;
			}
		}
	}
	else if (running == true && grounded == true)
	{
		if (left == true)
		{
			Player_box->setScale(-3.f, 3.f); // fliping a texture
		}
		else if (left == false)
		{
			Player_box->setScale(3.f, 3.f); // fliping a texture
		}
		if ((steps++) % 5 == 1)
		{
			j++;
			Player_box->setTexture(Run[j]);
			if (j == 7)
			{
				j = -1;
			}
		}
	}
	else if (jumping == true)
	{
		Player_box->setTexture(Jump[3]);
		if (left == true)
		{
			Player_box->setScale(-3.f, 3.f); // fliping a texture
		}
		else if (left == false)
		{
			Player_box->setScale(3.f, 3.f); // fliping a texture
		}
	}
	else if (fight == true)
	{
		able = false;
		if ((steps++) % 5 == 1)
		{
			a++;
			Player_box->setTexture(Attack[a]);
			if (a == 5)
			{
				fight_two = true;
				Miss_s.play();
				fighting();
			}
			if (a == 9)
			{
				able = true;
				fight_two = false;
				a = -1;
				fight = false;
				fighting();
				idling = true;
			}
		}
	}
	else if (death == true && be == true)
	{
		able = false;
		colissionb = true;
		gravitationbo = true;
		Player_box->setColor(sf::Color::White);
		if ((steps++) % 5 == 1)
		{
			d++;
			Player_box->setTexture(Die[d]);
			if (d == 18)
			{
				d = -1;
				be = false;
			}
		}
	}
}
void Player::knockback_fun()
{
	if (upper == true)
	{
		if (knockknock == 1)
		{
			Player_box->move(-7.5, -7.5);
		}
		else
		{
			Player_box->move(7.5, -7.5);
		}
	}
	else if (rightr == true)
	{
		Player_box->move(7.5, -7.5);
	}
	else
	{
		Player_box->move(-7.5, -7.5);
	}
	colissionb = false;
	gravitationbo = false;
	able = false;
}
void inline Player::knockback_detection()
{
	knockback = false;
	colissionb = true;
	gravitationbo = true;
}
void Player::fighting()
{
	sword.rotate(90);
}
void Player::check_life()
{
	if (life == 100)
	{
		health_bar.setSize(sf::Vector2f(life, 10));
	}
	else if (life == 75)
	{
		health_bar.setSize(sf::Vector2f(life, 10));
	}
	else if (life == 50)
	{
		health_bar.setSize(sf::Vector2f(life, 10));
	}
	else if (life == 25)
	{
		health_bar.setSize(sf::Vector2f(life, 10));
	}
	else if (life <= 0 && death == false)
	{
		health_bar.setSize(sf::Vector2f(life, 10));
		death = true;
		fight = false;
		idling = false;
		running = false;
	}
}
