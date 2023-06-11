#pragma once

#include "Menu.h"

namespace Menu
{
	class Ranking : public Menu
	{
	private:
		sf::Text Titulo;
		sf::Text Voltar;
		sf::Text Sair;

	public:
		Ranking();
		~Ranking();

		int executar();
	};

}