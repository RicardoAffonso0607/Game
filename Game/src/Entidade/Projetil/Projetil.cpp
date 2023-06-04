#include "pch.h"
#include "Entidade/Projetil/Projetil.h"

Projetil::Projetil()
{
}

Projetil::~Projetil()
{
}

void Projetil::setFacingLeft()
{
	facing_left = true;
}

void Projetil::unsetFacingLeft()
{
	facing_left = false;
}