#include "pch.h"
#include "Gerenciador/Salvamento.h"

using namespace std;

namespace Gerenciador{
	Salvamento* Salvamento::pSalvamento(nullptr);

	Salvamento::Salvamento()
	{
	}

	Salvamento::~Salvamento()
	{
		pSalvamento = nullptr;
	}

	void Salvamento::carregar(Grafico* ger_graf)
	{
		ifstream progresso("jogo_salvo.csv");
		if (progresso.is_open()) {
			progresso.close();
		}
		else {
			string erro = "Não foi possível carregar o progresso do jogo.";
			try { throw runtime_error(erro); }
			catch (...) {
				cerr << erro << endl;
				exit(1);
			}
		}
	}

	void Salvamento::getDados(ListaEntidades* list_ent)
	{
	}

	void Salvamento::salvar()
	{
		ofstream progresso("jogo_salvo.txt");
		progresso.clear();
		if (progresso.is_open()) {
			//char* buffer_dados = new char[sizeof(multimap<unsigned int, tuple<int, sf::Vector2f, sf::Clock, int32_t>>)];
			//progresso.write(buffer_dados, sizeof(dados));
			for (auto i : dados) {
				progresso << i.first << "," << get<0>(i.second) << "," << get<1>(i.second).x << "," << get<1>(i.second).y << ","
					      << get<2>(i.second).asMilliseconds() << "," << get<3>(i.second) << endl;
			}
			progresso.close();
		}
		else {
			string erro = "Não foi possível salvar o progresso do jogo.";
			try { throw runtime_error(erro); }
			catch (...) {
				cerr << erro << endl;
				exit(1);
			}
		}
	}

	void Salvamento::limpar()
	{
		ofstream progresso("jogo_salvo.txt");
		progresso.clear();
		progresso.close();
	}

	Salvamento* Salvamento::getSalvamento()
	{
		if(!pSalvamento)
			pSalvamento = new Salvamento();
		return pSalvamento;
	}
}