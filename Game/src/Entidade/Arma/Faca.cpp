#include "pch.h"
#include "Entidade/Arma/Faca.h"

namespace Armas {
	const int Faca::damage = 2;// dano que causa

	const unsigned int Faca::id = 92;

	Faca::Faca(sf::Vector2f pos) :
		attacker(false),
		pColidiu(nullptr)
	{
		textura.loadFromFile(string(IMG) + "Faca.png");
		body.setTexture(&textura);
		body.setPosition(pos);
		body.setSize(sf::Vector2f(10.f, 3.f));
		swoosh.loadFromFile(string(SFX) + "knife-swoosh.wav");
		sfx.setBuffer(swoosh);
		hit.loadFromFile(string(SFX) + "knife-hit.wav");
		sfx2.setBuffer(hit);
	}

	Faca::~Faca()
	{
	}

	bool Faca::getAttacker() const
	{
		return attacker;
	}

	int Faca::getDamage() const
	{
		return damage;
	}

	unsigned int Faca::getId() const
	{
		return id;
	}

	void Faca::attack()
	{
		sfx.setPosition(sf::Vector3f(body.getPosition().x, 0.f, body.getPosition().y));
		sfx2.setPosition(sf::Vector3f(body.getPosition().x, 0.f, body.getPosition().y));
		if (colidiu && pColidiu && pColidiu->getDamageable()) {
			pColidiu->applyDamage(damage);
			sfx.play();
		}
		else
			sfx2.play();
		colidiu = false;
		pColidiu = nullptr;
	}
}