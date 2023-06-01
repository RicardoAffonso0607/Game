#include "pch.h"

#include "Gerenciador/Grafico.h"

Gerenciador::Grafico* Gerenciador::Grafico::pGraf(nullptr);

Gerenciador::Grafico::Grafico() : window(new sf::RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode().width - 100, sf::VideoMode::getDesktopMode().height - 200), "Age of Warriors++"))
{
	window->setFramerateLimit(60);
	window->setPosition(sf::Vector2i(50, 50));

	if (!window)
	{
		std::cout << "Ponteiro para janela nulo" << std::endl;
		exit(1);
	}
}

Gerenciador::Grafico::~Grafico()
{
	if (window)
	{
		delete(window);
	}
	window = nullptr;
}

Gerenciador::Grafico* Gerenciador::Grafico::getGrafico()
{
	if (pGraf == nullptr)
		pGraf = new Gerenciador::Grafico();

	return pGraf;
}
