#include "pch.h"
#include "Gerenciador/Eventos.h"

namespace Gerenciador {
	Eventos* Eventos::pEventos(nullptr);

	Eventos::Eventos() :
		pGrafico(pGrafico->getGrafico()),
		pJogador(nullptr)
	{
	}

	Eventos::~Eventos()
	{
		pGrafico = nullptr;
		pJogador = nullptr;
	}

	Eventos* Eventos::getEventos()
	{
		if (pEventos == nullptr)
			pEventos = new Eventos();

		return pEventos;

	}

	void Eventos::executar()
	{
		sf::Event evento;

		while (pGrafico->getWindow()->pollEvent(evento))
		{
			if (evento.type == sf::Event::KeyPressed)
				verificaTeclaPressionada(evento.key.code);
			if (evento.type == sf::Event::MouseButtonPressed)
				verificaMouseClicado();
			if (evento.type == sf::Event::Closed)
				pGrafico->fecharJanela();

		}
	}

	void Eventos::verificaTeclaPressionada(sf::Keyboard::Key tecla)
	{
		if (tecla == sf::Keyboard::A || tecla == sf::Keyboard::Left)
		{
			//pJogador->changePos(sf::Vector2f(-pJogador->getVel().x, 0.f));
		}
		if (tecla == sf::Keyboard::D || tecla == sf::Keyboard::Right)
		{
			//pJogador->changePos(sf::Vector2f(pJogador->getVel().x, 0.f));
		}

		//if (tecla == sf::Keyboard::Space)
		//	pJogador->jumped = true;//pulou

		//if (tecla == sf::Keyboard::Backslash)
			//pJogador->setAttacker(pJogador->getGunType(), ATQ_LONGO);//ataque tipo 1

		if (tecla == sf::Keyboard::Escape)
		{
			pGrafico->fecharJanela();
		}
	}

	void Eventos::verificaMouseClicado()
	{
		//if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			//pJogador->setAttacker(pJogador->getGunType(), ATQ_CURTO);//ataque tipo 2
	}
}
