#include "stdafx.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

Jogador::Jogador()
{
	body.setFillColor(sf::Color::Blue);
	body.setPosition(sf::Vector2f(50.f, 50.f));

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

