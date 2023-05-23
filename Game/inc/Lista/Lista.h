//#pragma once
//
///* C�digo baseado no v�deo do Felipe Alvez Barboza, monitor de 2020*/
//
//#include "Lista/Elemento.h"
//#include <iostream>
//using namespace std;
//
//template<class Tipo>class Lista
//{
//private:
//	Elemento<Tipo> *pInicio;
//	Elemento<Tipo> *pFinal;
//	int tam;
//
//public:
//	Lista();
//	~Lista();
//
//	int getTamanho() { return tam; }
//
//	Tipo* getItem(int posicao);
//
//	void push(Tipo *pT);
//	void pop(Tipo *pT);
//
//};
//
///*-------------------------------*/
//
//Lista::Lista()
//{
//	pInicio = nullptr;
//	pFinal = nullptr;
//	tam = 0;
//}
//
//Lista::~Lista()
//{
//}

//Lista::getItem(int posicao){
//	Elemento<Tipo> *temp = pInicio;	
//	if (temp == nullptr){// Testar se a lista esta vazia
//		cout << "A lista est� vazia" << endl;
//		return nullptr;
//	}
//	else{
//		if (posicao == 0)
//			return temp->getDados();
//		else{
//			for (int i = 0; i < posicao; i++)
//				temp = temp->getProx();
//			return temp->getDados();
//		}
//	}
//}
//
//Lista::push(Tipo *pT){
//	if (pInicio == nullptr){// Lista vazia
//		pInicio = new Elemento<Tipo>;
//		if (pT){
//			pInicio->setDado(pT);
//			tam++;
//		}
//		else
//			cout << "Elemento n�o adicionado � lista" << endl;
//		pFinal = pInicio;
//	}
//	else { //Lista n�o vazia
//		Elemento<Tipo> *temp = new Elemento<Tipo>();
//		if (pT)
//		{
//			temp->setDado(pT);
//			tam++;
//		}
//		else
//			cout << "Elemento n�o adicionado � lista" << endl;
//		pFinal->setProx(temp);
//		pFinal = temp;
//	}
//}
//
//Lista::pop(Tipo* pT){
//	if (pT){
//		if (pInicio == nullptr){
//			cout << "N�o havia elementos na lista" << endl;
//			return nullptr;
//		}
//		else{
//			Elemento<Tipo*> temp = pInicio;
//			Elemento<Tipo*> tempAnt = nullptr;
//			while (temp->getDado() != pT || temp == nullptr){
//				tempAnt = temp;
//				temp = temp->getProx();
//			}
//			if (temp == pInicio)
//				pInicio = temp->getProx();
//			else if (temp == pFinal){
//				tempAnt->setProx(nullptr);
//				pFinal = tempAnt;
//			}
//			else
//				tempAnt->setProx(temp->getProx());
//			delete temp;
//			tam--;
//		}
//	}
//	else
//		cout << "Ponteiro Nulo" << endl;
//}
