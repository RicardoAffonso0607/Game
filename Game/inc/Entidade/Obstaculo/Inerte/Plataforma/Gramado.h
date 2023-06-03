#pragma once

#include "Entidade/Obstaculo/Inerte/Plataforma/Plataforma.h"

namespace Plataformas {
	class Gramado : public Plataforma
	{
	private:
		static const int id;

	public:
		Gramado(sf::Vector2f plat_pos, sf::Vector2f plat_size);
		~Gramado();

		unsigned int getId() const override;
	};
}