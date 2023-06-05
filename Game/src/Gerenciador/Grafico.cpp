#include "pch.h"
#include "Gerenciador/Grafico.h"


namespace Gerenciador {
	Grafico* Grafico::pGraf(nullptr);

	Grafico::Grafico() : window(new sf::RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode().width - 100, sf::VideoMode::getDesktopMode().height - 200), "Age of Warriors++"))
	{
		window->setFramerateLimit(60);
		window->setPosition(sf::Vector2i(50, 50));

		if (!window)
		{
			cout << "Ponteiro para janela nulo" << endl;
			exit(1);
		}
	}

	Grafico::~Grafico()
	{
		if (window)
		{
			delete(window);
		}
		window = nullptr;
	}

	Grafico* Grafico::getGrafico()
	{
		if (pGraf == nullptr)
			pGraf = new Grafico();

		return pGraf;
	}
}