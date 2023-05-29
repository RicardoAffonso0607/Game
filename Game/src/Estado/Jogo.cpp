#include "pch.h"
#include "../../inc/Estado/Jogo.h"

Jogo::Jogo() 
{
	inicializa();
	executar();
}

Jogo::~Jogo()
{
}

void Jogo::inicializa()
{
	ger_grafico = ger_grafico->getGrafico();
	ger_eventos = ger_eventos->getEventos();

	if (ger_grafico == NULL)
	{
		cout << "Gerenciador gráfico nulo" << endl;
		exit(1);
	}

	if (ger_eventos == NULL)
	{
		cout << "Gerenciador de eventos nulo" << endl;
		exit(1);
	}

	//Cria os jogadores
	jogador1 = new Jogador(sf::Vector2f(10.f, 10.f), 1, 100);
	jogador1->setGerGraf(ger_grafico);
	list_ent.push(static_cast<Entidade*> (jogador1));
	ger_eventos->setJogador(jogador1);

	//Cria os inimigos
	enemy1 = new EnemyMelee(sf::Vector2f(400.f, 10.f), 2);
	enemy1->setPlayer(jogador1);
	list_ent.push(static_cast<Entidade*> (enemy1));
}

void Jogo::executar()
{
	while (ger_grafico->verificaJanelaAberta())
	{
		ger_eventos->executar();
		ger_grafico->limpaJanela();
		list_ent.moveAll();
		list_ent.drawAll();
		ger_grafico->mostraElemntos();
	}
}
