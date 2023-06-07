#include "pch.h"
#include "Entidade/Arma/Espada.h"

namespace Armas {
	const int Espada::damage = 30;// dano que causa
	
	const unsigned int Espada::id = 93;

	Espada::Espada(sf::Vector2f pos) :
		attacker(false),
		pColidiu(nullptr)
	{
		textura.loadFromFile(string(IMG) + "Espada.png");
		body.setTexture(&textura);
		body.setPosition(pos);
		body.setSize(sf::Vector2f(40.f, 130.f));
		swoosh.loadFromFile(string(SFX) + "sword-slash.wav");
		sfx.setBuffer(swoosh);
		hit.loadFromFile(string(SFX) + "sword-hit.wav");
		sfx2.setBuffer(hit);
		if (facing_left)
			body.setRotation(angle);
		else
			body.setRotation(-angle);
	}

	Espada::~Espada()
	{
	}

	bool Espada::getAttacker() const
	{
		return attacker;
	}

	int Espada::getDamage() const
	{
		return damage;
	}

	unsigned int Espada::getId() const
	{
		return id;
	}

	void Espada::attack()
	{
		if (facing_left)
			body.setRotation(-angle);
		else
			body.setRotation(angle);
		angle += 20.f;
		if (angle > 60.f)
			angle = 40.f;
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