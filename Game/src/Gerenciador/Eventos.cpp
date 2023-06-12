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
			else if (evento.type == sf::Event::MouseButtonPressed)
				verificaMouseClicado();
			else if (evento.type == sf::Event::Closed)
				pGrafico->fecharJanela();
		}
	}

	void Eventos::verificaTeclaPressionada(sf::Keyboard::Key tecla)
	{
		if (tecla == sf::Keyboard::P)
		{
			sf::Event resume;
			pGrafico->getWindow()->setTitle("Jogo pausado!");
			while (1) {
				pGrafico->getWindow()->waitEvent(resume);
				if (resume.type == sf::Event::MouseButtonPressed)
					break;
			}
			pGrafico->getWindow()->setTitle("Age of Wars++");
		}
		else if (tecla == sf::Keyboard::Escape)
		{
			pGrafico->fecharJanela();
			Gerenciador::Salvamento* pSalvamento = new Gerenciador::Salvamento;
			//pSalvamento->salvarJogo(list_ent);
			delete pSalvamento;
		}
	}

	void Eventos::verificaMouseClicado()
	{
	}
}
