#include "pch.h"
#include "Entidade/Personagem/Personagem.h"

Personagem::Personagem(sf::Vector2f pos, int id) : Entidade(id), life(100), vel_x(0), vel_y(0), damage(5), retard(0), vel_max_x(5.f), vel_max_y(5.f)
{
	//Testar os valores da velocidade e dano
	this->pos = pos;
}

Personagem::~Personagem()
{
}
