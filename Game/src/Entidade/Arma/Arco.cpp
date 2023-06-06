#include "pch.h"
#include "Entidade/Arma/Arco.h"

namespace Armas {
	const bool Arco::attacker = false;// é atacante?

	const unsigned int Arco::id = 91;

	Arco::Arco(sf::Vector2f pos, ListaEntidades* list) :
		flecha(nullptr),
		list_ent(list)
	{
		list_ent->clear();

		body.setPosition(pos);
		body.setSize(sf::Vector2f(20.f, 50.f));
		bow_release.loadFromFile(string(SFX) + "bow-release.wav");
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
		flecha->setGerGraf(pGerGraf);
		list_ent->push(flecha);
		if (facing_left) {
			flecha->setEsquerda();
			flecha->changePos(sf::Vector2f(-flecha->getEntSize().x, .5f*body.getSize().y - flecha->getEntSize().y));
		}
		else {
			flecha->setDireita();
			flecha->changePos(sf::Vector2f(flecha->getEntSize().x, .5f*body.getSize().y - flecha->getEntSize().y));
		}
		sfx.setBuffer(bow_release);
		sfx.play();
	}

	bool Arco::getAttacker() const
	{
		return attacker;
	}
}