#include "pch.h"
#include "Entidade/Personagem/Inimigo/CorpoACorpo/Medjai.h"

namespace Inimigos {
	namespace CorpoACorpos {
		const float Medjai::mass = .5f;

		const unsigned int Medjai::id = 61;

		const sf::Vector2f Medjai::vel_max = sf::Vector2f(2.f, 15.f);

		Medjai::Medjai(sf::Vector2f pos, ListaEntidades* list_ent)
		{
			life = 20;
			vel = vel_max;
			textura.loadFromFile(string(IMG) + "MedjaiPA.png");
			body.setTexture(&textura);
			body.setSize(sf::Vector2f(150.f, 250.f));
			body.setPosition(pos);
			pArma = new Armas::Faca(pos);
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

		Medjai::~Medjai()
		{
			delete pArma;
		}

		unsigned int Medjai::getId() const
		{
			return id;
		}

		float Medjai::getMass() const
		{
			return mass;
		}
	}
}