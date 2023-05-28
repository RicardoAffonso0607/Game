#include "pch.h"
#include "../inc/Ente.h"

Gerenciador::Grafico* Ente::pGerGraf(NULL);

Ente::Ente() : id(0), body(sf::Vector2f(100.f, 100.f))
{
}

Ente::~Ente()
{
}
