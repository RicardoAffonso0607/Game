#pragma once

template <class Tipo> class Elemento
{
private:
	Elemento<Tipo*> pProx;
	Tipo* dados;

public:
	Elemento();
	~Elemento();

	void setProx(Elemento<Tipo*> pP) { pProx = pP; }
	void setDado(Tipo* dd) { dados = dd; }

	Elemento<Tipo*> getProx() { return pProx; }
	Tipo* getDados() { return dados; }
};

template<class Tipo>
inline Elemento<Tipo>::Elemento()
{
	pProx = nullptr;
	dados = nullptr;
}

template<class Tipo>
inline Elemento<Tipo>::~Elemento()
{	
}
