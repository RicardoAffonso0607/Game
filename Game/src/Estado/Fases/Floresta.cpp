#include "pch.h"
#include "Estado/Fases/Floresta.h"

Estado::Floresta::Floresta() : j1(NULL)
{
	list->clear();
	criarJogador();
	criarInimigos();
	criarObstaculos();
	colisor = new Gerenciador::Colisao(list, ger_grafico);
}

Estado::Floresta::~Floresta()
{
	list->clear();
}

void Estado::Floresta::executar()
{
	colisor->executar();
	move();
	draw();
}

void Estado::Floresta::criarJogador()
{
	j1 = new Jogador(sf::Vector2f(300.f, 300.f), 1, 50);
	ger_eventos->setJogador(j1);
	j1->setGerGraf(ger_grafico);
	list->push(static_cast<Entidade*>(j1));
}

void Estado::Floresta::criarInimigos()
{
	EnemyMelee* en1 = NULL;

	en1 = new EnemyMelee(sf::Vector2f(100.f, 300.f), 8);
	en1->setPlayer(j1);
	en1->setGerGraf(ger_grafico);
	list->push(static_cast<Entidade*>(en1));
}

void Estado::Floresta::criarObstaculos()
{
	Plataforma* plat = NULL;

	for (int i = 0; i < 4; i++)
	{
		plat = new Plataforma(sf::Vector2f((i * 630.f), 600.f), 9);
		plat->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(plat));
	}

}
