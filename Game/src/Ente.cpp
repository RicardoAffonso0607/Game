#include "pch.h"
#include "Ente.h"

Gerenciador::Grafico* Ente::pGerGraf(nullptr);

Ente::Ente() : body(sf::Vector2f(100.f, 100.f))
{
	id = NULL;
}

Ente::~Ente()
{
}
