#include "lista.hpp"

lista::lista():head(NULL),size(0) {};   ///constructor fara parametrii

lista::lista(Team *aux, int s):head(aux), size(s) {} ;    ///constructor cu parametrii

lista::~lista() {
	Team* node_to_delete;
	while(head != NULL)
	{
		node_to_delete = head;
		head = head->getNext();
		delete node_to_delete;
	}
}

lista::lista(const lista &l) {
	if(head!=NULL)
		delete [] head;
	head=l.head;
	size=l.size;
}

lista& lista::operator=(const lista &l) {
	if(this!=&l) {
		size=l.size;
		if(head!=NULL)
			delete [] head;
		head=l.head;
	}
	return *this;
}

void lista::AddTeam(const Team &tm) {

	Team *aux;
	aux = head;

	Team* new_Team = new Team(tm.getNrPlayers(),tm.getTeamName(),tm.getPlayers());

	new_Team->setNext(aux);
	head = new_Team;
	size++;
}

void lista::RemoveTeam(int n) {
	Team *aux, *curr;
	curr=head;
	aux=head;
	int i=1;
	if(n==1) {
		head=curr->getNext();
		delete curr;
		size--;
		return;
	}
	while(curr!=NULL) {
		if(i!=n) {
			aux=curr;
			curr=curr->getNext();
			i++;
		} else {
			aux->setNext(curr->getNext());
			delete curr;
			size--;
			return;
		}
	}
}

Team* lista::getHead() {
	return head;
}

void lista::afisare(ofstream &ofis)const {
	Team *p;
	p=head;
	while(p!=NULL) {
		ofis << p->getTeamName() << endl;
		p=p->getNext();
	}
}

int lista::getSize()const {
	return size;
}

void lista::stergere() {
	Team* p;
	int k=1, nod_de_sters, i=1;
	double min=200;
	while(k<=size) {
		k=k*2;
	}
	k=k/2;
	p=head;
	while(p!=NULL) {
		p=p->getNext();
	}
	while(size!=k) {
		i=1;
		min=1000;
		p=head;
		while(p!=NULL) {
			if(p->getPunctajEchipa()<min) {
				min=p->getPunctajEchipa();
				nod_de_sters=i;
			}
			i++;
			p=p->getNext();
		}
		RemoveTeam(nod_de_sters);
	}
}

void lista::golire_lista(){
	Team *aux;
	while(head!=NULL){
		aux=head->getNext();
		delete head;
		head=aux;
	}
	head=NULL;
	size=0;
}

void lista::AddTeam2(Team *tm){

	if(head==NULL)
		{head=tm;
		head->setNext(NULL);}
	else{
		Team* aux,*auxx;
		aux=head;
		while(aux->getNext()!=NULL)
			aux=aux->getNext();
		auxx=tm;
		aux->setNext(auxx);
		auxx->setNext(NULL);
	}
}
