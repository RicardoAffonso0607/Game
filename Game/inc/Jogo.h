#pragma once

#include "Fase/Deserto.h"
#include "Fase/Floresta.h"
#include "Gerenciador/Grafico.h"
#include "Gerenciador/Eventos.h"
#include "Menu/Menu.h"

class Jogo
{
private:
	Fases::Deserto* fase1;
	Fases::Floresta* fase2;
	Gerenciador::Grafico* ger_grafico;
	Gerenciador::Eventos* ger_eventos;
	Menu::Menu* menu;
	int iniciar;

public:
	Jogo();
	~Jogo();

	void inicializa();
	void executar();
};

