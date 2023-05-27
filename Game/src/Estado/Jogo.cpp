#include "pch.h"
#include "../../inc/Estado/Jogo.h"

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
		list_ent.moveAll();
		list_ent.drawAll();
		ger_grafico->mostraElemntos();
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
