#include "pch.h"
<<<<<<< HEAD
#include "Gerenciador/Grafico.h"

Gerenciador::Grafico* Gerenciador::Grafico::pGraf(NULL);

Gerenciador::Grafico::Grafico() : window(new sf::RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode().width - 100, sf::VideoMode::getDesktopMode().height - 200), "Age of Warriors++"))
{
	window->setFramerateLimit(60);
	window->setPosition(sf::Vector2i(50, 50));
=======
#include "../../Game/inc/Gerenciador/Grafico.h"

Gerenciador::Grafico* Gerenciador::Grafico::pGraf(NULL);

Gerenciador::Grafico::Grafico() : window( new sf::RenderWindow(sf::VideoMode(1800, 1000), "Age of Warriors"))
{
	window->setFramerateLimit(60);
>>>>>>> main

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
	window = NULL;
}

Gerenciador::Grafico* Gerenciador::Grafico::getGrafico()
{
<<<<<<< HEAD
	if (pGraf == NULL)
=======
	if(pGraf == NULL)
>>>>>>> main
		return new Gerenciador::Grafico();

	return pGraf;
}
