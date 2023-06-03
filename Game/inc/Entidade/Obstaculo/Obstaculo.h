#pragma once

#include "Entidade/Entidade.h"

class Obstaculo : public Entidade
{
protected:
	static const float mass;

	static const bool movable;
	static const bool ghost;
	static const bool damageable;

public:
	Obstaculo();
	virtual ~Obstaculo();

	bool getMovable() const override;
	bool getGhost() const override;
	bool getDamageable() const override;

	float getMass() const override;
};