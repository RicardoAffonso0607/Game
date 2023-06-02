#include "pch.h"
#include "Fase/Fase.h"

Gerenciador::Grafico* Fase::ger_grafico(ger_grafico->getGrafico());
Gerenciador::Eventos* Fase::ger_eventos(ger_eventos->getEventos());

Fase::Fase() : list(new ListaEntidades())
{
	list->clear();
}

Fase::~Fase() 
{
	list->clear();
	delete colisor;
}