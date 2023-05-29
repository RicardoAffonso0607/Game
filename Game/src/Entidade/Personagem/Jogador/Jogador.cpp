#include "pch.h"
#include "../../../../inc/Entidade/Personagem/Jogador/Jogador.h"

Jogador::Jogador(sf::Vector2f pos, int id, int life) : Personagem(pos, id), paraDireita(true), 
	podeMover(false), podePular(false)
{
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
	if (podeMover)
	{
		if (paraDireita)
		{
			body.move(5.f, 0.f);
			podeMover = false;
		}
		else
		{
			body.move(-5.f, 0.f);
			podeMover = false;
		}
	}

	if (podePular)
	{
		if (paraCima)
		{
			body.move(0.f, -5.f);
			podePular = false;
		}
		else
		{
			body.move(0.f, 5.f);
			podePular = false;
		}
	}
}


void Jogador::attack()
{

}

