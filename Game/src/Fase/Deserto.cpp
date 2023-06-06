#include "pch.h"
#include "Fase/Deserto.h"

namespace Fases {
	Deserto::Deserto()
	{
		list->clear();
		criarJogador();
		criarInimigos();
		criarObstaculos();
		colisor = new Gerenciador::Colisao(list, ger_grafico);
		background_texture.loadFromFile(string(IMG) + "DesertoPA.png");
		background.setSize(sf::Vector2f(ger_grafico->getWindowSize()));
		background.setTexture(&background_texture);
		background_auxiliar.setSize(sf::Vector2f(ger_grafico->getWindowSize()));
		background_auxiliar.setTexture(&background_texture);
		background_auxiliar.setPosition( (float) ger_grafico->getWindowSize().x, 0.f);
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
		ger_grafico->desenhaElemento(background_auxiliar);

		if (j1->getPos().x > ger_grafico->getWindowSize().x / 2.f)
			ger_grafico->getCamera()->setCenter(j1->getPos().x, ger_grafico->getWindowSize().y / 2.f);
		//Câmera no inicio
		if (j1->getPos().x > ger_grafico->getWindowSize().x / 2.f)
			ger_grafico->getCamera()->setCenter(j1->getPos().x, ger_grafico->getWindowSize().y / 2.f);
		else
			ger_grafico->getCamera()->setCenter(ger_grafico->getWindowSize().x / 2.f, ger_grafico->getWindowSize().y / 2.f);

		if (ger_grafico->getCamera()->getCenter().x >= 3.f * (background.getPosition().x + ger_grafico->getWindowSize().x) / 2.f)
			background.setPosition(2.f * ger_grafico->getWindowSize().x, 0.f);
		//Atualizar os planos de fundo
		if (ger_grafico->getCamera()->getCenter().x >= 3.f * (background.getPosition().x + ger_grafico->getWindowSize().x) / 2.f)
			background.setPosition(2.f * ger_grafico->getWindowSize().x, 0.f);

		if (ger_grafico->getCamera()->getCenter().x >= 2.5f * (background_auxiliar.getPosition().x))
			background_auxiliar.setPosition(3.f * ger_grafico->getWindowSize().x, 0.f);

		//Câmera no final
		if (j1->getPos().x > (7.f * ger_grafico->getWindowSize().x / 2.f) - 150.f)
			ger_grafico->getCamera()->setCenter((7.f * ger_grafico->getWindowSize().x / 2.f) - 150.f, (ger_grafico->getWindowSize().y / 2.f));

		draw();
	}

	void Deserto::criarJogador()
	{
		j1 = new Jogadores::Lutadora(sf::Vector2f(300.f, 10.f), 50);
		ger_eventos->setJogador(j1);
		j1->setGun(arma = new Armas::Arco(sf::Vector2f(300.f, 10.f), list));
		j1->setGerGraf(ger_grafico);
		list->push(j1);
		arma->setGerGraf(ger_grafico);
		list->push(arma);
	}

	void Deserto::criarInimigos()
	{
		Inimigos::CorpoACorpos::Medjai* corpo_a_corpo = nullptr;
		Inimigos::Disparadores::Horus* disparador = nullptr;
		Inimigos::Chefoes::Apofis* chefao = nullptr;

		/*---------------------------------------------------------------------------------*/ // Corpo a Corpos
		corpo_a_corpo = new Inimigos::CorpoACorpos::Medjai(sf::Vector2f(900.f, 200.f));
		corpo_a_corpo->setGerGraf(ger_grafico);
		corpo_a_corpo->setPlayer(j1);
		list->push(corpo_a_corpo);

		corpo_a_corpo = new Inimigos::CorpoACorpos::Medjai(sf::Vector2f(1600.f, 500.f));
		corpo_a_corpo->setGerGraf(ger_grafico);
		corpo_a_corpo->setPlayer(j1);
		list->push(corpo_a_corpo);

		corpo_a_corpo = new Inimigos::CorpoACorpos::Medjai(sf::Vector2f(3750.f, 0.f));
		corpo_a_corpo->setGerGraf(ger_grafico);
		corpo_a_corpo->setPlayer(j1);
		list->push(corpo_a_corpo);

		if ((rand() % 10) >= 5) // Aleatório
		{
			corpo_a_corpo = new Inimigos::CorpoACorpos::Medjai(sf::Vector2f(6300.f, 0.f));
			corpo_a_corpo->setGerGraf(ger_grafico);
			corpo_a_corpo->setPlayer(j1);
			list->push(corpo_a_corpo);
		}

		/*---------------------------------------------------------------------------------*/ // Disparadores
		disparador = new Inimigos::Disparadores::Horus(sf::Vector2f(2050.f, 200.f), list);
		disparador->setGerGraf(ger_grafico);
		disparador->setPlayer(j1);
		list->push(disparador);

		disparador = new Inimigos::Disparadores::Horus(sf::Vector2f(4950.f, 200.f), list);
		disparador->setGerGraf(ger_grafico);
		disparador->setPlayer(j1);
		list->push(disparador);

		disparador = new Inimigos::Disparadores::Horus(sf::Vector2f(5100.f, 200.f), list);
		disparador->setGerGraf(ger_grafico);
		disparador->setPlayer(j1);
		list->push(disparador);

		if ((rand() % 10) >= 5) // Aleatório
		{
			disparador = new Inimigos::Disparadores::Horus(sf::Vector2f(2450.f, 0.f), list);
			disparador->setGerGraf(ger_grafico);
			disparador->setPlayer(j1);
			list->push(disparador);
		}
		/*---------------------------------------------------------------------------------*/ // Chefão
		chefao = new Inimigos::Chefoes::Apofis(sf::Vector2f(6600.f, 90.f), list);
		chefao->setGerGraf(ger_grafico);
		chefao->setPlayer(j1);
		list->push(chefao);
	}

