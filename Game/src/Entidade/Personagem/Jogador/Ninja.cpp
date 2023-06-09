#include "pch.h"
#include "Entidade/Personagem/Jogador/Ninja.h"

namespace Jogadores {
	const unsigned int Ninja::id = 1;

	float Ninja::mass = .9f;

	const sf::Vector2f Ninja::vel_max = sf::Vector2f(12.f, 15.f);

	Ninja::Ninja(sf::Vector2f pos, int pl_life) : Jogador(vel_max)
	{
		life = pl_life;
		vel = vel_max;
		textura.loadFromFile(string(IMG) + "Ninja1.png");
		body.setTexture(&textura);
		body.setSize(sf::Vector2f(110.f, 180.f));
		body.setPosition(pos);
	}

	Ninja::~Ninja()
	{
	}

	unsigned int Ninja::getId() const
	{
		return id;
	}

	float Ninja::getMass() const
	{
		if (god_mode)
			mass = 0.f;
		return mass;
	}

	void Ninja::move()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {//Direita
			body.move(vel.x, 0.f);
			facing_left = false;
			sf::Listener::setDirection(1.f, 0.f, 0.f);
			body.setOrigin(0.f, 0.f);
			body.setScale(1.f, 1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {//Esquerda
			body.move(-vel.x, 0.f);
			facing_left = true;
			sf::Listener::setDirection(-1.f, 0.f, 0.f);
			body.setOrigin(body.getSize().x, 0.f);
			body.setScale(-1.f, 1.f);
		}
		if (god_mode) {
			if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up))//Cima
				body.move(0.f, -vel.y);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))//Baixo
				body.move(0.f, vel.y);
		}
		executar();
	}

	bool Ninja::getJumped() const
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			return true;
		else
			return false;
	}

	void Ninja::attack()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Period))
			attack_single();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Comma))
			attack_burst();
	}
}