#include "pch.h"
#include "Estado/Fases/Floresta.h"

Estado::Floresta::Floresta() : j1(NULL)
{
	list->clear();
	criarObstaculos();
	criarJogador();
	criarInimigos();
	colisor = new Gerenciador::Colisao(list, ger_grafico);
}

Estado::Floresta::~Floresta()
{
	list->clear();
}

void Estado::Floresta::executar()
{
	move();
	colisor->executar();
	draw();
}

void Estado::Floresta::criarJogador()
{
	j1 = new Jogador(sf::Vector2f(300.f, 10.f), 1, 50);
	ger_eventos->setJogador(j1);
	j1->setGerGraf(ger_grafico);
	list->push(static_cast<Entidade*>(j1));
}

void Estado::Floresta::criarInimigos()
{
	EnemyMelee* enemy_melee1 = NULL;
	EnemyRanged* enemy_ranged1 = NULL;
	Boss* boss1 = NULL;

	enemy_melee1 = new EnemyMelee(sf::Vector2f(560.f, 0.f), 10);
	enemy_melee1->setGerGraf(ger_grafico);
	enemy_melee1->setPlayer(j1);
	list->push(static_cast<Entidade*> (enemy_melee1));

	boss1 = new Boss(sf::Vector2f(850.f, 90.f), 10);
	boss1->setGerGraf(ger_grafico);
	boss1->setPlayer(j1);
	list->push(static_cast<Entidade*> (boss1));

	enemy_ranged1 = new EnemyRanged(sf::Vector2f(70.f, 90.f), 10);
	enemy_ranged1->setGerGraf(ger_grafico);
	enemy_ranged1->setPlayer(j1);
	list->push(static_cast<Entidade*> (enemy_ranged1));
}

void Estado::Floresta::criarObstaculos()
{
	Plataforma *plat = NULL, *platform1=NULL, * platform2 = NULL, * platform3 = NULL, * platform4 = NULL;
	ObstacleBlock* obstacle1 = NULL;

	/*for (int i = 0; i < 4; i++)
	{
		plat = new Plataforma(sf::Vector2f((i * 630.f), 400.f), 9);
		plat->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(plat));
	}*/

	obstacle1 = new ObstacleBlock(sf::Vector2f(500.f, 200.f), 100);
	obstacle1->setGerGraf(ger_grafico);
	list->push(static_cast<Entidade*> (obstacle1));

	platform1 = new Plataforma(sf::Vector2f(450.f, 500.f), 1000);
	platform1->setGerGraf(ger_grafico);
	list->push(static_cast<Entidade*> (platform1));

	platform2 = new Plataforma(sf::Vector2f(800.f, 300.f), 2000);
	platform2->setGerGraf(ger_grafico);
	list->push(static_cast<Entidade*> (platform2));

	platform3 = new Plataforma(sf::Vector2f(0.f, 300.f), 3000);
	platform3->setGerGraf(ger_grafico);
	list->push(static_cast<Entidade*> (platform3));

	platform4 = new Plataforma(sf::Vector2f(770.f, 500.f), 3000);
	platform4->setGerGraf(ger_grafico);
	list->push(static_cast<Entidade*> (platform4));
}
