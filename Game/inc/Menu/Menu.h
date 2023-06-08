#pragma once

#include "Gerenciador/Grafico.h"
#include "Gerenciador/Eventos.h"
#include "Fase/Floresta.h"
#include "Fase/Deserto.h"

namespace Menu{
	class Menu {
	private:
		sf::RectangleShape fundo;
		sf::Font fonte;
		sf::Text AgeOfWarriors;
		sf::Text Fase1;
		sf::Text Fase2;
		sf::Text Ranking;
		Gerenciador::Grafico* ger_grafico;
		Gerenciador::Eventos* ger_eventos;
		Fases::Deserto* fase1;
		Fases::Floresta* fase2;

	public:
		Menu();
		~Menu();

		int executar();

	};
}
