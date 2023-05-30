#include "pch.h"
#include "Estado/Jogo.h"

Jogo::Jogo() : ger_grafico(ger_grafico->getGrafico())
{
	if (ger_grafico == NULL)
	{
		cout << "Gerenciador gráfico nulo" << endl;
		exit(1);
	}


	inicializa();
	executar();
}


void Jogo::inicializa()
{
	list_ent = new ListaEntidades;
	colisor = new Gerenciador::Colisao(list_ent, ger_grafico);

	//Cria os jogadores
	jogador1 = new Jogador(sf::Vector2f(300.f, 150.f), 1, 1);
	jogador1->setGerGraf(ger_grafico);
	list_ent->push(static_cast<Entidade*> (jogador1));

	//Cria os inimigos
	enemy1 = new EnemyMelee(sf::Vector2f(560.f, 0.f), 10);
	enemy1->setGerGraf(ger_grafico);
	enemy1->setPlayer(jogador1);
	list_ent->push(static_cast<Entidade*> (enemy1));

	boss1 = new Boss(sf::Vector2f(850.f, 90.f), 10);
	boss1->setGerGraf(ger_grafico);
	boss1->setPlayer(jogador1);
	list_ent->push(static_cast<Entidade*> (boss1));

	enemy2 = new EnemyRanged(sf::Vector2f(70.f, 90.f), 10);
	enemy2->setGerGraf(ger_grafico);
	enemy2->setPlayer(jogador1);
	list_ent->push(static_cast<Entidade*> (enemy2));

	//Cria os obstáculos
	obstacle1 = new ObstacleBlock(sf::Vector2f(500.f, 200.f), 100);
	obstacle1->setGerGraf(ger_grafico);
	list_ent->push(static_cast<Entidade*> (obstacle1));

	//Cria as plataformas
	platform1 = new Plataforma(sf::Vector2f(450.f, 500.f), 1000);
	platform1->setGerGraf(ger_grafico);
	list_ent->push(static_cast<Entidade*> (platform1));

	platform2 = new Plataforma(sf::Vector2f(800.f, 300.f), 2000);
	platform2->setGerGraf(ger_grafico);
	list_ent->push(static_cast<Entidade*> (platform2));

	platform3 = new Plataforma(sf::Vector2f(0.f, 300.f), 3000);
	platform3->setGerGraf(ger_grafico);
	list_ent->push(static_cast<Entidade*> (platform3));

	platform4 = new Plataforma(sf::Vector2f(770.f, 500.f), 3000);
	platform4->setGerGraf(ger_grafico);
	list_ent->push(static_cast<Entidade*> (platform4));

}

Jogo::~Jogo()
{
}

void Jogo::executar()
{
	while (ger_grafico->verificaJanelaAberta())
	{
		eventos();
		teclas_pressionadas();

		ger_grafico->limpaJanela();
		list_ent->moveAll();
		list_ent->drawAll();
		colisor->executar();
		ger_grafico->mostraElementos();
	}
}

void Jogo::eventos()
{
	sf::Event event;

	while (ger_grafico->getWindow()->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			ger_grafico->fecharJanela();
	}
}

void Jogo::teclas_pressionadas()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		ger_grafico->fecharJanela();
}