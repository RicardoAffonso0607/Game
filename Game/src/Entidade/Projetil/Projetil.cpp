#include "pch.h"
#include "Entidade/Projetil/Projetil.h"

namespace Projetil {
	Projetil::Projetil(sf::Vector2f pos, int id) : Entidade(id), damage(20)
	{
		movable = true;
		attacker = true;
		retarder = false;
		damageable = false;
		projected = true;

		this->pos = pos;
		caster = nullptr;
	}

	Projetil::~Projetil()
	{
		caster = nullptr;
	}

	void Projetil::move()
	{
	}

	void Projetil::attack()
	{
	}
}