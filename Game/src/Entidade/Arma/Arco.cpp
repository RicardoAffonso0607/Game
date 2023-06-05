#include "pch.h"
#include "Entidade/Arma/Arco.h"

namespace Armas {
	const bool Arco::attacker = false;// é atacante?

	const unsigned int Arco::id = 91;

	Arco::Arco(sf::Vector2f pos)
	{
		body.setPosition(pos);
		body.setSize(sf::Vector2f(8.f, 20.f));
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
		if (facing_left) {
			flecha = new Projeteis::Flecha(body.getPosition());
			flecha->setEsquerda();
		}
		else {
			flecha = new Projeteis::Flecha(body.getPosition());
			flecha->setDireita();
		}
	}
}