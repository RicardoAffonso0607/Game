#include "pch.h"
#include "Entidade/Entidade.h"

Gerenciador::Grafico* Entidade::pGerGraf(nullptr);

Entidade::Entidade()
{
}

Entidade::~Entidade()
{
}

void Entidade::setGerGraf(Gerenciador::Grafico* pauxGerGraf)
{
	pGerGraf = pauxGerGraf;
}

void Entidade::draw() {
	pGerGraf->desenhaElemento(body);
}

void Entidade::changePosition(sf::Vector2f dif_pos)
{
	body.move(dif_pos);
}

sf::Vector2f Entidade::getPosition() const
{
	return body.getPosition();
}

sf::Vector2f Entidade::getEntSize() const
{
	return body.getSize();
}

sf::Vector2f Entidade::getVel() const
{
	throw std::runtime_error("Solicitou velocidade de entidade fixa.");
}

void Entidade::move()
{
	throw std::runtime_error("Tentou mover entidade fixa.");
}

void Entidade::attack()
{
	throw std::runtime_error("Tentou fazer entidade n�o atacante atacar.");
}

float Entidade::getMass() const
{
	string errou = "Solicitou massa de entidade que n�o � afetada pela gravidade.";
	cerr << errou << endl;
	//throw std::runtime_error(errou);
	return 1.f;
}

int Entidade::getDamage() const
{
	throw std::runtime_error("Solicitou dano de entidade n�o atacante.");
}

float Entidade::getSlowness() const
{
	throw std::runtime_error("Solicitou lentid�o de entidade n�o retardante.");
}

float Entidade::getJumpStrength() const
{
	throw std::runtime_error("Solicitou for�a do pulo de entidade que n�o pula.");
}

bool Entidade::getJumped() const
{
	//throw std::runtime_error("Solicitou estado do pulo de entidade que n�o pula.");
	return false;
}

bool Entidade::getFacingLeft() const
{
	throw std::runtime_error("Solicitou dire��o da mira de entidade im�vel.");
}

void Entidade::applyDamage(int damage)
{
	throw std::runtime_error("Tentou aplicar dano em entidade n�o danific�vel.");
}

void Entidade::applySlowness(float slowness)
{
	throw std::runtime_error("Tentou retardar entidade que n�o � afetada pela lentid�o.");
}


//void Entidade::gunType() {}
//void Entidade::setAttacker() {}
//void Entidade::getGun() {}
//void Entidade::events() {}
//void Entidade::setAtacou() {}
//void Entidade::setCaster() {}
//void Entidade::setPlayer() {}