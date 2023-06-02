#include "pch.h"
#include "Ente.h"

Ente::Ente() : id(NULL), pGerGraf(nullptr)
{
}

Ente::Ente(unsigned int id) : id(id), pGerGraf(nullptr)
{
}

Ente::~Ente()
{
	pGerGraf = nullptr;
}