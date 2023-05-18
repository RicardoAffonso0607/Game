#pragma once

/* Código baseado no vídeo do Felipe Alvez Barboza, monitor de 2020*/
#include "stdafx.h"
#include "Lista/Elemento.h"

using namespace std;

template<class Tipo> 
class Lista
{
private:
	Elemento<Tipo>* pInicio;
	Elemento<Tipo>* pFinal;
	int tam;

public:
	Lista();
	~Lista();

	int getTamanho() { return tam; }

	Tipo* getItem(int posicao);

	void push(Tipo* pT);
	void pop(Tipo* pT);

};

/*-------------------------------*/

template<class Tipo>
inline Lista<Tipo>::Lista()
{
	pInicio = nullptr;
	pFinal = nullptr;
	tam = 0;
}

template<class Tipo>
inline Lista<Tipo>::~Lista()
{
}

template<class Tipo>
inline Tipo* Lista<Tipo>::getItem(int posicao)
{
	Elemento<Tipo*> temp = pInicio;

	//Testar se a lista esta vazia
	if (temp == nullptr)
	{
		cout << "A lista está vazia" << endl;
		return nullptr;
	}
	else
	{
		if (posicao == 0)
			return temp->getDados();
		else
		{
			for (int i = 0; i < posicao; i++)
			{
				temp = temp->getProx();
			}

			return temp->getDados();
		}
		
	}

}

template<class Tipo>
inline void Lista<Tipo>::push(Tipo* pT)
{

	if (pInicio == nullptr) //Lista vazia
	{
		pInicio = new Elemento<Tipo*>();
		if (pT)
		{
			pInicio->setDado(pT);
			tam++;
		}
		else
			cout << "Elemento não adicionado na lista" << endl;

		pFinal = pInicio;
	}
	else //Lista não vazia
	{
		Elemento<Tipo*> temp = new Elemento<Tipo*>();
		if (pT)
		{
			temp->setDado(pT);
			tam++;
		}
		else
			cout << "Elemento não adicionado na lista" << endl;

		pFinal->setProx(temp);
		pFinal = temp;
	}
}

template<class Tipo>
inline void Lista<Tipo>::pop(Tipo* pT)
{
	if (pT)
	{

		if (pInicio == nullptr)
		{
			cout << "Não havia elementos na lista" << endl;
			return nullptr;
		}
		else
		{
			Elemento<Tipo*> temp = pInicio;
			Elemento<Tipo*> tempAnt = nullptr;

			while (temp != pT || temp == nullptr)
			{
				tempAnt = temp;
				temp = temp->getProx();
			}

			if (temp == pInicio)
				pInicio = temp->getProx();
			else if (temp == pFinal)
			{
				tempAnt->setProx(nullptr);
				pFinal = tempAnt;
			}
			else
				tempAnt->setProx(temp->getProx());

			delete temp;
			tam--;

		}
	}
	else
		cout << "Ponteiro Nulo" << endl;
}
