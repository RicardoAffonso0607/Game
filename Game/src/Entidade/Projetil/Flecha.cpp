#include "pch.h"
#include "Entidade/Projetil/Flecha.h"

namespace Projeteis {
	const int Flecha::damage = 10;

	const unsigned int Flecha::id = 83;

	Flecha::Flecha(sf::Vector2f pos)
	{
		textura.loadFromFile(string(IMG) + "Flecha.png");
		body.setTexture(&textura);
		body.setSize(sf::Vector2f(40.f, 15.f));
		body.setPosition(pos);
	}

	Flecha::~Flecha()
	{
	}

	float Flecha::getMass() const
	{
		return mass;
	}
	
	int Flecha::getDamage() const
	{
		return damage;
	}

	unsigned int Flecha::getId() const
	{
		return id;
	}

	void Flecha::move()
	{
		if (facing_left)
			body.move(sf::Vector2f(-vel.x, 0.f));
		else
			body.move(sf::Vector2f(vel.x, 0.f));
		cout << (this->colidiu ? 1 : 0) << endl;
		if (this->colidiu) {
			cout << "perfurou" << endl;
			this->attack();
			this->pColidiu = nullptr;
		}
	}

	void Flecha::attack()
	{
		if (this->pColidiu->getDamageable())
			this->pColidiu->applyDamage(this->damage);
		cout << "perfurou" << endl;
		this->life = 0;
	}

	void Flecha::setEntColidiu(Entidade* pauxColidiu)
{
	pColidiu = pauxColidiu;
}

	void Flecha::setColidiu()
	{
		this->colidiu = true;
	}
}
