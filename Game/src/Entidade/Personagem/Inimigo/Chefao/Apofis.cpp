#include "pch.h"
#include "Entidade/Personagem/Inimigo/Chefao/Apofis.h"

namespace Inimigos {
	namespace Chefoes {
		const float Apofis::mass = 1.5f;

		const unsigned int Apofis::id = 51;

		const sf::Vector2f Apofis::vel_max = sf::Vector2f(5.f, 15.f);

		Apofis::Apofis(sf::Vector2f pos, ListaEntidades* list) :
			fogo(nullptr),
			list_ent(list)
		{
			life = 100;
			vel = vel_max;
			textura.loadFromFile(string(IMG) + "DragaoDesertoPA.png");
			body.setTexture(&textura);
			body.setSize(sf::Vector2f(400.f, 500.f));
			body.setPosition(pos);
			fire_cast.loadFromFile(string(SFX) + "fire-cast.wav");
			attack_delay = sf::milliseconds(1000);
			attack_instant = clock.getElapsedTime();
			sfx.setBuffer(fire_cast);
		}

		Apofis::~Apofis()
		{
		}

		unsigned int Apofis::getId() const
		{
			return id;
		}

		float Apofis::getMass() const
		{
			return mass;
		}

		void Apofis::attack()
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