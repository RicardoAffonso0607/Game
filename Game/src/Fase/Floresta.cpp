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
		background_auxiliar.setSize(sf::Vector2f(ger_grafico->getWindowSize()));
		background.setTexture(&background_texture);
		background_auxiliar.setTexture(&background_texture);
		background_auxiliar.setPosition(ger_grafico->getWindowSize().x, 0.f);
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
		ger_grafico->desenhaElemento(background_auxiliar);
		ger_grafico->getCamera()->setCenter(j1->getPosition().x, ger_grafico->getWindowSize().y / 2);

		if (ger_grafico->getCamera()->getCenter().x >= 3 * (background.getPosition().x + ger_grafico->getWindowSize().x) / 2)
			background.setPosition(2 * ger_grafico->getWindowSize().x, 0.f);

		draw();
	}

	void Floresta::criarJogador()
	{
		j1 = new Jogador::Lutadora(sf::Vector2f(300.f, 10.f), 1, 50);
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
		Obstaculo::Danoso::Danoso* cacto = nullptr;
		Obstaculo::Inerte::Inerte* inerte1 = nullptr;

		for (int i = 0; i < 9; i++)
		{
			plat = new Plataforma::Plataforma(sf::Vector2f((i * 600.f), ger_grafico->getWindowSize().y - 20), 9);
			plat->setGerGraf(ger_grafico);
			list->push(static_cast<Entidade*>(plat));
		}

		cacto = new Obstaculo::Danoso::Danoso(sf::Vector2f(ger_grafico->getWindowSize().x, ger_grafico->getWindowSize().y - 20), 4);
	}
}