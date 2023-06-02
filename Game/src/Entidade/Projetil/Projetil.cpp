#include "pch.h"
#include "Entidade/Projetil/Projetil.h"

Projetil::Projetil()
{
	const bool movable;

	caster = nullptr;
}

Projetil::~Projetil()
{
	caster = nullptr;
}

void Projetil::move()
{
}

void Projetil::attack()
{
}