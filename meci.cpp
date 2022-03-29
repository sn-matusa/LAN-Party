#include "meci.hpp"

meci::meci(): tm1(NULL), tm2(NULL), next(NULL) {} ;

meci::meci(Team *aux1, Team* aux2): tm1(aux1), tm2(aux2) {} ;

meci::~meci() {
	delete tm1;
	delete tm2;
}

meci::meci(const meci &mec) {
	if(tm1!=NULL) {
		delete [] tm1;
		delete [] tm2;
	}
	tm1=mec.tm1;
	tm2=mec.tm2;
	next=NULL;
}

meci& meci::operator=(const meci &mec) {
	if(this!=&mec) {
		if(tm1!=NULL) {
			delete [] tm1;
			delete [] tm2;
		}
		tm1=mec.tm1;
		tm2=mec.tm2;
		next=NULL;
	}
	return *this;
}

void meci::setNextMeci(meci *aux) {
	next=aux;
}

meci* meci::getNextMeci()const {
	return next;
}

void meci::setTeam1(Team *t) {
	tm1=t;
}

void meci::setTeam2(Team *t) {
	tm2=t;
}

void meci::afisMeci(ofstream &ofis)const {

	ofis <<left<<setw(33)<<tm1->getTeamName()<<internal<<"-"<<right<<setw(33)<<tm2->getTeamName()<<endl;
}

Team* meci::getTeam1()const {
	return tm1;
}

Team* meci::getWinner()const {
	if(tm1->getPunctajEchipa()>tm2->getPunctajEchipa())
		return tm1;
	return tm2;
}

Team* meci::getLoser()const {
	if(tm1->getPunctajEchipa()>tm2->getPunctajEchipa())
		return tm2;
	return tm1;
}
