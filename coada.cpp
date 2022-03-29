#include "coada.hpp"

coada::coada():front(NULL), rear(NULL) {} ;

coada::coada(meci* aux1, meci* aux2): front(aux1), rear(aux2) {} ;

coada::~coada() {
	meci* aux;
	while(front != rear)
	{
		aux = front;
		front = front->getNextMeci();
		delete aux;
	}
	aux=rear;
	delete aux;
}

coada::coada(const coada &q) {
	if(front!=NULL) {
		delete [] front;
		delete [] rear;
	}
	front=q.front;
	rear=q.rear;
}

coada& coada::operator=(const coada &q) {
	if(this!=&q) {

		if(front!=NULL) {
			delete [] front;
			delete [] rear;
		}
		front=q.front;
		rear=q.rear;
	}
	return *this;
}
 
void coada::inserare_coada(Team *nod) {     /// inserez un nod in coada

	Team *p,*q;
	meci* mec=new meci;
	p=nod;
	q=nod->getNext();
	mec->setTeam1(p);
	mec->setTeam2(q);
	if(rear==NULL)
		rear=mec;
	else{
		rear->setNextMeci(mec);
		rear=mec;
	}
	if(front==NULL)
		front=rear;
}

void coada::afisare_coada(ofstream &ofis)const {

	meci *p;
	p=front;

	while(p!=rear) {
		p->afisMeci(ofis);
		p=p->getNextMeci();
	}
	rear->afisMeci(ofis);
}

meci* coada::getFront()const {
	return front;
}

void coada::RemoveElement(){
	meci* aux;
	aux=front;
	front=front->getNextMeci();
}

int coada::isEmpty(){
	return front==NULL;
}

