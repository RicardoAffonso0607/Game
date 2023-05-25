#include "pch.h"
#include "Estado/Jogo.h"

Jogo::Jogo() : window(sf::VideoMode(sf::VideoMode::getDesktopMode().width-100, sf::VideoMode::getDesktopMode().height-200), "Age of Warriors++")
{
	window.setFramerateLimit(60);
	window.setPosition(sf::Vector2i(50, 50));
	
	list_ent = new ListaEntidades;
	colisor = new Gerenciador::Colisao;
	jogador1 = new Jogador(sf::Vector2f(300.f, 100.f), 1, 100);
	jogador1->setWindow(&window);
	list_ent->push(jogador1);

	enemy1 = new EnemyMelee(sf::Vector2f(200.f, 200.f), 2);
	enemy1->setWindow(&window);
	enemy1->setPlayer(jogador1);
	list_ent->push(enemy1);

	platform1 = new Plataforma(sf::Vector2f(150.f, 300.f), 10);
	platform1->setWindow(&window);
	list_ent->push(platform1);

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
		platform1->draw();
		jogador1->draw();
		enemy1->draw();
		jogador1->move();
		enemy1->move();
		colisor->collided(list_ent);
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