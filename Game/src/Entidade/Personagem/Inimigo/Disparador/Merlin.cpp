#include "pch.h"
#include "Entidade/Personagem/Inimigo/Disparador/Merlin.h"

namespace Inimigos {
	namespace Disparadores {
		const float Merlin::mass = 1.f;

		const unsigned int Merlin::id = 72;

		const sf::Vector2f Merlin::vel_max = sf::Vector2f(2.f, 15.f);

		Merlin::Merlin(sf::Vector2f pos, ListaEntidades* list) :
			gelo(nullptr),
			list_ent(list)
		{
			life = 40;
			vel = vel_max;
			textura.loadFromFile(string(IMG) + "Mage.png");
			body.setTexture(&textura);
			body.setSize(sf::Vector2f(170.f, 240.f));
			body.setPosition(pos);
			ice_cast.loadFromFile(string(SFX) + "ice-cast.wav");
			attack_instant = clock.getElapsedTime();
			sfx.setBuffer(ice_cast);
		}

		Merlin::~Merlin()
		{
		}

		unsigned int Merlin::getId() const
		{
			return id;
		}

		float Merlin::getMass() const
		{
			return mass;
		}

		void Merlin::attack()
		{
			gelo = new Projeteis::EsferaDeGelo(body.getPosition());
			gelo->setGerGraf(pGerGraf);
			list_ent->push(gelo);
			if (facing_left) {
				gelo->setEsquerda();
				gelo->changePos(sf::Vector2f(-gelo->getEntSize().x, cast_height * body.getSize().y - gelo->getEntSize().y));
			}
			else {
				gelo->setDireita();
				gelo->changePos(sf::Vector2f(body.getSize().x, cast_height * body.getSize().y - gelo->getEntSize().y));
			}
			sfx.setPosition(sf::Vector3f(gelo->getPos().x,0.f, gelo->getPos().y));
			sfx.play();
		}
	}
}