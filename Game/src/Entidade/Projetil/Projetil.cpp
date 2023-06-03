#include "pch.h"
#include "Entidade/Projetil/Projetil.h"

Projetil::Projetil() :
	pInimigo(nullptr),
	pArma(nullptr),
	attacker(true),
	movable(true),
	damageable(false),
	ghost(true)
{
}

Projetil::~Projetil()
{
}
