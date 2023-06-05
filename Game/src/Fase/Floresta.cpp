#include "pch.h"
#include "Fase/Floresta.h"

namespace Fases {
	Floresta::Floresta()
	{
		list->clear();
		criarJogador();
		criarInimigos();
		criarObstaculos();
		colisor = new Gerenciador::Colisao(list, ger_grafico);
		background_texture.loadFromFile(string(IMG) + "teste2.jpg");
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
		j1 = new Jogadores::Lutadora(sf::Vector2f(300.f, 10.f), 50);
		ger_eventos->setJogador(j1);
		j1->setGun(arma = new Armas::Arco(sf::Vector2f(300.f, 10.f)));
		j1->setGerGraf(ger_grafico);
		list->push(j1);
		arma->setGerGraf(ger_grafico);
		list->push(arma);
	}

	void Floresta::criarInimigos()
	{
		Inimigos::CorpoACorpo* corpo_a_corpo = nullptr;
		Inimigos::Disparador* disparador = nullptr;
		Inimigos::Chefao* chefao = nullptr;

		corpo_a_corpo = new Inimigos::CorpoACorpos::Spartacus(sf::Vector2f(560.f, 0.f));
		corpo_a_corpo->setGerGraf(ger_grafico);
		corpo_a_corpo->setPlayer(j1);
		list->push(corpo_a_corpo);

		chefao = new Inimigos::Chefoes::Nidogue(sf::Vector2f(850.f, 90.f));
		chefao->setGerGraf(ger_grafico);
		chefao->setPlayer(j1);
		list->push(chefao);

		disparador = new Inimigos::Disparadores::Merlin(sf::Vector2f(70.f, 90.f));
		disparador->setGerGraf(ger_grafico);
		disparador->setPlayer(j1);
		list->push(disparador);
	}

	void Floresta::criarObstaculos()
	{
		Obstaculos::Inertes::Plataforma* plat = nullptr;
		Obstaculos::Inerte* inerte = nullptr;

		//for (int i = 0; i < 4; i++)
		//{
		//	plat = new Plataformas::Gramado(sf::Vector2f((i * 630.f), 400.f));
		//	plat->setGerGraf(ger_grafico);
		//	list->push(static_cast<Entidade*>(plat));
		//}

		inerte = new Obstaculos::Inertes::ArbustoFlorido(sf::Vector2f(500.f, 200.f));
		inerte->setGerGraf(ger_grafico);
		list->push(inerte);

		plat = new Obstaculos::Inertes::Plataformas::Gramado(sf::Vector2f(450.f, 500.f), sf::Vector2f(600.f, 20.f));
		plat->setGerGraf(ger_grafico);
		list->push(plat);

		plat = new Obstaculos::Inertes::Plataformas::Gramado(sf::Vector2f(800.f, 300.f), sf::Vector2f(600.f, 20.f));
		plat->setGerGraf(ger_grafico);
		list->push(plat);

		plat = new Obstaculos::Inertes::Plataformas::Gramado(sf::Vector2f(0.f, 300.f), sf::Vector2f(600.f, 20.f));
		plat->setGerGraf(ger_grafico);
		list->push(plat);

		plat = new Obstaculos::Inertes::Plataformas::Gramado(sf::Vector2f(770.f, 500.f), sf::Vector2f(600.f, 20.f));
		plat->setGerGraf(ger_grafico);
		list->push(plat);
	}
}