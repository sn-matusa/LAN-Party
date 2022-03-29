#include "Team.hpp"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class lista{
	private:
		Team* head;
		int size;		
	public:
		lista();
		lista(Team*, int);
		lista(const lista &);
		~lista();
		lista& operator=(const lista&);
		void AddTeam(const Team&);
		void RemoveTeam(int);
		Team* getHead();
		void afisare(ofstream &)const;
		int getSize()const;
		void stergere();
		void golire_lista();
		void AddTeam2(Team *);
};
