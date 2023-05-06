#include "stdafx.h"
#include "Jogo.h"

Jogo::Jogo() : window(sf::VideoMode(400,400), "Jogo")
{


	executar();
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{
	while (window.isOpen())
	{
		eventos();
		teclas_pressionadas();

		window.clear();
		window.display();
	}
}

void Jogo::eventos()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Jogo::teclas_pressionadas()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D));
		
}
