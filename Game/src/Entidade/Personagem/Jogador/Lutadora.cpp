#include "pch.h"
#include "Entidade/Personagem/Jogador/Lutadora.h"

namespace Jogadores {
	const unsigned int Lutadora::id = 2;

	float Lutadora::mass = .6f;

	const sf::Vector2f Lutadora::vel_max = sf::Vector2f(12.f, 15.f);

	Lutadora::Lutadora(sf::Vector2f pos, int pl_life) : Jogador(vel_max)
	{
		life = pl_life;
		vel = vel_max;
		textura.loadFromFile(string(IMG) + "Lutadora1.png");
		body.setTexture(&textura);
		body.setSize(sf::Vector2f(150.f, 230.f));
		body.setPosition(pos);
	}

	Lutadora::~Lutadora()
	{
	}

	unsigned int Lutadora::getId() const
	{
		return id;
	}

	float Lutadora::getMass() const
	{
		if (god_mode)
			mass = 0.f;
		return mass;
	}
}