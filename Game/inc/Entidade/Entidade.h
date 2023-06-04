
#pragma once

#include "Ente.h"
#include "Gerenciador/Grafico.h"

class Entidade : public Ente
{
protected:
	static Gerenciador::Grafico* pGerGraf;

	sf::RectangleShape body;

	sf::Texture textura;

	sf::Vector2f vel_max = sf::Vector2f(10.f, 10.f);
	sf::Vector2f vel = vel_max;
	sf::Vector2f size_max = sf::Vector2f(200.f, 200.f);

	bool facingLeft;
	bool projected;

	unsigned int attack_delay;
	unsigned int retarder_delay;
	unsigned int retarder_timer;

	float mass = 1.f;
	float life = 0;

public:
	Entidade();
	virtual ~Entidade();

	static void setGerGraf(Gerenciador::Grafico* pauxGerGraf);

	void changePosition(sf::Vector2f dif_pos);
	void draw();

	virtual bool getMovable() const = 0;
	virtual bool getAttacker() const = 0;
	virtual bool getRetardant() const = 0;
	virtual bool getDamageable() const = 0;

	virtual bool getJumped() const;
	virtual bool getFacingLeft() const;

	virtual float getMass() const;
	virtual float getSlowness() const;
	virtual float getJumpStrength() const;

	virtual int getDamage() const;

	virtual sf::Vector2f getVel() const;

	sf::Vector2f getPosition() const;
	sf::Vector2f getEntSize() const;

	virtual void move();
	virtual void attack();
	virtual void applyDamage(int damage);
	virtual void applySlowness(float slowness);




	float jumped_height = 0.f;
	bool colidiu_baixo = false;
	bool colidiu_cima = false;
	bool allow_jump = true;
	bool jumped = false;
	bool flying = true;


	

};