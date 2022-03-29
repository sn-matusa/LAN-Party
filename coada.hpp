#include "meci.hpp"

class coada{
	private:
		meci* front;
		meci* rear;
	public:
		coada();
		coada(meci*, meci*);
		~coada();
		coada(const coada &);
		coada& operator=(const coada &);
		void inserare_coada(Team*);
		void afisare_coada(ofstream &)const;
		meci* getFront()const;
		void RemoveElement();
		int isEmpty();
};
