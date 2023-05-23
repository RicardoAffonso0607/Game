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

	body.setFillColor(sf::Color::Blue);
	body.setPosition(pos);
	


}

Jogador::~Jogador()
{
}

void Jogador::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) //Direita
		body.move(sf::Vector2f(2.f, 0.f));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //Esquerda
		body.move(sf::Vector2f(-2.f, 0.f));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //Cima
		body.move(sf::Vector2f(0.f, -2.f));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) //Baixo
		body.move(sf::Vector2f(0.f, 2.f));

}

void Jogador::atack()
{

}

