#include "pch.h"
#include "Gerenciador/Salvamento.h"

using namespace std;

namespace Gerenciador{
	Salvamento* Salvamento::pSalvamento(nullptr);

	Salvamento::Salvamento() :
		rodada(0)
	{
	}

	Salvamento::~Salvamento()
	{
		dados.clear();
		pSalvamento = nullptr;
	}

	void Salvamento::encontrarID(ListaEntidades* list_ent, unsigned int id)
	{
		int j = 0, k =0;
		auto range = dados.equal_range(id);
		for (auto i = range.first; i != range.second; ++i)
		{
			for (j = k; j < list_ent->getSize() && list_ent->getEntity(j)->getId() != id; j++)
			{
				k++;
			}
			if (list_ent->getEntity(j)->getId() == id) {
				restaurarProgresso(list_ent->getEntity(j), i->second);
				dados.erase(i);
				k++;
			}
			else
				k = 0;
		}
	}

	void Salvamento::encontrarJogador(ListaEntidades* list_ent, unsigned int id)
	{
		int j;
		tuple<int, string, int, unsigned int> dados_jogador;
		for(auto p:jogadores)
		{
			if (get<2>(p) > rodada && get<3>(p) == id)
			{
				rodada = get<2>(p);
				dados_jogador = p;
				break;
			}
		}
		for (j = 0; j < list_ent->getSize(); j++){}
			if (list_ent->getEntity(j)->getId() == id) {
				restaurarJogador(dynamic_cast<Jogador*>(list_ent->getEntity(j)), dados_jogador);
			}
	}

	void Salvamento::carregarPersonagens(ListaEntidades* list_ent)
	{
		for_each(id_list.begin(), id_list.end(), [&](auto& id){encontrarID(list_ent, id);});
		for_each(player_id.begin(), player_id.end(), [&](auto& player) {encontrarJogador(list_ent, player);});
	}

	void Salvamento::carregarJogoSalvo(ListaEntidades* list_ent)
	{
		progresso.open("jogo_salvo.csv", ios::in);
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
			string erro = "Progresso do jogo indisponível.";
			try { throw runtime_error(erro); }
			catch (...) {
				cerr << erro << endl;
			}
		}
		carregarRankingSalvo();
		carregarPersonagens(list_ent);
	}

	void Salvamento::carregarRankingSalvo()
	{
		ifstream ranking("jogo_salvo.csv", ios::in);
		if (ranking.is_open()) {
			int pontuacao_tmp, rodada_tmp, id_tmp;
			string apelido_tmp, buffer_linha, buffer_texto;
			while (getline(ranking, buffer_linha))
			{
				istringstream linestream(buffer_linha);
				getline(linestream, buffer_texto, ',');
				pontuacao_tmp = stoi(buffer_texto);
				getline(linestream, buffer_texto, ',');
				apelido_tmp = buffer_texto;
				getline(linestream, buffer_texto, ',');
				rodada_tmp = stoi(buffer_texto);
				getline(linestream, buffer_texto);
				id_tmp = stoul(buffer_texto);
				jogadores.insert(make_tuple(pontuacao_tmp, apelido_tmp, rodada_tmp, id_tmp));
				ranking.close();
			}
		}
		else {
			string erro = "Ranking do jogo indisponível.";
			try { throw runtime_error(erro); }
			catch (...) {
				cerr << erro << endl;
			}
		}
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
		ranking.clear();
		ofstream ranking("ranking_salvo.csv", ios::trunc);
		if (ranking.is_open()) {
			ranking.close();
		}
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
		for (int k = 0; k < list_ent->getSize(); k++)
		{
			if (binary_search(player_id.begin(),player_id.end(),list_ent->getEntity(k)->getId()))
			{
				jogadores.insert(make_tuple(list_ent->getEntity(k)->getPontuacao(), list_ent->getEntity(k)->getApelido(), rodada, list_ent->getEntity(k)->getId()));
			}
		}
		carregarRankingSalvo();
		for_each(jogadores.begin(), jogadores.end(), [&](auto& um_jogador) {
			if(get<2>(um_jogador)>rodada)
				rodada=get<2>(um_jogador)>+1;
		});
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
		ofstream progresso("jogo_salvo.csv", ios::trunc);
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
		ofstream ranking("ranking_salvo.csv", ios::app);
		if (ranking.is_open()) {
			for (auto p : jogadores) {
				ranking << get<0>(p) << "," << get<1>(p) << "," << get<2>(p) << endl;
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

	void Salvamento::restaurarJogador(Jogador* player, tuple<int, string, int, unsigned int> dados_jogador)
	{
		player->setPontuacao(get<0>(dados_jogador));
		player->setApelido(get<1>(dados_jogador));
	}

	Salvamento* Salvamento::getSalvamento()
	{
		if(!pSalvamento)
			pSalvamento = new Salvamento();
		return pSalvamento;
	}
}