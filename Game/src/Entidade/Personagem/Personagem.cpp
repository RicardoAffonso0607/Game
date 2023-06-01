#include "pch.h"
#include "Entidade/Personagem/Personagem.h"

Personagem::Personagem(sf::Vector2f pos, int id) : Entidade(id)
{
	this->pos = pos;
	this->life = 100;
	this->damage = 5;
	this->retard = 0;
}

Personagem::~Personagem()
{

}