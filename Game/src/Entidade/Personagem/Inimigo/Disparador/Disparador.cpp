#include "pch.h"
#include "Entidade/Personagem/Inimigo/Disparador/Disparador.h"
#include "Entidade/Projetil/Projetil.h"

namespace Inimigos {
	Disparador::Disparador()
	{
		movable = true;
		attacker = true;
		retarder = false;
		damageable = true;

		//magic = nullptr;
		this->life = 50;
		this->damage = 0;

		body.setFillColor(sf::Color::Magenta);
		body.setPosition(pos);
	}

	Disparador::~Disparador()
	{

	}

	void Disparador::move()
	{

	}

	void Disparador::attack()
	{
		//magic = new Projetil(sf::Vector2f(pos.x, pos.y), 10);
		//magic->setCaster(this);
	}
}