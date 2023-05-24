#include "pch.h"
#include "Entidade/Obstaculos/Plataforma.h"

Plataforma::Plataforma(sf::Vector2f pos, int id) : Obstacles(pos, id) {
	this->movable = false;
	this->attacker = false;
	this->retarder = false;
	this->damageable = false;
	body.setSize(sf::Vector2f(600.0f, 10.0f));
	body.setFillColor(sf::Color::Yellow);
	body.setPosition(pos);
}

Plataforma::~Plataforma(){
}
