#include "pch.h"
#include "../../../inc/Entidade/Personagem/Personagem.h"

Personagem::Personagem(sf::Vector2f pos, int id) : Entidade(id), life(100), vel_x(0), vel_y(0), vel_max_x(5), vel_max_y(5)
{
	//Testar os valores da velocidade
	this->pos = pos;
}

Personagem::~Personagem()
{
}
