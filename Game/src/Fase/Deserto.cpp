#include "pch.h"
#include "Fase/Deserto.h"

namespace Fases {
	Deserto::Deserto()
	{
		list->clear();
		criarObstaculos();
		criarJogador();
		criarInimigos();
		colisor = new Gerenciador::Colisao(list, ger_grafico);
		background_texture.loadFromFile("Game/assets/img/teste2.jpg");
		background.setSize(sf::Vector2f(ger_grafico->getWindowSize()));
		background.setTexture(&background_texture);
	}

	Deserto::~Deserto()
	{
		list->clear();
	}

	void Deserto::executar()
	{
		move();
		colisor->executar();
		ger_grafico->desenhaElemento(background);
		draw();
	}

	void Deserto::criarJogador()
	{
		j1 = new Jogadores::Ninja(sf::Vector2f(300.f, 300.f), 1, 50);
		ger_eventos->setJogador(j1);
		j1->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(j1));
	}

	void Deserto::criarInimigos()
	{
		inimigo = new Inimigos::CorpoACorpos::Medjai(sf::Vector2f(100.f, 300.f), 8);
		//inimigo->setPlayer(j1);
		inimigo->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(inimigo));
	}

	void Deserto::criarObstaculos()
	{
		for (int i = 0; i < 4; i++)
		{
			plataforma = new Plataformas::Areal(sf::Vector2f((i * 630.f), 400.f), 9);
			plataforma->setGerGraf(ger_grafico);
			list->push(static_cast<Entidade*>(plataforma));
		}
	}
}