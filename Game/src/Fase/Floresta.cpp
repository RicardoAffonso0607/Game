#include "pch.h"
#include "Fase/Floresta.h"

namespace Fases {
	Floresta::Floresta() : j1(nullptr)
	{
		list->clear();
		criarJogador();
		criarInimigos();
		criarObstaculos();
		colisor = new Gerenciador::Colisao(list, ger_grafico);
		background_texture.loadFromFile("Game/assets/img/teste2.jpg");
		background.setSize(sf::Vector2f(ger_grafico->getWindowSize()));
		background.setTexture(&background_texture);
	}

	Floresta::~Floresta()
	{
		list->clear();
	}

	void Floresta::executar()
	{
		move();
		colisor->executar();
		ger_grafico->desenhaElemento(background);
		draw();
	}

	void Floresta::criarJogador()
	{
		j1 = new Jogadores::Lutadora(sf::Vector2f(300.f, 10.f), 1, 50);
		ger_eventos->setJogador(j1);
		j1->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*> (j1));
	}

	void Floresta::criarInimigos()
	{
		Entidade* corpo_a_corpo = nullptr;
		Entidade* disparador = nullptr;
		Entidade* chefao = nullptr;

		corpo_a_corpo = new Inimigos::CorpoACorpos::Spartacus(sf::Vector2f(560.f, 0.f), 10);
		corpo_a_corpo->setGerGraf(ger_grafico);
		//corpo_a_corpo->setPlayer(j1);
		list->push(static_cast<Entidade*> (corpo_a_corpo));

		chefao = new Inimigos::Chefoes::Nidogue(sf::Vector2f(850.f, 90.f), 10);
		chefao->setGerGraf(ger_grafico);
		//chefao->setPlayer(j1);
		list->push(static_cast<Entidade*> (chefao));

		disparador = new Inimigos::Disparadores::Merlin(sf::Vector2f(70.f, 90.f), 10);
		disparador->setGerGraf(ger_grafico);
		//disparador->setPlayer(j1);
		list->push(static_cast<Entidade*> (disparador));
	}

	void Floresta::criarObstaculos()
	{
		Entidade* plat = nullptr;
		Entidade* inerte = nullptr;

		//for (int i = 0; i < 4; i++)
		//{
		//	plat = new Plataformas::Gramado(sf::Vector2f((i * 630.f), 400.f), 9);
		//	plat->setGerGraf(ger_grafico);
		//	list->push(static_cast<Entidade*>(plat));
		//}

		inerte = new Obstaculos::Inertes::ArbustoFlorido(sf::Vector2f(500.f, 200.f), 100);
		inerte->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*> (inerte));

		plat = new Plataformas::Gramado(sf::Vector2f(450.f, 500.f), 1000);
		plat->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*> (plat));

		plat = new Plataformas::Gramado(sf::Vector2f(800.f, 300.f), 2000);
		plat->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*> (plat));

		plat = new Plataformas::Gramado(sf::Vector2f(0.f, 300.f), 3000);
		plat->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*> (plat));

		plat = new Plataformas::Gramado(sf::Vector2f(770.f, 500.f), 3000);
		plat->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*> (plat));
	}
}