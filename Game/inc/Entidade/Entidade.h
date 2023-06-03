#pragma once

#include "Ente.h"

class Entidade : public Ente
{
protected:
	sf::RectangleShape body;

	sf::Texture textura;

public:
	Entidade();
	virtual ~Entidade();

	void draw();

	virtual sf::Vector2f getPosition();
	virtual sf::Vector2f getEntSize();
	virtual sf::Vector2f getVel();
	virtual sf::Vector2f getVelMax();

	virtual void move();
	virtual void attack();
	virtual void gunType();
	virtual void setPlayer();
	virtual void changePosition();
	virtual void subtractLife();
	virtual void subtractVelocity();
	virtual void setAttacker();
	virtual void getGun();
	virtual void events();
	virtual void setAtacou();
	virtual void setPlayer();
	virtual void setCaster();

	virtual bool getMovable();
	virtual bool getAttacker();
	virtual bool getRetardant();
	virtual bool getDamageable();
	virtual bool getJumped();
	virtual bool getFacingLeft();
	virtual bool getProjetil();

	virtual int getDamage();

	virtual float getSlowness();
	virtual float getMass();
	virtual float getJumpStrength();
};