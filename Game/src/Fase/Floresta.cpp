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

		//Câmera no inicio
		if (j1->getPos().x > ger_grafico->getWindowSize().x / 2)
			ger_grafico->getCamera()->setCenter(j1->getPos().x, ger_grafico->getWindowSize().y / 2);
		else
			ger_grafico->getCamera()->setCenter(ger_grafico->getWindowSize().x / 2, ger_grafico->getWindowSize().y / 2);

		//Atualizar os planos de fundo
		if (ger_grafico->getCamera()->getCenter().x >= 3 * (background.getPosition().x + ger_grafico->getWindowSize().x) / 2)
			background.setPosition(2 * ger_grafico->getWindowSize().x, 0.f);

		if (ger_grafico->getCamera()->getCenter().x >= 2.5 * (background_auxiliar.getPosition().x))
			background_auxiliar.setPosition(3 * ger_grafico->getWindowSize().x, 0.f);

		//Câmera no final
		if (j1->getPos().x > (7*ger_grafico->getWindowSize().x / 2) - 150.f)
			ger_grafico->getCamera()->setCenter((7*ger_grafico->getWindowSize().x / 2) - 150.f, (ger_grafico->getWindowSize().y / 2));

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

		/*---------------------------------------------------------------------------------*/ // Corpo a Corpos
		corpo_a_corpo = new Inimigos::CorpoACorpos::Spartacus(sf::Vector2f(900.f, 200.f));
		corpo_a_corpo->setGerGraf(ger_grafico);
		corpo_a_corpo->setPlayer(j1);
		list->push(corpo_a_corpo);

		corpo_a_corpo = new Inimigos::CorpoACorpos::Spartacus(sf::Vector2f(1600.f, 500.f));
		corpo_a_corpo->setGerGraf(ger_grafico);
		corpo_a_corpo->setPlayer(j1);
		list->push(corpo_a_corpo);

		corpo_a_corpo = new Inimigos::CorpoACorpos::Spartacus(sf::Vector2f(3750.f, 0.f));
		corpo_a_corpo->setGerGraf(ger_grafico);
		corpo_a_corpo->setPlayer(j1);
		list->push(corpo_a_corpo);

		if ((rand() % 10) >= 5) // Aleatório
		{
			corpo_a_corpo = new Inimigos::CorpoACorpos::Spartacus(sf::Vector2f(6300.f, 0.f));
			corpo_a_corpo->setGerGraf(ger_grafico);
			corpo_a_corpo->setPlayer(j1);
			list->push(corpo_a_corpo);
		}

		/*---------------------------------------------------------------------------------*/ // Disparadores
		disparador = new Inimigos::Disparadores::Merlin(sf::Vector2f(2050.f, 200.f));
		disparador->setGerGraf(ger_grafico);
		disparador->setPlayer(j1);
		list->push(disparador);

		disparador = new Inimigos::Disparadores::Merlin(sf::Vector2f(4950.f, 200.f));
		disparador->setGerGraf(ger_grafico);
		disparador->setPlayer(j1);
		list->push(disparador);

		disparador = new Inimigos::Disparadores::Merlin(sf::Vector2f(5100.f, 200.f));
		disparador->setGerGraf(ger_grafico);
		disparador->setPlayer(j1);
		list->push(disparador);

		if ((rand() % 10) >= 5) // Aleatório
		{
			disparador = new Inimigos::Disparadores::Merlin(sf::Vector2f(2450.f, 0.f));
			disparador->setGerGraf(ger_grafico);
			disparador->setPlayer(j1);
			list->push(disparador);
		}
		/*---------------------------------------------------------------------------------*/ // Chefão
		chefao = new Inimigos::Chefoes::Nidogue(sf::Vector2f(6600.f, 90.f));
		chefao->setGerGraf(ger_grafico);
		chefao->setPlayer(j1);
		list->push(chefao);
	}

	void Floresta::criarObstaculos()
	{
		Obstaculos::Inertes::Plataformas::Gramado* plat = nullptr;
		Obstaculos::Danosos::ArmadilhaDeLancas* danoso = nullptr;
		Obstaculos::Inertes::ArbustoFlorido* inerte = nullptr;
		Obstaculos::Retardantes::Lama* retardante = nullptr;

		/*---------------------------------------------------------------------------------*/ // Plataformas
		for (int i = 0; i < 12; i++)
		{
			plat = new Obstaculos::Inertes::Plataformas::Gramado (sf::Vector2f(i*600.f, ger_grafico->getWindowSize().y - 100.f), sf::Vector2f(600.f, 100.f));
			plat->setGerGraf(ger_grafico);
			list->push(static_cast<Entidade*>(plat));
		}

		plat = new Obstaculos::Inertes::Plataformas::Gramado(sf::Vector2f(600.f, ger_grafico->getWindowSize().y - 400.f), sf::Vector2f(600.f, 50.f));
		plat->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(plat));

		plat = new Obstaculos::Inertes::Plataformas::Gramado(sf::Vector2f(1900.f, ger_grafico->getWindowSize().y - 400.f), sf::Vector2f(600.f, 50.f));
		plat->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(plat));

		plat = new Obstaculos::Inertes::Plataformas::Gramado(sf::Vector2f(2200.f, ger_grafico->getWindowSize().y - 700.f), sf::Vector2f(600.f, 50.f));
		plat->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(plat));

		plat = new Obstaculos::Inertes::Plataformas::Gramado(sf::Vector2f(3400.f, ger_grafico->getWindowSize().y - 650.f), sf::Vector2f(600.f, 50.f));
		plat->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(plat));

		plat = new Obstaculos::Inertes::Plataformas::Gramado(sf::Vector2f(5400.f, ger_grafico->getWindowSize().y - 400.f), sf::Vector2f(600.f, 50.f));
		plat->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(plat));

		plat = new Obstaculos::Inertes::Plataformas::Gramado(sf::Vector2f(6600.f, ger_grafico->getWindowSize().y - 400.f), sf::Vector2f(600.f, 50.f));
		plat->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(plat));

		/*---------------------------------------------------------------------------------*/ // Retardantes

		retardante = new Obstaculos::Retardantes::Lama (sf::Vector2f(800.f, ger_grafico->getWindowSize().y - 100.f), sf::Vector2f(600.f, 100.f));
		retardante->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(retardante));

		retardante = new Obstaculos::Retardantes::Lama(sf::Vector2f(3400.f, ger_grafico->getWindowSize().y - 100.f), sf::Vector2f(600.f, 100.f));
		retardante->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(retardante));

		retardante = new Obstaculos::Retardantes::Lama(sf::Vector2f(5580.f, ger_grafico->getWindowSize().y - 100.f), sf::Vector2f(600.f, 100.f));
		retardante->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(retardante));

		/*---------------------------------------------------------------------------------*/ // Danosos

		if ((rand() % 10) >= 5) // Aleatório
		{
			danoso = new Obstaculos::Danosos::ArmadilhaDeLancas(sf::Vector2f(600.f, ger_grafico->getWindowSize().y  - 350.f));
			danoso->setGerGraf(ger_grafico);
			list->push(static_cast<Entidade*>(danoso));
		}

		danoso = new Obstaculos::Danosos::ArmadilhaDeLancas (sf::Vector2f(3*(ger_grafico->getWindowSize().x)/2, ger_grafico->getWindowSize().y - 350.f));
		danoso->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(danoso));

		danoso = new Obstaculos::Danosos::ArmadilhaDeLancas (sf::Vector2f((5*(ger_grafico->getWindowSize().x)/2) - 150, ger_grafico->getWindowSize().y - 350.f));
		danoso->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(danoso));

		danoso = new Obstaculos::Danosos::ArmadilhaDeLancas (sf::Vector2f(6600.f, ger_grafico->getWindowSize().y - 350));
		danoso->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(danoso));

		/*---------------------------------------------------------------------------------*/ // Inertes

		inerte = new Obstaculos::Inertes::ArbustoFlorido(sf::Vector2f(2250.f, ger_grafico->getWindowSize().y - 650.f));
		inerte->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*> (inerte));

		inerte = new Obstaculos::Inertes::ArbustoFlorido(sf::Vector2f(3150.f, ger_grafico->getWindowSize().y - 350.f));
		inerte->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*> (inerte));

		if ((rand() % 10) >= 5) // Aleatório
		{
			inerte = new Obstaculos::Inertes::ArbustoFlorido(sf::Vector2f(4000.f, ger_grafico->getWindowSize().y - 350.f));
			inerte->setGerGraf(ger_grafico);
			list->push(static_cast<Entidade*> (inerte));
		}

		inerte = new Obstaculos::Inertes::ArbustoFlorido(sf::Vector2f(5330.f, ger_grafico->getWindowSize().y - 350.f));
		inerte->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*> (inerte));

	}
}