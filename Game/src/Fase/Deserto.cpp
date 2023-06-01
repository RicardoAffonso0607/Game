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
	}

	Deserto::~Deserto()
	{
		list->clear();
	}

	void Deserto::executar()
	{
		colisor->executar();
		move();
		draw();
	}

	void Deserto::criarJogador()
	{
		j1 = new Jogador(sf::Vector2f(300.f, 300.f), 1, 50);
		ger_eventos->setJogador(j1);
		j1->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(j1));
	}

	void Deserto::criarInimigos()
	{
		CorpoACorpo* en1 = nullptr;

		en1 = new CorpoACorpo(sf::Vector2f(100.f, 300.f), 8);
		en1->setPlayer(j1);
		en1->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(en1));
	}

	void Deserto::criarObstaculos()
	{
		Plataforma* plat = nullptr;

		for (int i = 0; i < 4; i++)
		{
			plat = new Plataforma(sf::Vector2f((i * 630.f), 400.f), 9);
			plat->setGerGraf(ger_grafico);
			list->push(static_cast<Entidade*>(plat));
		}
	}
}