#pragma once

#include "Entidade/Entidade.h"

class Personagem : public Entidade
{
protected:

	sf::Vector2f vel;

	sf::Time attack_instant;
	sf::Time attack_delay;
	sf::Time retarder_delay;
	sf::Time retarder_timer;

	sf::Clock clock;

	int life;

	static const bool movable;
	static const bool damageable;
	static const bool retardant;
	static const bool ghost;
	
	bool facing_left;
	bool attacker;
	bool atacou;

public:
	Personagem();
	virtual ~Personagem();

	bool getMovable() const override;
	bool getAttacker() const override;
	bool getRetardant() const override;
	bool getDamageable() const override;
	bool getFacingLeft() const override;
	bool getGhost() const override;

	sf::Vector2f getVel() const override;

	void applyDamage(int ent_damage) override;
	void applySlowness(float ent_slowness) override;
	void setAtacou() override;
	void setFacingLeft() override;
	void unsetFacingLeft() override;

	int getLife() const override;



	float jumped_height = NULL;
	bool colidiu_baixo = false;
	bool colidiu_cima = false;
	bool flying = false;


	



	//void events() /*override*/;
};