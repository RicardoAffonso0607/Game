#pragma once

#include "Ente.h"

//namespace Entidade {
	class Entidade : public Ente
	{
	protected:
		sf::Vector2f pos;
		sf::Vector2f size;
		sf::Vector2f vel;
		sf::Vector2f vel_max = sf::Vector2f(10.f, 10.f);
		sf::Vector2f size_max = sf::Vector2f(200.f, 200.f);

		bool movable = false;
		bool attacker = false;
		bool retarder = false;
		bool damageable = false;
		bool facingLeft = false;
		bool projected = false;

		unsigned int attack_delay;
		unsigned int retarder_delay;
		unsigned int retarder_timer;

		float damage;
		float retard;
		float life;
		float mass = 1.f;

	public:
		Entidade(int id);
		virtual ~Entidade();

		float jumped_height = 0.f;
		bool colidiu_baixo = false;
		bool colidiu_cima = false;
		bool allow_jump = true;
		bool jumped = false;
		bool flying = true;

		virtual void move() = 0;
		virtual void attack() = 0;

		sf::Vector2f getPosition() { return body.getPosition(); }
		sf::Vector2f getEntSize() { return body.getSize(); }

		void changePosition(sf::Vector2f dif_pos) { body.move(dif_pos); }

		void subtractLife(float damaged) { life -= damaged; }
		void subtractVelocity(float retarded) { vel.x -= retarded; }

		bool getMovable() { return movable; }
		bool getAttacker() { return attacker; }
		bool getRetarder() { return retarder; }
		bool getDamageable() { return damageable; }
		bool getJumped() { return jumped; }
		bool getFacingLeft() { return facingLeft; }
		bool getProjetil() { return projected; }
		float getRetard() { return retard; }
		float getDamage() { return damage; }
		float getMass() { return mass; }
	};
//}