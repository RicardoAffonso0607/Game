#pragma once

#include "Estado/Fases/Deserto.h"
#include "Estado/Fases/Floresta.h"
#include "Gerenciador/Grafico.h"
#include "Gerenciador/Eventos.h"

class Jogo
{
private:
	Gerenciador::Grafico* ger_grafico;
	Gerenciador::Eventos* ger_eventos;
	Estado::Floresta* fase1;
	Estado::Deserto* fase2;
public:
	Jogo();
	~Jogo();

	void inicializa();
	void executar();
};

