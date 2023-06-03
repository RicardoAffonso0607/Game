#include "pch.h"
#include "Entidade/Plataforma/Plataforma.h"

Plataforma::Plataforma() :
	movable(false),
	retardant(false),
	damageable(false),
	attacker(false),
	projected(false)
{
}

Plataforma::~Plataforma()
{
}