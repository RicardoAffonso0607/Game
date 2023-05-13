#include "stdafx.h"
#include "Jogo.h"

Jogo::Jogo() : window(sf::VideoMode(400,400), "Jogo")
{
	window.setFramerateLimit(60);

	jogador1 = new Jogador();
	jogador1->setWindow(&window);

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
		jogador1->draw();
		jogador1->move();
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

}
