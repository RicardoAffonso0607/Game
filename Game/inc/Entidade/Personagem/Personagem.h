#pragma once

#include "Entidade/Entidade.h"

class Personagem : public Entidade
{
protected:
	sf::Vector2f vel_max;
	sf::Vector2f vel;

	sf::Time attack_delay;
	sf::Time attack_timer;
	sf::Time attack_instant;

	sf::Clock clock;

	const bool movable;
	const bool damageable;
	const bool projected;

	bool facing_left;
	bool atacou;

	float damage;
	float life;
	float mass;

public:
	Personagem();
	virtual ~Personagem();

	float jumped_height;

	bool colidiu_baixo;
	bool colidiu_cima;
	bool flying;

	sf::Vector2f getPosition() override;
	sf::Vector2f getEntSize() override;
	sf::Vector2f getVel() override;
	sf::Vector2f getVelMax() override;

	void changePosition(sf::Vector2f dif_pos) override;
	void subtractLife(float damaged) override;
	void subtractVelocity(float retarded) override;
	void events() override;
	void setAtacou() override;

	bool getMovable() override;
	bool getAttacker() override;
	bool getRetardant() override;
	bool getDamageable() override;
	bool getFacingLeft() override;
	bool getProjetil() override;

	int getDamage() override;
	float getMass() override;
};