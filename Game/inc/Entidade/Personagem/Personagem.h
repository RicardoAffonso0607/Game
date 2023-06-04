#pragma once

#include "Entidade/Entidade.h"

class Personagem : public Entidade
{
protected:
	int damage = 0;
	sf::Vector2f vel_max;
	sf::Vector2f vel;

	sf::Time attack_delay = sf::Time::Zero;
	sf::Time attack_timer = sf::Time::Zero;
	sf::Time attack_instant = sf::Time::Zero;

	sf::Clock clock;

	static const bool movable = true;
	static const bool damageable = true;
	//static const bool projected = false;
	static const bool retardant = false;

	bool facing_left = false;
	bool atacou = false;
	bool attacker = false;

public:
	Personagem();
	virtual ~Personagem();

	float jumped_height = NULL;

	bool colidiu_baixo = false;
	bool colidiu_cima = false;
	bool flying = false;

	sf::Vector2f getPosition() /*override*/;
	sf::Vector2f getEntSize() /*override*/;
	sf::Vector2f getVel() /*override*/;
	sf::Vector2f getVelMax() /*override*/;

	void changePosition(sf::Vector2f dif_pos) /*override*/;
	void subtractLife(float damaged) /*override*/;
	void subtractVelocity(float retarded) /*override*/;
	void events() /*override*/;
	void setAtacou() /*override*/;

	bool getMovable() const override;
	bool getAttacker() const override;
	bool getRetardant() const override;
	bool getDamageable() const override;
	//bool getFacingLeft() const override;
	//bool getProjetil() const override;

	int getDamage() /*override*/;
	float getMass() /*override*/;
};