#include "pch.h"
#include "../../inc/Estado/Jogo.h"

Jogo::Jogo() : window(sf::VideoMode(1800,1000), "Jogo")
{
	inicializa();
	executar();
}

Jogo::~Jogo()
{
}

void Jogo::inicializa()
{
	//Define o frame rate da janela
	window.setFramerateLimit(60);

	//Cria os jogadores
	jogador1 = new Jogador(sf::Vector2f(10.f, 10.f), 1, 100);
	jogador1->setWindow(&window);
	list_ent.push(static_cast<Entidade*> (jogador1));

	//Cria os inimigos
	enemy1 = new EnemyMelee(sf::Vector2f(400.f, 10.f), 2);
	enemy1->setWindow(&window);
	enemy1->setPlayer(jogador1);
	list_ent.push(static_cast<Entidade*> (enemy1));
}

void Jogo::executar()
{
	while (window.isOpen())
	{
		eventos();
		teclas_pressionadas();

		window.clear();
		//list_ent.drawAll();
		list_ent.moveAll();
		list_ent.drawAll();
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
