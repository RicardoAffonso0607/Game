#include "pch.h"
#include "Gerenciador/Grafico.h"


namespace Gerenciador {
	Grafico* Grafico::pGraf(nullptr);

	Grafico::Grafico() : window(new sf::RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode().width - 100, sf::VideoMode::getDesktopMode().height - 200), "Age of Warriors++")),
		camera(new sf::View())
	{
		window->setFramerateLimit(60);
		window->setPosition(sf::Vector2i(50, 50));
		camera->setSize((sf::Vector2f)window->getSize());

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

		if (camera)
		{
			delete(camera);
		}
		camera = nullptr;
	}

	Grafico* Grafico::getGrafico()
	{
		if (pGraf == nullptr)
			pGraf = new Grafico();

		return pGraf;
	}
}