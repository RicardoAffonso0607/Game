#include "pch.h"
#include "Entidade/Obstaculo/Obstaculo.h"

Obstaculo::Obstaculo(sf::Vector2f pos, int id) : Entidade(id)
{
	this->pos = pos;
}

Obstaculo::~Obstaculo()
{
}

void Obstaculo::move()
{
}

void Obstaculo::attack()
{
}