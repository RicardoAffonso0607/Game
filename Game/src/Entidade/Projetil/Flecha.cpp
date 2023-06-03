#include "pch.h"
#include "Entidade/Projetil/Flecha.h"

namespace Projeteis {
	Flecha::Flecha(sf::Vector2f pos, int id) :
		damage(10),
		id(83),
		pGun(nullptr)
	{
		body.setSize(sf::Vector2f(30.f, 10.f));
		body.setPosition(pos);
	}

	Flecha::~Flecha()
	{
	}
	
	int Flecha::getDamage()
	{
		return damage;
	}

	Arma* Flecha::getGun()
	{
		return pGun;
	}

	void Flecha::setGun(Armas* gun)
	{
		pGun = gun;
	}
}