	void Deserto::criarObstaculos()
	{
		Obstaculos::Inertes::Plataformas::Areal* plat = nullptr;
		Obstaculos::Danosos::Cacto* danoso = nullptr;
		Obstaculos::Inertes::ArbustoSeco* inerte = nullptr;
		Obstaculos::Retardantes::AreiaMovedica* retardante = nullptr;

		/*---------------------------------------------------------------------------------*/ // Plataformas
		for (int i = 0; i < 12; i++)
		{
			plat = new Obstaculos::Inertes::Plataformas::Areal(sf::Vector2f(i * 600.f, ger_grafico->getWindowSize().y - 100.f), sf::Vector2f(600.f, 100.f));
			plat->setGerGraf(ger_grafico);
			list->push(static_cast<Entidade*>(plat));
		}

		plat = new Obstaculos::Inertes::Plataformas::Areal(sf::Vector2f(600.f, ger_grafico->getWindowSize().y - 400.f), sf::Vector2f(600.f, 50.f));
		plat->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(plat));

		plat = new Obstaculos::Inertes::Plataformas::Areal(sf::Vector2f(1900.f, ger_grafico->getWindowSize().y - 400.f), sf::Vector2f(600.f, 50.f));
		plat->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(plat));

		plat = new Obstaculos::Inertes::Plataformas::Areal(sf::Vector2f(2200.f, ger_grafico->getWindowSize().y - 700.f), sf::Vector2f(600.f, 50.f));
		plat->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(plat));

		plat = new Obstaculos::Inertes::Plataformas::Areal(sf::Vector2f(3400.f, ger_grafico->getWindowSize().y - 650.f), sf::Vector2f(600.f, 50.f));
		plat->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(plat));

		plat = new Obstaculos::Inertes::Plataformas::Areal(sf::Vector2f(5400.f, ger_grafico->getWindowSize().y - 400.f), sf::Vector2f(600.f, 50.f));
		plat->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(plat));

		plat = new Obstaculos::Inertes::Plataformas::Areal(sf::Vector2f(6600.f, ger_grafico->getWindowSize().y - 400.f), sf::Vector2f(600.f, 50.f));
		plat->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(plat));

		/*---------------------------------------------------------------------------------*/ // Retardantes

		retardante = new Obstaculos::Retardantes::AreiaMovedica(sf::Vector2f(800.f, ger_grafico->getWindowSize().y - 100.f), sf::Vector2f(600.f, 100.f));
		retardante->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(retardante));

		retardante = new Obstaculos::Retardantes::AreiaMovedica(sf::Vector2f(3400.f, ger_grafico->getWindowSize().y - 100.f), sf::Vector2f(600.f, 100.f));
		retardante->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(retardante));

		retardante = new Obstaculos::Retardantes::AreiaMovedica(sf::Vector2f(5580.f, ger_grafico->getWindowSize().y - 100.f), sf::Vector2f(600.f, 100.f));
		retardante->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(retardante));

		/*---------------------------------------------------------------------------------*/ // Danosos

		if ((rand() % 10) >= 5) // Aleatório
		{
			danoso = new Obstaculos::Danosos::Cacto(sf::Vector2f(600.f, ger_grafico->getWindowSize().y - 350.f));
			danoso->setGerGraf(ger_grafico);
			list->push(static_cast<Entidade*>(danoso));
		}

		danoso = new Obstaculos::Danosos::Cacto(sf::Vector2f(3 * (ger_grafico->getWindowSize().x) / 2.f, ger_grafico->getWindowSize().y - 350.f));
		danoso->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(danoso));

		danoso = new Obstaculos::Danosos::Cacto(sf::Vector2f((5 * (ger_grafico->getWindowSize().x) / 2.f) - 150.f, ger_grafico->getWindowSize().y - 350.f));
		danoso->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(danoso));

		danoso = new Obstaculos::Danosos::Cacto(sf::Vector2f(6600.f, ger_grafico->getWindowSize().y - 350.f));
		danoso->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*>(danoso));

		/*---------------------------------------------------------------------------------*/ // Inertes

		inerte = new Obstaculos::Inertes::ArbustoSeco(sf::Vector2f(2250.f, ger_grafico->getWindowSize().y - 650.f));
		inerte->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*> (inerte));

		inerte = new Obstaculos::Inertes::ArbustoSeco(sf::Vector2f(3150.f, ger_grafico->getWindowSize().y - 350.f));
		inerte->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*> (inerte));

		if ((rand() % 10) >= 5) // Aleatório
		{
			inerte = new Obstaculos::Inertes::ArbustoSeco(sf::Vector2f(4000.f, ger_grafico->getWindowSize().y - 350.f));
			inerte->setGerGraf(ger_grafico);
			list->push(static_cast<Entidade*> (inerte));
		}

		inerte = new Obstaculos::Inertes::ArbustoSeco(sf::Vector2f(5330.f, ger_grafico->getWindowSize().y - 350.f));
		inerte->setGerGraf(ger_grafico);
		list->push(static_cast<Entidade*> (inerte));
	}
}