#include "pch.h"
#include "Ente.h"

Ente::Ente() :
	pGerGraf(nullptr)
{
}

Ente::~Ente()
{
}

void Ente::setGerGraf(Gerenciador::Grafico* pauxGerGraf)
{ 
	pGerGraf = pauxGerGraf;
}