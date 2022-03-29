#include <string>
#include <iostream>

using namespace std;

class Player {
	private:
		string firstName;
		string secondName;
		int points;
	public:
		Player();
		Player(string, string, int);
    	void setFirstName(string);
    	void setSecondName(string);
    	void setPoints(int);
    	void afisPlayer()const;
    	Player& operator=(const Player&);
    	int getPoints()const;
};
