#pragma once

#include "Lista/ListaEntidades.h"
#include "Gerenciador/Grafico.h"

namespace Estado {
	class Fase 
	{
	protected:
		ListaEntidades list;
		Gerenciador::Grafico* ger_grafico;

	public:
		Fase();
		~Fase();

		void executar();
		void criarInimigos();
		void criarObstaculos();

	};
}