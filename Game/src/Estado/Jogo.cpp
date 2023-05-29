#include "pch.h"
#include "Estado/Jogo.h"

Jogo::Jogo() : ger_grafico(ger_grafico->getGrafico()), ger_eventos(ger_eventos->getEventos())
{
	inicializa();
	executar();
}


void Jogo::inicializa()
{

	if (ger_grafico == NULL)
	{
		cout << "Gerenciador gr�fico nulo" << endl;
		exit(1);
	}

	if (ger_eventos == NULL)
	{
		cout << "Gerenciador de eventos nulo" << endl;
		exit(1);
	}

	list_ent = new ListaEntidades;
	colisor = new Gerenciador::Colisao;

	//Cria os jogadores
	jogador1 = new Jogador(sf::Vector2f(300.f, 150.f), 1, 1);
	jogador1->setGerGraf(ger_grafico);
	list_ent->push(static_cast<Entidade*> (jogador1));
	ger_eventos->setJogador(jogador1);

	//Cria os inimigos
	enemy1 = new EnemyMelee(sf::Vector2f(200.f, 300.f), 10);
	enemy1->setGerGraf(ger_grafico);
	enemy1->setPlayer(jogador1);
	list_ent->push(static_cast<Entidade*> (enemy1));

	//Cria os obst�culos
	obstacle1 = new ObstacleBlock(sf::Vector2f(500.f, 100.f), 100);
	obstacle1->setGerGraf(ger_grafico);
	list_ent->push(static_cast<Entidade*> (obstacle1));

	//Cria as plataformas
	platform1 = new Plataforma(sf::Vector2f(150.f, 400.f), 1000);
	platform1->setGerGraf(ger_grafico);
	list_ent->push(static_cast<Entidade*> (platform1));

	platform2 = new Plataforma(sf::Vector2f(400.f, 200.f), 2000);
	platform2->setGerGraf(ger_grafico);
	list_ent->push(static_cast<Entidade*> (platform2));
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{
	while (ger_grafico->verificaJanelaAberta())
	{
		ger_eventos->executar();
		ger_grafico->limpaJanela();
		list_ent->moveAll();
		list_ent->drawAll();
		colisor->executar(list_ent);
		ger_grafico->mostraElementos();
	}
}

