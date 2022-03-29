#include "Team.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class nod_bst{
	private:
		Team* nod;
		nod_bst* left;
		nod_bst* right;
	public:
		nod_bst();
		nod_bst(Team*);
		~nod_bst();
        nod_bst& operator=(const nod_bst &);
		nod_bst* insert(nod_bst*, const Team &);
		void setTeam(const Team &);
		Team* getTeam()const;
		void inorder(nod_bst*,ofstream &);
};
