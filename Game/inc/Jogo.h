#pragma once

#include "Fase/Deserto.h"
#include "Fase/Floresta.h"
#include "Gerenciador/Grafico.h"
#include "Gerenciador/Eventos.h"
#include "Menu/Morte.h"
#include "Menu/Ranking.h"

class Jogo
{
private:
	Fases::Deserto* fase1;
	Fases::Floresta* fase2;
	Gerenciador::Grafico* ger_grafico;
	Gerenciador::Eventos* ger_eventos;
	Gerenciador::Salvamento* ger_salvamento;
	Menu::Menu* menu;
	Menu::Morte* morte;
	Menu::Ranking* ranking;
	int iniciar;

public:
	Jogo();
	~Jogo();

	void inicializa();
	void executar();
};

