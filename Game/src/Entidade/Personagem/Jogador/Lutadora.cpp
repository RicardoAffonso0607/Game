#include "pch.h"
#include "Entidade/Personagem/Jogador/Lutadora.h"

namespace Jogadores {
	Lutadora::Lutadora(sf::Vector2f pos, float pl_life, int id) :
		size(sf::Vector2f(100.f, 140.f)),
		vel(sf::Vector2f(12.f, 15.f)),
		life(pl_life)
		mass(.6f)
	{
		textura.loadFromFile(IMG + "teste.png");
		body.setTexture(&textura);
		body.setSize(size);
		body.setPosition(pos);
	}

	Lutadora::~Lutadora()
	{

	}
}