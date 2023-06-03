#include "pch.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

Jogador::Jogador() :
	attacker(false),
	pontuacao(NULL),
	damage(NULL)
	pArma(nullptr)
{
}

Jogador::~Jogador()
{
}

void Jogador::setAttacker(int gun_type, int attack_type)
{
	if (!attack_delay) {
		if (attack_type == ATQ_LONGO) {
			attacker = true;
			attack_delay = gun->getDelay();
			attack_instant = clock.getElapsedTime();
		}
		else if (attack_type == ATQ_CURTO) {
			attacker = true;
			attack_delay = 2*gun->getDelay();
			attack_instant = clock.getElapsedTime();
		}
	}
}

float Jogador::getJumpStrength()
{
	return jump_strength;
}

bool Jogador::getJumped()
{ 
	return jumped;
}

void setGun(Arma* pArma) {
	delete pArma;
	pArma = gun_load;
}