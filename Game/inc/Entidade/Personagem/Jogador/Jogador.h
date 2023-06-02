#pragma once

#include "Entidade/Personagem/Personagem.h"

class Jogador : public Personagem
{
private:

public:
	Jogador();
	virtual ~Jogador();
	void move();
	void attack();
	sf::Vector2f getPos() { return pos; }
	sf::Texture textura;
};