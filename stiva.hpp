#include "Team.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class stiva{
	private:
		Team* top;
		int size_stiva;
	public:
		stiva();
		stiva(Team*, int);
		~stiva();
		stiva(const stiva &);
		stiva& operator=(const stiva &);
		void afisare_stiva(ofstream &)const;
		void AddElement(Team*);
		void golire();
		int getSizeStiva()const;		
		void RemoveElement();
		Team* getTop()const;
		int isEmpty();
};
