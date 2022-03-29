#include "stiva.hpp"

stiva::stiva(): top(NULL), size_stiva(0) {} ;

stiva::stiva(Team *aux, int s): top(aux), size_stiva(s) {} ;

stiva::~stiva() {
	Team* aux;
	while(top != NULL)
	{
		aux = top;
		top = top->getNext();
		delete aux;
	}
}

stiva::stiva(const stiva &s) {
	if(top!=NULL)
		delete [] top;
	top=s.top;
	size_stiva=s.size_stiva;
}

stiva& stiva::operator=(const stiva &s) {
	if(this!=&s) {
		size_stiva=s.size_stiva;
		if(top!=NULL)
			delete [] top;
		top=s.top;
	}
	return *this;
}

void stiva::AddElement(Team *p) {
	Team *q=new Team;
	q=p;
	q->setNext(top);
	top=q;
	size_stiva++;
}

void stiva::golire(){
	Team *q;
	while(top!=NULL){
		q=top;
		top=top->getNext();
		delete q;
	}
}

void stiva::afisare_stiva(ofstream &ofis)const{
	Team *p;
	p=top;
	while(p!=NULL){
		ofis.width(34);
		ofis<<left<<p->getTeamName();
		ofis<<right<<"-  "<<fixed<<setprecision(2)<<p->getPunctajEchipa()<<endl;
		p=p->getNext();
	}
}

int stiva::getSizeStiva()const{
	return size_stiva;
}

Team* stiva::getTop()const{
	return top;
}

void stiva::RemoveElement(){
	Team *q;
	q=top;
	top=top->getNext();
	size_stiva--;
}

int stiva::isEmpty() {
	return top==NULL;
}
