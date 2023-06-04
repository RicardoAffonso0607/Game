#pragma once

class Ente
{
protected:

public:
	Ente();
	virtual ~Ente();

	virtual unsigned int getId() const = 0;
};