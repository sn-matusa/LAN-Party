#include "Player.hpp"
#pragma once
class Team{

	private:
		int nr_players;
		string TeamName;
		Player *p;
		Team *next;
		double PunctajEchipa;
	public:
		Team();
		Team(int, string, Player*);
		Team(int, string, Player*,double);
		~Team();
		Team(const Team &);
		Team& operator=(const Team &);

		void setNext(Team*);
		void setNrJucatori(int);
		void setNumeEchipa(string);
		void setPlayer(string *, string *, int*, int);

		Team* getNext() const;
		int getNrPlayers()const;
		string getTeamName()const;
		Player* getPlayers()const;

		void afisare()const;
		void setTeam(int ,string, string*, string*, int*, Team*);

		void calcPunctajEchipa();
		double getPunctajEchipa()const;
		void setPunctajEchipa();
};
