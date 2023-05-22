#include "pch.h"
#include "../../inc/Estado/Jogo.h"

Jogo::Jogo() : window(sf::VideoMode(1400,1000), "Jogo")
{
	window.setFramerateLimit(60);

	jogador1 = new Jogador(sf::Vector2f(10.f, 10.f), 1, 100);
	jogador1->setWindow(&window);

	enemy1 = new EnemyMelee(sf::Vector2f(400.f, 10.f), 2);
	enemy1->setWindow(&window);
	enemy1->setPlayer(jogador1);


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
		enemy1->draw();
		jogador1->move();
		enemy1->move();
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
