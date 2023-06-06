#pragma once

#include "Fase/Deserto.h"
#include "Fase/Floresta.h"
#include "Gerenciador/Grafico.h"
#include "Gerenciador/Eventos.h"

class Jogo
{
private:
	Fases::Deserto* fase1;
	Fases::Floresta* fase2;
	Gerenciador::Grafico* ger_grafico;
	Gerenciador::Eventos* ger_eventos;

public:
	Jogo();
	~Jogo();

	void inicializa();
	void executar();
};

