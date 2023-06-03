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

	virtual sf::Vector2f getPosition() = 0;
	virtual sf::Vector2f getEntSize() = 0;
	virtual sf::Vector2f getVel() = 0;
	virtual sf::Vector2f getVelMax() = 0;

	virtual void move() = 0;
	virtual void attack() = 0;
	virtual void gunType() = 0;
	virtual void setPlayer() = 0;
	virtual void changePosition() = 0;
	virtual void subtractLife() = 0;
	virtual void subtractVelocity() = 0;
	virtual void setAttacker() = 0;
	virtual void getGun() = 0;
	virtual void events() = 0;
	virtual void setAtacou() = 0;
	virtual void setPlayer() = 0;
	virtual void setCaster() = 0;

	virtual bool getMovable() = 0;
	virtual bool getAttacker() = 0;
	virtual bool getRetarder() = 0;
	virtual bool getDamageable() = 0;
	virtual bool getJumped() = 0;
	virtual bool getFacingLeft() = 0;
	virtual bool getProjetil() = 0;

	virtual int getDamage() = 0;

	virtual float getRetard() = 0;
	virtual float getMass() = 0;
	virtual float getJumpStrength() = 0;
};