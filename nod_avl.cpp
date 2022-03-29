#include "nod_avl.hpp"

nod_avl::nod_avl():height(0), nod(NULL), right(NULL), left(NULL) {};

nod_avl* nod_avl::insert(nod_avl* n, const Team &tm) {
///inserez nod in ordine descrescatoare
	if(n==NULL) {
		n=new nod_avl;
		n->setTeam(tm);
		n->left=NULL;
		n->right=NULL;
		n->height=0;
		return n;
	}

	else  if(n->getTeam()->getPunctajEchipa()> tm.getPunctajEchipa())
		n->right=insert(n->right,tm);
	else if(n->getTeam()->getPunctajEchipa()< tm.getPunctajEchipa())
		n->left=insert(n->left,tm);

	else if(n->getTeam()->getTeamName()>tm.getTeamName())
		n->right=insert(n->right,tm);
	else if(n->getTeam()->getTeamName()<tm.getTeamName())
		n->left=insert(n->left,tm);
	else
		return n;
	///resetez intalnitea nodurilor
	n->height=1+max(n->nodeHeight(n->left),n->nodeHeight(n->right));
	///factor de echilibru stamosi
	int k=(nodeHeight(n->left)-nodeHeight(n->right));

	///echilibrare
	if (k > 1 && tm.getPunctajEchipa() > n->left->getTeam()->getPunctajEchipa())
		return n->RightRotation(n);

	if (k < -1 && tm.getPunctajEchipa() < n->right->getTeam()->getPunctajEchipa())
		return n->LeftRotation(n);

	if (k > 1 && tm.getTeamName() > n->left->getTeam()->getTeamName() && tm.getPunctajEchipa()==n->left->getTeam()->getPunctajEchipa())
		return n->RightRotation(n);

	if (k < -1 && tm.getTeamName() < n->right->getTeam()->getTeamName() && tm.getPunctajEchipa()==n->right->getTeam()->getPunctajEchipa())
		return n->LeftRotation(n);



	if (k > 1 && tm.getPunctajEchipa() > n->left->getTeam()->getPunctajEchipa())
		return n->RLRotation(n);

	if (k < -1 && tm.getPunctajEchipa() < n->right->getTeam()->getPunctajEchipa())
		return n->LRRotation(n);

	if (k > 1 && tm.getTeamName() > n->left->getTeam()->getTeamName() && tm.getPunctajEchipa()==n->left->getTeam()->getPunctajEchipa())
		return n->RLRotation(n);

	if (k < -1 && tm.getTeamName() < n->right->getTeam()->getTeamName() && tm.getPunctajEchipa()==n->right->getTeam()->getPunctajEchipa())
		return n->LRRotation(n);

	return n;
}

int nod_avl::nodeHeight(nod_avl *n) {
	if(n==NULL)
		return -1;
	return n->height;
}

nod_avl* nod_avl::RightRotation(nod_avl* z) {
	nod_avl *y=z->left;
	nod_avl *x = y->right;
	y->right = z;
	z->left = x;
	z->height = max(nodeHeight(z->left), nodeHeight(z->right))+1;
	y->height = max(nodeHeight(y->left), nodeHeight(y->right))+1;

	return y;
}

nod_avl* nod_avl::LeftRotation(nod_avl *z) {
	nod_avl *y = z->right;
	nod_avl *x = y->left;
	y->left = z;
	z->right = x;
	z->height = max(nodeHeight(z->left), nodeHeight(z->right))+1;
	y->height = max(nodeHeight(y->left), nodeHeight(y->right))+1;

	return y;
}

nod_avl* nod_avl::LRRotation(nod_avl *Z) {
	Z->left=LeftRotation(Z->left);
	return RightRotation(Z);
}

nod_avl* nod_avl::RLRotation(nod_avl *Z) {
	Z->right=RightRotation(Z->right);
	return LeftRotation(Z);
}

void nod_avl::print_avl(nod_avl *n, int level,ofstream &ofis) {
	if(n==NULL)
		return;
	if(level==1)
		ofis<<n->getTeam()->getTeamName()<<" "<<n->height<<endl;
	else if(level>1) {
		print_avl(n->left,level-1,ofis);
		print_avl(n->right,level-1,ofis);
	}
}

void nod_avl::setTeam(const Team &tm) {
	this->nod=new Team(tm.getNrPlayers(),tm.getTeamName(),tm.getPlayers(),tm.getPunctajEchipa());
}

Team* nod_avl::getTeam()const {
	return nod;
}
