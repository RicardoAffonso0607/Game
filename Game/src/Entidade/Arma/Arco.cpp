#include "pch.h"
#include "Entidade/Arma/Arco.h"

namespace Armas {
	const bool Arco::attacker = false;// é atacante?

	const unsigned int Arco::id = 91;

	Arco::Arco(sf::Vector2f pos) :
		flecha(nullptr)
	{
		body.setPosition(pos);
		body.setSize(sf::Vector2f(20.f, 50.f));
	}

	Arco::~Arco()
	{
	}

	void move()
	{
	}

	unsigned int Arco::getId() const
	{
		return id;
	}

	void Arco::attack()
	{
		flecha = new Projeteis::Flecha(body.getPosition());
		if (facing_left) {
			flecha->setEsquerda();
			flecha->changePos(sf::Vector2f(-flecha->getEntSize().x, .5f*body.getSize().y - flecha->getEntSize().y));
		}
		else {
			flecha->setDireita();
			flecha->changePos(sf::Vector2f(flecha->getEntSize().x, .5f*body.getSize().y - flecha->getEntSize().y));
		}
	}

	bool Arco::getAttacker() const
	{
		return attacker;
	}
}