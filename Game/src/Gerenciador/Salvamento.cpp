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
		dados.clear();
		pSalvamento = nullptr;
	}

	bool compareSecond(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
		return lhs.second < rhs.second;
	}

	void Salvamento::carregarID(ListaEntidades* list_ent, unsigned int id)
	{
		int j;
		auto range = dados.equal_range(id);
		for (auto i = range.first; i != range.second; ++i)
		{
			for (j = 0; j < list_ent->getSize() && list_ent->getEntity(j)->getId() != id; j++)
			{
				j++;
			}
			if (j < list_ent->getSize() - 1) {
				restaurarProgresso(list_ent->getEntity(j), i->second);
				dados.erase(i);
				j++;
			}
			else
				j = 0;
		}
	}

	void Salvamento::carregarPersonagens(ListaEntidades* list_ent)
	{
		for_each(id_list.begin(), id_list.end(), [&](auto& id){carregarID(list_ent, id);});
	}

	void Salvamento::carregarJogoSalvo(ListaEntidades* list_ent)
	{
		progresso.open("jogo_salvo.csv", ios::trunc);
		if (progresso.is_open()) {
			unsigned int id_tmp;
			int life_tmp;
			sf::Vector2f pos_tmp;
			sf::Time clock_tmp;
			string buffer_linha, buffer_texto;
			while (getline(progresso, buffer_linha))
			{                                                                                    
				istringstream linestream(buffer_linha);
				getline(linestream, buffer_texto, ',');
				id_tmp = stoul(buffer_texto);
				getline(linestream, buffer_texto, ',');
				life_tmp = stoi(buffer_texto);
				getline(linestream, buffer_texto, ',');
				pos_tmp.x = stof(buffer_texto);
				getline(linestream, buffer_texto, ',');
				pos_tmp.y = stof(buffer_texto);
				getline(linestream, buffer_texto);
				clock_tmp = sf::milliseconds(stoi(buffer_texto));
				dados.emplace(id_tmp, make_tuple(life_tmp, pos_tmp, clock_tmp));
				progresso.close();
			}
		}
		else {
			string erro = "Não foi possível carregar o progresso do jogo.";
			try { throw runtime_error(erro); }
			catch (...) {
				cerr << erro << endl;
				exit(1);
			}
		}
		carregarPersonagens(list_ent);
	}

	void Salvamento::limparJogoSalvo()
	{
		dados.clear();
		progresso.open("jogo_salvo.csv", ios::trunc);
		if (progresso.is_open()) {
			progresso.close();
		}
		if (!remove("jogo_salvo.txt"))
		{
			string erro = "Não foi possível excluir o progresso do jogo.";
			try { throw runtime_error(erro); }
			catch (...) {
				cerr << erro << endl;
				exit(1);
			}
		}
	}

	void Salvamento::limparRankingSalvo()
	{
		ofstream progresso("ranking_salvo.csv");
		progresso.clear();
		progresso.close();
		ranking.clear();
		if (!remove("ranking_salvo.csv"))
		{
			string erro = "Não foi possível excluir o ranking.";
			try { throw runtime_error(erro); }
			catch (...) {
				cerr << erro << endl;
				exit(1);
			}
		}
	}

	void Salvamento::prepararSalvarRanking(ListaEntidades* list_ent)
	{
		//pair<string, int> tmp;
		//for (int k = 0; k < list_ent->getSize(); k++)
		//{
		//	if (binary_search(jogadores.begin(),jogadores.end(),list_ent->getEntity(k)->getId()))
		//	{
		//		jogadores.push_back(make_pair(list_ent->getEntity(k)->getApelido(), list_ent->getEntity(k)->getPontuacao()));
		//	}
		//}
	}

	void Salvamento::prepararSalvarJogo(ListaEntidades* list_ent)
	{
		for (int k = 0; k < list_ent->getSize(); k++)
		{
			if (binary_search(id_list.begin(), id_list.end(), list_ent->getEntity(k)->getId()))
			{
				dados.emplace(list_ent->getEntity(k)->getId(), make_tuple(list_ent->getEntity(k)->getLife(), list_ent->getEntity(k)->getPos(), list_ent->getEntity(k)->getClock()));
			}
		}
	}

	void Salvamento::salvarJogo(ListaEntidades* list_ent)
	{
		prepararSalvarJogo(list_ent);
		progresso.open("jogo_salvo.txt", ios::trunc);
		progresso.clear();
		if (progresso.is_open()) {
			for (auto i : dados) {
				progresso << i.first << "," << get<0>(i.second) << "," << get<1>(i.second).x << "," << get<1>(i.second).y << ","
					      << get<2>(i.second).asMilliseconds() << endl;
			}
			progresso.close();
			dados.clear();
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

	void Salvamento::salvarRanking(ListaEntidades* list_ent)
	{
		prepararSalvarRanking(list_ent);
		ranking.open("ranking_salvo.txt", ios::app);
		if (ranking.is_open()) {
			for (auto p : jogadores) {
				ranking << p.first << "," << p.second << endl;
			}
			ranking.close();
			jogadores.clear();
		}
		else {
			string erro = "Não foi possível salvar o ranking do jogo.";
			try { throw runtime_error(erro); }
			catch (...) {
				cerr << erro << endl;
				exit(1);
			}
		}
	}

	void Salvamento::restaurarProgresso(Entidade* ent, tuple<int, sf::Vector2f, sf::Time> dados_um)
	{
		ent->applyDamage(ent->getLife() - get<0>(dados_um));
		ent->setEntPos(get<1>(dados_um));
		ent->setClockZero(get<2>(dados_um));
	}

	Salvamento* Salvamento::getSalvamento()
	{
		if(!pSalvamento)
			pSalvamento = new Salvamento();
		return pSalvamento;
	}
}