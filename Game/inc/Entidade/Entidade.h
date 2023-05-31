#pragma once

#include "Ente.h"

class Entidade : public Ente
{
protected:
	sf::Vector2f pos;

	bool movable;
	bool attacker;
	bool retarder;
	bool damageable;
	bool jumped = false;
	bool jump_unlocked = true;

public:
	Entidade(int id);
	~Entidade();

	virtual void move() = 0;
	virtual void attack() = 0;

	sf::Vector2f getPosition() { return body.getPosition(); }
	sf::Vector2f getEntSize() { return body.getSize(); }
	void changePosition(sf::Vector2f dif_pos) { body.move(dif_pos); }
	bool isMovable() { return movable; }
	bool isAttacker() { return attacker; }
	bool isRetarder() { return retarder; }
	bool isDamageable() { return damageable; }
	bool isJumped() { return jumped; }
	void offJumped() { jumped = false; }
	void blockJumped() { jump_unlocked = false; }
	void allowJumped() { jump_unlocked = true; }
};

