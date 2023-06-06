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
		background_texture.loadFromFile(string(IMG) + "FlorestaPA.png");
		background.setSize(sf::Vector2f(ger_grafico->getWindowSize()));
		background_auxiliar.setSize(sf::Vector2f(ger_grafico->getWindowSize()));
		background.setTexture(&background_texture);
		background_auxiliar.setTexture(&background_texture);
		background_auxiliar.setPosition((float) ger_grafico->getWindowSize().x, 0.f);
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

		if (j1->getPos().x > ger_grafico->getWindowSize().x / 2.f)
			ger_grafico->getCamera()->setCenter(j1->getPos().x, ger_grafico->getWindowSize().y / 2.f);
		else
			ger_grafico->getCamera()->setCenter(ger_grafico->getWindowSize().x / 2.f, ger_grafico->getWindowSize().y / 2.f);

		if (ger_grafico->getCamera()->getCenter().x >= 3.f * (background.getPosition().x + ger_grafico->getWindowSize().x) / 2.f)
			background.setPosition(2.f * ger_grafico->getWindowSize().x, 0.f);

		draw();
	}

	void Floresta::criarJogador()
	{
		j1 = new Jogadores::Lutadora(sf::Vector2f(300.f, 10.f), 50);
		ger_eventos->setJogador(j1);
		j1->setGun(arma = new Armas::Arco(sf::Vector2f(300.f, 10.f), list));
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

		corpo_a_corpo = new Inimigos::CorpoACorpos::Spartacus(sf::Vector2f(1100.f, 0.f));
		corpo_a_corpo->setGerGraf(ger_grafico);
		corpo_a_corpo->setPlayer(j1);
		list->push(corpo_a_corpo);

		corpo_a_corpo = new Inimigos::CorpoACorpos::Spartacus(sf::Vector2f(1900.f, 0.f));
		corpo_a_corpo->setGerGraf(ger_grafico);
		corpo_a_corpo->setPlayer(j1);
		list->push(corpo_a_corpo);

		chefao = new Inimigos::Chefoes::Nidogue(sf::Vector2f(850.f, 90.f), list);
		chefao->setGerGraf(ger_grafico);
		chefao->setPlayer(j1);
		list->push(chefao);

		disparador = new Inimigos::Disparadores::Merlin(sf::Vector2f(70.f, 90.f), list);
		disparador->setGerGraf(ger_grafico);
		disparador->setPlayer(j1);
		list->push(disparador);
	}

	void Floresta::criarObstaculos()
	{
		Obstaculos::Inertes::Plataformas::Gramado* plat = nullptr;
		Obstaculos::Danosos::ArmadilhaDeLancas* danoso = nullptr;
		Obstaculos::Inertes::ArbustoFlorido* inerte = nullptr;
		Obstaculos::Retardantes::Lama* retardante = nullptr;

		for (int i = 0; i < 9; i++)
		{
			plat = new Obstaculos::Inertes::Plataformas::Gramado (sf::Vector2f(i*600.f, ger_grafico->getWindowSize().y - 100.f), sf::Vector2f(600.f, 100.f));
			plat->setGerGraf(ger_grafico);
			list->push(static_cast<Entidade*>(plat));
		}

		plat = new Obstaculos::Inertes::Plataformas::Gramado(sf::Vector2f(800.f, ger_grafico->getWindowSize().y - 400.f), sf::Vector2f(600.f, 50.f));
		plat->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(plat));

		retardante = new Obstaculos::Retardantes::Lama (sf::Vector2f(800.f, ger_grafico->getWindowSize().y - 100.f), sf::Vector2f(600.f, 100.f));
		retardante->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(retardante));

		danoso = new Obstaculos::Danosos::ArmadilhaDeLancas (sf::Vector2f(3.f *(ger_grafico->getWindowSize().x)/2.f, ger_grafico->getWindowSize().y - 50.f));
		danoso->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(danoso));
	}
}