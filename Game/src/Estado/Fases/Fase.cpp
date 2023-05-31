#include "pch.h"
#include "Estado/Fases/Fase.h"

namespace Estado {

	Gerenciador::Grafico* Fase::ger_grafico(ger_grafico->getGrafico());
	Gerenciador::Eventos* Fase::ger_eventos(ger_eventos->getEventos());
	Gerenciador::Colisao* Fase::colisor(new Gerenciador::Colisao);

	Fase::Fase() : list(new ListaEntidades())
	{
		list->clear();
	}

	Fase::~Fase() 
	{
		list->clear();
	}

}