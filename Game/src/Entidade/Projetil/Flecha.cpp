#include "pch.h"
#include "Entidade/Projetil/Flecha.h"

namespace Projeteis {
	Flecha::Flecha(sf::Vector2f pos)
	{
		body.setSize(sf::Vector2f(30.f, 10.f));
		body.setPosition(pos);
	}

	Flecha::~Flecha()
	{
	}
	
	int Flecha::getDamage() const
	{
		return damage;
	}

	Arma* Flecha::getGun()
	{
		return pGun;
	}

	void Flecha::setGun(Arma* gun)
	{
		pGun = gun;
	}
}
