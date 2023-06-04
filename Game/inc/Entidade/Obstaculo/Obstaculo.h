#pragma once

#include "Entidade/Entidade.h"

class Obstaculo : public Entidade
{
protected:
	static const bool damageable = false;
	static const bool ghost = false;
	static const bool movable = false;
	static const bool projected = false;

public:
	Obstaculo();
	virtual ~Obstaculo();

	bool getDamageable() const /*override*/;
	bool getGhost() const /*override*/;
	bool getMovable() const /*override*/;
};