#include "pch.h"
#include "Entidade/Entidade.h"

Entidade::Entidade(int id) : pos(0.f, 0.f), body(sf::Vector2f(100.f, 100.f)), pWindow(NULL), Ente()
{
	this->id = id;

	this->movable = false;
	this->retarder = false;
	this->attacker = false;
	this->damageable = false;
}

Entidade::~Entidade()
{
}
