#pragma once

#include "Entidade/Entidade.h"

class Obstaculo : public Entidade
{
protected:

public:
	Obstaculo();
	virtual ~Obstaculo();

	void move();
	void attack();
};