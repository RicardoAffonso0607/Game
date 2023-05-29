#include "pch.h"
#include "../../Game/inc/Gerenciador/Grafico.h"

Gerenciador::Grafico* Gerenciador::Grafico::pGraf(NULL);

Gerenciador::Grafico::Grafico() : window( new sf::RenderWindow(sf::VideoMode(1800, 1000), "Age of Warriors"))
{
	window->setFramerateLimit(60);

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
	if(pGraf == NULL)
		pGraf = new Gerenciador::Grafico();

	return pGraf;
}
