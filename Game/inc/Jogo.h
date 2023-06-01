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
	Fase::Floresta* fase1;
	Fase::Deserto* fase2;
public:
	Jogo();
	~Jogo();

	void inicializa();
	void executar();
};

