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

	void Salvamento::carregarJogo(Grafico* ger_graf)
	{
		ifstream progresso("jogo_salvo.csv");
		if (progresso.is_open()) {
			unsigned int id_tmp;
			int life_tmp;
			sf::Vector2f pos_tmp;
			sf::Time clock_tmp;
			int32_t pontuacao_tmp;
			string linha;
			while (getline(progresso, linha))
			{
				istringstream linestream(line);
				getline(linestream, texto, ",");
				id_tmp = stoul(texto);
				getline(linestream, texto, ",");

				dados.insert(id_tmp, make_tuple(life_tmp, pos_tmp, clock_tmp, pontuacao_tmp));
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

	void Salvamento::salvarJogo()
	{
		ofstream progresso("jogo_salvo.txt");
		progresso.clear();
		if (progresso.is_open()) {
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