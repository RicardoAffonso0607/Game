#include "pch.h"
#include "Entidade/Personagem/Inimigo/Chefao/Chefao.h"

namespace Inimigos {
	Chefao::Chefao()
	{
		movable = true;
		attacker = true;
		retarder = false;
		damageable = true;

		this->life = 100;
		this->damage = 10;

		body.setFillColor(sf::Color::White);
		body.setPosition(pos);
	}

	Chefao::~Chefao()
	{
	}

	void Chefao::move()
	{
	}

	void Chefao::attack()
	{
	}
}
