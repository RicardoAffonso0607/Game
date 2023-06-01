#include "pch.h"
#include "Fase/Floresta.h"

namespace Fase {
	Floresta::Floresta() : j1(nullptr)
	{
		list->clear();
		criarJogador();
		criarInimigos();
		criarObstaculos();
		colisor = new Gerenciador::Colisao(list, ger_grafico);
		background_texture.loadFromFile("Game/assets/teste2.jpg");
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
		j1 = new Jogador::Jogador(sf::Vector2f(300.f, 10.f), 1, 50);
		ger_eventos->setJogador(j1);
		j1->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*> (j1));
	}

	void Floresta::criarInimigos()
	{
		Inimigo::CorpoACorpo::CorpoACorpo* corpo_a_corpo1 = nullptr;
		Inimigo::Disparador::Disparador* disparador1 = nullptr;
		Inimigo::Chefao::Chefao* chefao1 = nullptr;

		corpo_a_corpo1 = new Inimigo::CorpoACorpo::CorpoACorpo(sf::Vector2f(560.f, 0.f), 10);
		corpo_a_corpo1->setGerGraf(ger_grafico);
		corpo_a_corpo1->setPlayer(j1);
		list->push(static_cast<Entidade*> (corpo_a_corpo1));

		chefao1 = new Inimigo::Chefao::Chefao(sf::Vector2f(850.f, 90.f), 10);
		chefao1->setGerGraf(ger_grafico);
		chefao1->setPlayer(j1);
		list->push(static_cast<Entidade*> (chefao1));

		disparador1 = new Inimigo::Disparador::Disparador(sf::Vector2f(70.f, 90.f), 10);
		disparador1->setGerGraf(ger_grafico);
		disparador1->setPlayer(j1);
		list->push(static_cast<Entidade*> (disparador1));
	}

	void Floresta::criarObstaculos()
	{
		Plataforma::Plataforma* plat = nullptr, * plataforma1 = nullptr, * plataforma2 = nullptr, * plataforma3 = nullptr, * plataforma4 = nullptr;
		Obstaculo::Inerte::Inerte* inerte1 = nullptr;

		//for (int i = 0; i < 4; i++)
		//{
		//	plat = new Plataforma(sf::Vector2f((i * 630.f), 400.f), 9);
		//	plat->setGerGraf(ger_grafico);
		//	list->push(static_cast<Entidade*>(plat));
		//}

		inerte1 = new Obstaculo::Inerte::Inerte(sf::Vector2f(500.f, 200.f), 100);
		inerte1->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*> (inerte1));

		plataforma1 = new Plataforma::Plataforma(sf::Vector2f(450.f, 500.f), 1000);
		plataforma1->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*> (plataforma1));

		plataforma2 = new Plataforma::Plataforma(sf::Vector2f(800.f, 300.f), 2000);
		plataforma2->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*> (plataforma2));

		plataforma3 = new Plataforma::Plataforma(sf::Vector2f(0.f, 300.f), 3000);
		plataforma3->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*> (plataforma3));

		plataforma4 = new Plataforma::Plataforma(sf::Vector2f(770.f, 500.f), 3000);
		plataforma4->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*> (plataforma4));
	}
}