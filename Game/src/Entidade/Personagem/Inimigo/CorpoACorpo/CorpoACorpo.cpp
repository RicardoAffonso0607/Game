#include "pch.h"
#include "Entidade/Personagem/Inimigo/CorpoACorpo/CorpoACorpo.h"

namespace Inimigos {
	CorpoACorpo::CorpoACorpo()
	{
		movable = true;
		attacker = true;
		retarder = false;
		damageable = true;

		this->life = 20;

		body.setFillColor(sf::Color::Red);
		body.setPosition(pos);
	}

	CorpoACorpo::~CorpoACorpo()
	{

	}

	void CorpoACorpo::move()
	{
		if (pPlayer)
		{
			//body.move((float)pos.x - pPlayer->getPos().x, (float)pos.y - pPlayer->getPos().y);
		}
	}

	void CorpoACorpo::attack()
	{

	}
}