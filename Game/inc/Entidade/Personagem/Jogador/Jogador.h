#pragma once

#include "../Personagem.h"

class Jogador : public Personagem
{
private:

public:
	Jogador(sf::Vector2f pos, int id, int life);
	~Jogador();

	void move();
	void atack();

	sf::Vector2f getPos() { return pos; }
};

