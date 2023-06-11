#pragma once

#include "Gerenciador/Grafico.h"
#include "Gerenciador/Eventos.h"
#include "Fase/Floresta.h"
#include "Fase/Deserto.h"

namespace Menu{
	class Menu {

	protected:
		sf::RectangleShape fundo;
		sf::Font fonte;
		Gerenciador::Grafico* ger_grafico;
		Gerenciador::Eventos* ger_eventos;
		Gerenciador::Salvamento* ger_salvamento;

	private:
		sf::Text AgeOfWarriors;
		sf::Text Fase1;
		sf::Text Fase2;
		sf::Text Sair;
		sf::Text Ranking;
		Fases::Deserto* fase1;
		Fases::Floresta* fase2;

	public:
		Menu();
		~Menu();

		int executar();

	};
}
