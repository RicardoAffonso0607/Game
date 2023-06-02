#pragma once

#include "Fase/Deserto.h"
#include "Fase/Floresta.h"
#include "Gerenciador/Grafico.h"
#include "Gerenciador/Eventos.h"

class Jogo
{
private:
	Gerenciador::Grafico* ger_grafico;
	Gerenciador::Eventos* ger_eventos;
	Fases::Floresta* fase1;
	Fases::Deserto* fase2;
public:
	Jogo();
	~Jogo();

	void inicializa();
	void executar();
};

