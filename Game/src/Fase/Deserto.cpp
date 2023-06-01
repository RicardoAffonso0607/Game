#include "pch.h"
#include "Fase/Deserto.h"

namespace Fase {
	Deserto::Deserto()
	{
		list->clear();
		criarObstaculos();
		criarJogador();
		criarInimigos();
		colisor = new Gerenciador::Colisao(list, ger_grafico);
		background_texture.loadFromFile("Game/assets/teste2.jpg");
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
		j1 = new Jogador::Jogador(sf::Vector2f(300.f, 300.f), 1, 50);
		ger_eventos->setJogador(j1);
		j1->setGerGraf(ger_grafico);
		list->push(dynamic_cast<Entidade*>(j1));
	}

	void Deserto::criarInimigos()
	{
		Inimigo::CorpoACorpo::CorpoACorpo* en1 = nullptr;

		en1 = new Inimigo::CorpoACorpo::CorpoACorpo(sf::Vector2f(100.f, 300.f), 8);
		en1->setPlayer(j1);
		en1->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(en1));
	}

	void Deserto::criarObstaculos()
	{
		Plataforma::Plataforma* plat = nullptr;

		for (int i = 0; i < 4; i++)
		{
			plat = new Plataforma::Plataforma(sf::Vector2f((i * 630.f), 400.f), 9);
			plat->setGerGraf(ger_grafico);
			list->push(static_cast<Entidade*>(plat));
		}
	}
}