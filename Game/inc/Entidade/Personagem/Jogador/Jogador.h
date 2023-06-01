#pragma once

#include "Entidade/Personagem/Personagem.h"

class Jogador : public Personagem
{
private:

public:
	Jogador(sf::Vector2f pos, int id, float life);
	~Jogador();
	void move();
	void attack();
	sf::Vector2f getPos() { return pos; }
};