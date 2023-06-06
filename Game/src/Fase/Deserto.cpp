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
		background_texture.loadFromFile(string(IMG) + "DesertoPA.png");
		background.setSize(sf::Vector2f(ger_grafico->getWindowSize()));
		background.setTexture(&background_texture);
		background_auxiliar.setSize(sf::Vector2f(ger_grafico->getWindowSize()));
		background_auxiliar.setTexture(&background_texture);
		background_auxiliar.setPosition((float) ger_grafico->getWindowSize().x, 0.f);
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
		j1 = new Jogadores::Ninja(sf::Vector2f(300.f, 300.f), 50);
		ger_eventos->setJogador(j1);
		j1->setGerGraf(ger_grafico);
		list->push(j1);
	}

	void Deserto::criarInimigos()
	{
		
	}

	void Deserto::criarObstaculos()
	{
		
	}
}