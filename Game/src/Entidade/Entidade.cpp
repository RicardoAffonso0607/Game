#include "pch.h"
#include "Entidade/Entidade.h"
#include "Gerenciador/Grafico.h"

Entidade::Entidade(bool mov, bool dam, bool pro, bool gho) :
	movable(mov),
	damageable(dam),
	projected(pro),
	ghost(gho)
{
}

Entidade::~Entidade()
{
}

Entidade::draw() {
	pGerGraf->desenhaElemento(body);
}

sf::Vector2f Entidade::getPosition() = 0;
sf::Vector2f Entidade::getEntSize() = 0;
sf::Vector2f Entidade::getVel() = 0;
sf::Vector2f Entidade::getVelMax() = 0;

void Entidade::move() = 0;
void Entidade::attack() = 0;
void Entidade::gunType() = 0;
void Entidade::setPlayer() = 0;
void Entidade::changePosition() = 0;
void Entidade::subtractLife() = 0;
void Entidade::subtractVelocity() = 0;
void Entidade::setAttacker() = 0;
void Entidade::getGun() = 0;
void Entidade::events() = 0;
void Entidade::setAtacou() = 0;
void Entidade::setPlayer() = 0;
void Entidade::setCaster() = 0;

bool Entidade::getMovable() = 0;
bool Entidade::getAttacker() = 0;
bool Entidade::getRetardant() = 0;
bool Entidade::getDamageable() = 0;
bool Entidade::getJumped() = 0;
bool Entidade::getFacingLeft() = 0;
bool Entidade::getProjetil() = 0;

int Entidade::getDamage() = 0;

float Entidade::getSlowness();
float Entidade::getMass() = 0;
float Entidade::getJumpStrength() = 0;