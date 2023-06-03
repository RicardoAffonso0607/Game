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

sf::Vector2f Entidade::getPosition() {}
sf::Vector2f Entidade::getEntSize() {}
sf::Vector2f Entidade::getVel() {}
sf::Vector2f Entidade::getVelMax() {}

void Entidade::move() {}
void Entidade::attack() {}
void Entidade::gunType() {}
void Entidade::setPlayer() {}
void Entidade::changePosition() {}
void Entidade::subtractLife() {}
void Entidade::subtractVelocity() {}
void Entidade::setAttacker() {}
void Entidade::getGun() {}
void Entidade::events() {}
void Entidade::setAtacou() {}
void Entidade::setPlayer() {}
void Entidade::setCaster() {}

bool Entidade::getMovable() {}
bool Entidade::getAttacker() {}
bool Entidade::getRetardant() {}
bool Entidade::getDamageable() {}
bool Entidade::getJumped() {}
bool Entidade::getFacingLeft() {}
bool Entidade::getProjetil() {}

int Entidade::getDamage() {}

float Entidade::getSlowness() {}
float Entidade::getMass() {}
float Entidade::getJumpStrength() {}