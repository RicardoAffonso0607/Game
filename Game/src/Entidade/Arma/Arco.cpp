#include "pch.h"
#include "Entidade/Arma/Arco.h"

namespace Armas {
	const bool Arco::attacker = false;// é atacante?

	const unsigned int Arco::id = 91;

	const float Arco::cast_height = .5f;// altura do disparo

	Arco::Arco(sf::Vector2f pos, ListaEntidades* list) :
		flecha(nullptr),
		list_ent(list)
	{
		textura.loadFromFile(string(IMG) + "bow.png");
		body.setTexture(&textura);
		body.setPosition(pos);
		body.setSize(sf::Vector2f(60.f, 200.f));
		bow_release.loadFromFile(string(SFX) + "bow-release.wav");
		sfx.setBuffer(bow_release);
	}

	Arco::~Arco()
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
			flecha->changePos(sf::Vector2f(-flecha->getEntSize().x, cast_height*body.getSize().y - flecha->getEntSize().y));
		}
		else {
			flecha->setDireita();
			flecha->changePos(sf::Vector2f(flecha->getEntSize().x, cast_height*body.getSize().y - flecha->getEntSize().y));
		}
		sfx.setPosition(sf::Vector3f(flecha->getPos().x, 0.f, flecha->getPos().y));
		sfx.play();
	}

	bool Arco::getAttacker() const
	{
		return attacker;
	}
}