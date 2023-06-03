#include "pch.h"
#include "Entidade/Entidade.h"
#include "Gerenciador/Grafico.h"

Entidade::Entidade(bool mov, bool dam, bool pro, bool gho) :
	movable(mov),
	damageable(dam),
	projected(pro),
	ghost(gho)
{
}

Entidade::~Entidade()
{
}

Entidade::draw() {
	pGerGraf->desenhaElemento(body);
}