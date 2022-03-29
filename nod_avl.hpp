#include "Team.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class nod_avl{
	private:
		int height;
		Team *nod;
		nod_avl* right;
		nod_avl* left;
	public:
		nod_avl();
		nod_avl* insert(nod_avl*, const Team &);
		int nodeHeight(nod_avl*);
		nod_avl* RightRotation(nod_avl*);
		nod_avl* LeftRotation(nod_avl*);
		nod_avl* LRRotation(nod_avl*);
		nod_avl* RLRotation(nod_avl*);
		void print_avl(nod_avl* ,int, ofstream &);
		void setTeam(const Team &);
		Team* getTeam()const;
};
