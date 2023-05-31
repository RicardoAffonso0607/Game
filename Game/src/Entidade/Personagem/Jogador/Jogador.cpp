#include "pch.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

Jogador::Jogador(sf::Vector2f pos, int id, int life) : Personagem(pos, id)
{
	this->movable = true;
	this->attacker = true;
	this->retarder = false;
	this->damageable = true;

	this->life = life;
	this->damage = 0;
	this->retard = 5;
	this->vel_x = this->vel_max_x;
	this->vel_y = this->vel_max_y;
	body.setFillColor(sf::Color::Blue);
	body.setPosition(pos);

	body.setFillColor(sf::Color::Blue);
	body.setPosition(pos);
	


}

Jogador::~Jogador()
{
}

void Jogador::move()
{
	if (attack_delay)
		this->attack_delay--;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {//Direita
		body.move(sf::Vector2f(this->vel_x, 0.f));
		this->facingLeft = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {//Esquerda
		body.move(sf::Vector2f(-this->vel_x, 0.f));
		this->facingLeft = true;
	}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))//Cima
		//body.move(sf::Vector2f(0.f, -this->vel_y));
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))//Baixo
		//body.move(sf::Vector2f(0.f, this->vel_y));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) /* && !this->flying*/)
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

