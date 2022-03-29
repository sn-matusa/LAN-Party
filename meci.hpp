#include "Team.hpp"
#include <fstream>
#include <iomanip>


class meci{
	private:
		Team* tm1;
		Team* tm2;
		meci *next;
	public:
		meci();
		meci(Team*, Team*);
		~meci();
		meci(const meci &);
		meci& operator=(const meci &);
		void setNextMeci(meci*);
		meci* getNextMeci()const;
		void setTeam1(Team*);
		void setTeam2(Team*);
		void afisMeci(ofstream &)const;
		Team* getTeam1()const;
		Team* getWinner()const;
		Team* getLoser()const;
};
