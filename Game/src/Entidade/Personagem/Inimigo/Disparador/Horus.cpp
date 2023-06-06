#include "pch.h"
#include "Entidade/Personagem/Inimigo/Disparador/Horus.h"

namespace Inimigos {
	namespace Disparadores {
		const float Horus::mass = 1.f;

		const unsigned int Horus::id = 71;

		const sf::Vector2f Horus::vel_max = sf::Vector2f(1.f, 15.f);

		Horus::Horus(sf::Vector2f pos, ListaEntidades* list) :
			fogo(nullptr),
			list_ent(list)
		{
			life = 100;
			vel = vel_max;
			textura.loadFromFile(string(IMG) + "MageDesertoPA.png");
			body.setTexture(&textura);
			body.setSize(sf::Vector2f(170.f, 240.f));
			body.setPosition(pos);
			fire_cast.loadFromFile(string(SFX) + "fire-cast.wav");
			attack_instant = clock.getElapsedTime();
			sfx.setBuffer(fire_cast);
		}

		Horus::~Horus()
		{
		}

		unsigned int Horus::getId() const
		{
			return id;
		}

		float Horus::getMass() const
		{
			return mass;
		}

		void Horus::attack()
		{
			fogo = new Projeteis::EsferaDeFogo(body.getPosition());
			fogo->setGerGraf(pGerGraf);
			list_ent->push(fogo);
			if (facing_left) {
				fogo->setEsquerda();
				fogo->changePos(sf::Vector2f(-fogo->getEntSize().x, cast_height * body.getSize().y - fogo->getEntSize().y));
			}
			else {
				fogo->setDireita();
				fogo->changePos(sf::Vector2f(body.getSize().x, cast_height * body.getSize().y - fogo->getEntSize().y));
			}
			sfx.setPosition(sf::Vector3f(fogo->getPos().x, 0.f, fogo->getPos().y));
			sfx.play();
		}
	}
}