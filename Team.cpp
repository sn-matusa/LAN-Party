#include "Team.hpp"
///constructor fara parametrii
Team::Team() {
	nr_players=0;
	TeamName=string();
	next=NULL;
	PunctajEchipa=0;
}
///constructor cu parametrii
Team::Team(int nr, string tm, Player *vec) {
	nr_players=nr;
	TeamName=tm;
	next=NULL;
	PunctajEchipa=0;
	p  = new Player[nr];
	for(int i=0; i<nr; i++) {
		p[i]=vec[i];
	}
}
Team::Team(int nr, string tm, Player *vec,double pe) {
	nr_players=nr;
	TeamName=tm;
	next=NULL;
	PunctajEchipa=pe;
	p  = new Player[nr];
	for(int i=0; i<nr; i++) {
		p[i]=vec[i];
	}
}
///destructor
Team::~Team() {
	delete [] p;
}
///constructor de copiere
Team::Team(const Team &tm) {
	TeamName=tm.TeamName;
	nr_players=tm.nr_players;
	PunctajEchipa=tm.PunctajEchipa;
	if(p!=NULL)
		delete [] p;
	p=new Player[nr_players];
	for(int i=0; i<nr_players; i++)
		p[i]=tm.p[i];
}
///operator =
Team& Team::operator=(const Team &tm) {
	if(this!=&tm) {
		nr_players=tm.nr_players;
		TeamName=tm.TeamName;
		PunctajEchipa=tm.PunctajEchipa;
		if(p!=NULL)      /////
			delete [] p;          /////
		p=new Player[nr_players];
		for(int i=0; i<nr_players; i++) {
			p[i]=tm.p[i];
		}
	}
	return *this;
}

void Team::setNext(Team *urm) {
	next=urm;
}

void Team::setNrJucatori(int nr) {
	nr_players=nr;
}

void Team::setNumeEchipa(string tm) {
	TeamName=tm;
}

void Team::setPlayer(string fn[], string sn[], int pct[], int nr) {
	p=new Player[nr];
	for(int i=0; i<nr; i++) {
		p[i].setFirstName(fn[i]);
		p[i].setSecondName(sn[i]);
		p[i].setPoints(pct[i]);
	}
}

Team* Team::getNext()const {
	return next;
}

int Team::getNrPlayers()const {
	return nr_players;
}

string Team::getTeamName()const {
	return TeamName;
}

Player* Team::getPlayers()const {
	return p;
}

void Team::afisare()const {
	if(this!=NULL) {
		cout<<nr_players<<" "<<TeamName<<endl;
		for(int i=0; i<nr_players; i++)
			p[i].afisPlayer();
		cout<<endl;
	}

}
void Team::setTeam(int nr, string tm, string fn[], string sn[], int pct[], Team *urm) {
	next=urm;
	nr_players=nr;
	TeamName=tm;
	p=new Player[nr];
	for(int i=0; i<nr; i++) {
		p[i].setFirstName(fn[i]);
		p[i].setSecondName(sn[i]);
		p[i].setPoints(pct[i]);
	}
}

void Team::calcPunctajEchipa() {
	int s=0;
	for(int i=0; i<nr_players; i++) {
		s=s+p[i].getPoints();
	}
	PunctajEchipa=(double)s/nr_players;
}

double Team::getPunctajEchipa()const {
	return PunctajEchipa;
}

void Team::setPunctajEchipa() {
	PunctajEchipa=PunctajEchipa+1;
}
