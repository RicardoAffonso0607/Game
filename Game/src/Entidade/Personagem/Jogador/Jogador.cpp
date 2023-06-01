#include "pch.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Jogador {
	Jogador::Jogador(sf::Vector2f pos, int id, float life) : Personagem(pos, id)
	{
		movable = true;
		attacker = true;
		retarder = false;
		damageable = true;
		life = life;
		damage = 0;
		retard = 5;
		vel = vel_max;
		//body.setFillColor(sf::Color::Blue);

	}

	Jogador::~Jogador()
	{

	}

	void Jogador::move()
	{
		if (attack_delay)
			this->attack_delay--;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {//Direita
			body.move(sf::Vector2f(this->vel.x, 0.f));
			this->facingLeft = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {//Esquerda
			body.move(sf::Vector2f(-this->vel.x, 0.f));
			this->facingLeft = true;
		}
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))//Cima
			//body.move(sf::Vector2f(0.f, -this->vel.y));
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))//Baixo
			//body.move(sf::Vector2f(0.f, this->vel.y));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			this->jumped = true;
	}

	void Jogador::attack()
	{
		if (!this->attack_delay) {
			if (sf::Mouse::Left) {
				this->attacker = true;
				this->damage = 10;
				this->attack_delay = 100;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backslash)) {
				this->attacker = true;
				this->damage = 20;
				this->attack_delay = 200;
			}
		}
		else
			this->attacker = false;
	}
}