#pragma once

#include "Ente.h"

class Entidade : public Ente
{
protected:
	sf::Vector2f pos;
	sf::Vector2f size;
	sf::Vector2f vel;
	sf::Vector2f vel_max;
	sf::Vector2f size_max;

	sf::String player_nickname;

	sf::RectangleShape body;

	sf::Time attack_delay;
	sf::Time retarder_delay;
	sf::Time retarder_timer;

	//sf::Clock clock;

	bool movable;
	bool attacker;
	bool retarder;
	bool damageable;
	bool facingLeft;
	bool projected;
	
	float pontuacao;
	float damage;
	float retard;
	float life;
	float mass;
	float jump_strength;

public:
	Entidade();
	virtual ~Entidade();

	float jumped_height = 0.f;

	bool colidiu_baixo = false;
	bool colidiu_cima = false;
	bool allow_jump = true;
	bool jumped = false;
	bool flying = true;

	virtual void move() = 0;
	virtual void attack() = 0;
	virtual void gunType() = 0;
	virtual void setPlayer() = 0;

	sf::Vector2f getPosition() { return body.getPosition(); }
	sf::Vector2f getEntSize() { return body.getSize(); }
	sf::Vector2f getVel() { return vel; }
	sf::Vector2f getVelMax() { return vel_max; }

	void draw() { pGerGraf->desenhaElemento(body); }
	void changePosition(sf::Vector2f dif_pos) { body.move(dif_pos); }
	void subtractLife(float damaged) { life -= damaged; }
	void subtractVelocity(float retarded) { vel.x -= retarded; }
	void setAttacker(int i){}

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
	float getJumpStrength() { return jump_strength; }
};