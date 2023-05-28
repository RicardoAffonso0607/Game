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
	colisor = new Gerenciador::Colisao;

	//Cria os jogadores
	jogador1 = new Jogador(sf::Vector2f(300.f, 150.f), 1, 1);
	jogador1->setGerGraf(ger_grafico);
	list_ent->push(static_cast<Entidade*> (jogador1));

	//Cria os inimigos
	enemy1 = new EnemyMelee(sf::Vector2f(200.f, 300.f), 10);
	enemy1->setGerGraf(ger_grafico);
	enemy1->setPlayer(jogador1);
	list_ent->push(static_cast<Entidade*> (enemy1));

	//Cria os obstáculos
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

void Jogo::inicializa()
{

	//Cria os jogadores
	jogador1 = new Jogador(sf::Vector2f(10.f, 10.f), 1, 100);
	jogador1->setGerGraf(ger_grafico);
	list_ent.push(static_cast<Entidade*> (jogador1));

	//Cria os inimigos
	enemy1 = new EnemyMelee(sf::Vector2f(400.f, 10.f), 2);
	enemy1->setPlayer(jogador1);
	list_ent.push(static_cast<Entidade*> (enemy1));
}

void Jogo::executar()
{
	while (ger_grafico->verificaJanelaAberta())
	{
		eventos();
		teclas_pressionadas();

		ger_grafico->limpaJanela();
<<<<<<< HEAD
		list_ent->moveAll();
		list_ent->drawAll();
		colisor->executar(list_ent);
		ger_grafico->mostraElementos();
=======
		list_ent.moveAll();
		list_ent.drawAll();
		ger_grafico->mostraElemntos();
>>>>>>> main
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

}