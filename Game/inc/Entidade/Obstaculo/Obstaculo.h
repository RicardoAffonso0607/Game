#pragma once

#include "Entidade/Entidade.h"

class Obstaculo : public Entidade
{
protected:
	static const bool damageable;
	static const bool ghost;
	static const bool movable;

	static const float mass;

public:
	Obstaculo();
	virtual ~Obstaculo();

	bool getDamageable() const override;
	bool getGhost() const override;
	bool getMovable() const override;

	float getMass() const override;
};