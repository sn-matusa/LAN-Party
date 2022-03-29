#include "lista.hpp"
#include "coada.hpp"
#include "stiva.hpp"
#include "nod_bst.hpp"
#include "nod_avl.hpp"

void creare_lista(ifstream &d, lista* &list, int nr_teams) {

	int nr_juc,*pct;
	string buf;
	string *fn, *sn;

	for(int i=0; i<nr_teams; i++) {
		d>>nr_juc;
		getline(d,buf);
		buf.erase(0,1);

		if(buf.back()==' ')
			buf.pop_back();

		fn=new string[nr_juc];
		sn=new string[nr_juc];
		pct=new int[nr_juc];

		Player* pl= new Player[nr_juc];

		for(int j=0; j<nr_juc; j++) {
			d>>fn[j]>>sn[j]>>pct[j];
			pl[j] = Player(fn[j],sn[j],pct[j]);
		}

		Team tm(nr_juc,buf,pl);
		list->AddTeam(tm);
	}
}

void calcul_punctaj_echipa(lista* &list) {

	Team *p=list->getHead();
	while(p!=NULL) {
		p->calcPunctajEchipa();
		p=p->getNext();
	}
}

void task3(lista* &list, ofstream &r, nod_bst* &root, nod_avl* &root2) {

	Team *h,*p;
	h=list->getHead();

	coada *queque=new coada;
	stiva* stiva_invingatori = new stiva;
	stiva* stiva_invinsi = new stiva;

	while(h!=NULL) {		///introduc lista initiala in coada
		queque->inserare_coada(h);
		h=h->getNext()->getNext();
	}
	r<<endl<<"--- ROUND NO:1"<<endl;
	queque->afisare_coada(r); 	///afisez coada initiala

	while(!queque->isEmpty()) { 	/// golesc coada si adaug elementele in stive

		h=queque->getFront()->getWinner();
		p=queque->getFront()->getLoser();

		queque->RemoveElement();

		h->setPunctajEchipa();


		stiva_invingatori->AddElement(h);
		stiva_invinsi->AddElement(p);
	}

	r<<endl<<"WINNERS OF ROUND NO:1"<<endl;

	stiva_invingatori->afisare_stiva(r);

	int i=2;
	while(stiva_invingatori->getSizeStiva()>1) {

		if(stiva_invingatori->getSizeStiva()==8) {

			lista* list2=new lista;

			while(!stiva_invingatori->isEmpty()) {

				p=stiva_invingatori->getTop();
				stiva_invingatori->RemoveElement();
				list2->AddTeam2(p);                                  //////////
		///
				Team new_Team(p->getNrPlayers(),p->getTeamName(),p->getPlayers(),p->getPunctajEchipa());

                root=root->insert(root,new_Team);
                root2=root2->insert(root2,new_Team);
        ///
			}

			h=list2->getHead();
			while(h!=NULL) {
				queque->inserare_coada(h);
				h=h->getNext()->getNext();
			}
			r<<endl<<"--- ROUND NO:"<<i<<endl;
			queque->afisare_coada(r);

			while(!queque->isEmpty()) {
				h=queque->getFront()->getWinner();
				p=queque->getFront()->getLoser();
				queque->RemoveElement();
				h->setPunctajEchipa();
				stiva_invingatori->AddElement(h);
				stiva_invinsi->AddElement(p);
			}
			r<<endl<<"WINNERS OF ROUND NO:"<<i<<endl;
			stiva_invingatori->afisare_stiva(r);

		} else {

			while(!stiva_invingatori->isEmpty()) {
				h=stiva_invingatori->getTop();
				stiva_invingatori->RemoveElement();
				stiva_invingatori->RemoveElement();
				queque->inserare_coada(h);
			}
			r<<endl<<"--- ROUND NO:"<<i<<endl;
			queque->afisare_coada(r);

			while(!queque->isEmpty()) {
				h=queque->getFront()->getWinner();
				p=queque->getFront()->getLoser();
				queque->RemoveElement();
				h->setPunctajEchipa();
				stiva_invingatori->AddElement(h);
				stiva_invinsi->AddElement(p);
			}
			r<<endl<<"WINNERS OF ROUND NO:"<<i<<endl;
			stiva_invingatori->afisare_stiva(r);
		}
		i++;
	}
	stiva_invingatori->golire();
	stiva_invinsi->golire();
}

int main(int argc, char *argv[]) {

	ifstream c(argv[1]);
	if(!c) cout<<"eroare1";
	ifstream d(argv[2]);
	if (!d) cout<<"eroare2";
	ofstream r(argv[3]);
	if(!r) cout<<"eroare3";

	lista *list=new lista;
	nod_bst *root=NULL;
	nod_avl *root2=NULL;
	int nr_teams;
	d>>nr_teams;

	int cerinta[5];
	for(int i = 0; i < 5; i++)
		c>>cerinta[i];
	if(cerinta[1]==1)
		cerinta[0]=0;

	for(int i = 0; i < 5; i++) {
		switch(i) {
			case 0 : {
				if(cerinta[0] == 1) {
					creare_lista(d,list,nr_teams);
					list->afisare(r);
				}
				break;
			}
			case 1 : {
				if(cerinta[1] == 1) {
					creare_lista(d,list,nr_teams);
					calcul_punctaj_echipa(list);
					list->stergere();
					list->afisare(r);
				}
				break;
			}
			case 2 : {
				if(cerinta[2] == 1) {
					task3(list,r,root,root2);
				}
				break;
			}
			case 3: {
				if(cerinta[3] == 1){
                    r<<endl<<"TOP 8 TEAMS:"<<endl;
                   root->inorder(root,r);

				}
				break;
			}
			case 4:{
				if(cerinta[4] == 1){
					r<<endl<<"THE LEVEL 2 TEAMS ARE: "<<endl;
					root2->print_avl(root2,2,r);
				}
				break;
			}
			default: {
				cout<< "Error!"<<endl;
				break;
			}
		}
	}
	delete list;

	c.close();
	d.close();
	r.close();

	return 0;
}
