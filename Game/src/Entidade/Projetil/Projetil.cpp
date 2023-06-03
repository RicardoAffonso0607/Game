#include "pch.h"
#include "Entidade/Projetil/Projetil.h"

Projetil::Projetil() :
	attacker(true),
	movable(true),
	damageable(false),
	ghost(true)
{
}

Projetil::~Projetil()
{
}
