#include "pch.h"
#include "Entidade/Personagem/Inimigo/Chefao/Nidogue.h"

namespace Inimigos {
	namespace Chefoes {
		const float Nidogue::mass = 1.5f;

		const unsigned int Nidogue::id = 52;

		const sf::Vector2f Nidogue::vel_max = sf::Vector2f(5.f, 15.f);

		Nidogue::Nidogue(sf::Vector2f pos, ListaEntidades* list) :
			gelo(nullptr),
			list_ent(list)
		{
			life = 100;
			vel = vel_max;
			textura.loadFromFile(string(IMG) + "DragaoFlorestaPA.png");
			body.setTexture(&textura);
			body.setSize(sf::Vector2f(400.f, 500.f));
			body.setPosition(pos);
			ice_cast.loadFromFile(string(SFX) + "ice-cast.wav");
			attack_delay = sf::milliseconds(1000);
			attack_instant = clock.getElapsedTime();
			sfx.setBuffer(ice_cast);
		}

		Nidogue::~Nidogue()
		{
		}

		unsigned int Nidogue::getId() const
		{
			return id;
		}

		float Nidogue::getMass() const
		{
			return mass;
		}

		void Nidogue::attack()
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
			sfx.setPosition(sf::Vector3f(gelo->getPos().x, 0.f, gelo->getPos().y));
			sfx.play();
		}
	}
}