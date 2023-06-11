#pragma once

#include "Menu.h"

namespace Menu
{
	class Morte : public Menu
	{
	private:
		sf::Text Mensagem;
		sf::Text Voltar;
		sf::Text Sair;

	public:
		Morte();
		~Morte();

		int executar();
	};

}

