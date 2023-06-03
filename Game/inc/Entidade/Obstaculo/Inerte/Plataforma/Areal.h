#pragma once

#include "Entidade/Obstaculo/Inerte/Plataforma/Plataforma.h"

namespace Plataformas {
	class Areal : public Plataforma
	{
	private:
		static const int id;

	public:
		Areal(sf::Vector2f pos, sf::Vector2f size, int id);
		~Areal();

		int getId() const override;
	};
}