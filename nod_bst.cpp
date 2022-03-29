#include "nod_bst.hpp"

nod_bst::nod_bst():nod(NULL), right(NULL), left(NULL) {} ;
nod_bst::nod_bst(Team *aux): nod(aux) {} ;

nod_bst& nod_bst::operator=(const nod_bst &nb)
{
    if(this!=&nb)
    {
        if(nod!=NULL)
            delete nod;
        nod=nb.nod;
        right=nb.right;
        left=nb.left;
    }
    return *this;
}
nod_bst::~nod_bst()
{
    delete nod;
}


nod_bst* nod_bst::insert(nod_bst* n, const Team &tm)
{	
	///daca arborele sau subargorele este gol, creez un nod nou
    if(n==NULL)
    {
        n=new nod_bst;
        n->setTeam(tm);
        n->left=NULL;
        n->right=NULL;
    }
	///altfel cobor in arbore
    else  if(n->getTeam()->getPunctajEchipa()> tm.getPunctajEchipa())
        n->right=insert(n->right,tm);
    else if(n->getTeam()->getPunctajEchipa()< tm.getPunctajEchipa())
        n->left=insert(n->left,tm);

    else if(n->getTeam()->getTeamName()>tm.getTeamName())
        n->right=insert(n->right,tm);
    else
        n->left=insert(n->left,tm);

    return n;
}


void nod_bst::setTeam(const Team &tm)
{
    this->nod=new Team(tm.getNrPlayers(),tm.getTeamName(),tm.getPlayers(),tm.getPunctajEchipa());
}

Team* nod_bst::getTeam()const
{
    return nod;
}

void nod_bst::inorder(nod_bst *n, ofstream &ofis)
{
    if(!n)
        return;
    inorder(n->left,ofis);
    ofis.width(34);
    ofis<<std::left<<n->getTeam()->getTeamName();
    ofis<<std::right<<"-  "<<fixed<<setprecision(2)<<n->getTeam()->getPunctajEchipa()<<endl;
    inorder(n->right,ofis);
}
