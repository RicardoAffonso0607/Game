#include "pch.h"
#include "Ente.h"

Gerenciador::Grafico* Ente::pGerGraf(NULL);

Ente::Ente() : body(sf::Vector2f(100.f, 100.f))
{
}

Ente::~Ente()
{
}
