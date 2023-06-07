#include "pch.h"
#include "Entidade/Personagem/Inimigo/CorpoACorpo/Spartacus.h"

namespace Inimigos {
	namespace CorpoACorpos {
		const float Spartacus::mass = .5f;

		const unsigned int Spartacus::id = 62;

		const sf::Vector2f Spartacus::vel_max = sf::Vector2f(5.f, 15.f);

		Spartacus::Spartacus(sf::Vector2f pos, ListaEntidades* list_ent)
		{
			life = 50;
			vel = vel_max;
			textura.loadFromFile(string(IMG) + "Spartacus.png");
			body.setTexture(&textura);
			body.setSize(sf::Vector2f(250.f, 300.f));
			body.setPosition(pos);
			pArma = new Armas::Espada(pos);
			pArma->setGerGraf(pGerGraf);
			list_ent->push(pArma);
			if (facing_left) {
				pArma->setEsquerda();
				pArma->setEntPos(body.getPosition() + sf::Vector2f(-pArma->getEntSize().x, gun_pos * body.getSize().y - pArma->getEntSize().y));
			}
			else {
				pArma->setDireita();
				pArma->setEntPos(body.getPosition() + sf::Vector2f(body.getSize().x, gun_pos * body.getSize().y - pArma->getEntSize().y));
			}
			attack_radius = .5f * body.getSize().x + pArma->getEntSize().y + 100.f;
		}

		Spartacus::~Spartacus()
		{
			delete pArma;
		}

		unsigned int Spartacus::getId() const
		{
			return id;
		}

		float Spartacus::getMass() const
		{
			return mass;
		}
	}
}