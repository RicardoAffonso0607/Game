#include "pch.h"
#include "Entidade/Personagem/Jogador/Lutadora.h"

namespace Jogadores {
	Lutadora::Lutadora(sf::Vector2f pos, int id, float life)
	{
		vel = sf::Vector2f(10.f, 2.f);
		textura.loadFromFile("Game/assets/img/teste.png");
		body.setTexture(&textura);
		body.setPosition(pos);
	}

	Lutadora::~Lutadora()
	{

	}
}