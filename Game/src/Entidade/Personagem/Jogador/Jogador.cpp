#include "pch.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

Jogador::Jogador(sf::Vector2f pos, int id, int life) : Personagem(pos, id)
{
	this->movable = true;
	this->attacker = false;
	this->retarder = false;
	this->damageable = true;

	this->life = life;
	this->damage = 0;

	body.setFillColor(sf::Color::Blue);
	body.setPosition(pos);
	


}

Jogador::~Jogador()
{
}

void Jogador::move()
{
	if(attack_delay)
		this->attack_delay--;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))//Direita
		body.move(sf::Vector2f(2.f, 0.f));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))//Esquerda
		body.move(sf::Vector2f(-2.f, 0.f));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))//Cima
		body.move(sf::Vector2f(0.f, -2.f));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))//Baixo
		body.move(sf::Vector2f(0.f, 2.f));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		this->jumped = true;
}

void Jogador::attack()
{
	if (!this->attack_delay) {
		if (sf::Keyboard::isKeyPressed(sf::Mouse::Left)) {
			this->attacker = true;
			this->damage = 10;
			this->attack_delay = 100;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			this->attacker = true;
			this->damage = 20;
			this->attack_delay = 200;
		}
	}
	else
		this->attacker = false;
}
