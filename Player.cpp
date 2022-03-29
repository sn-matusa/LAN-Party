#include "Player.hpp"
///constructor fara parametrii
Player::Player() {
	firstName=string();
	secondName=string();
	points=0;
}
///constructor cu parametrii
Player::Player(string fm, string sm, int p){
	firstName=fm;
	secondName=sm;
	points=p;
}

void Player::setFirstName(string fn){
	firstName=fn;
}

void Player::setSecondName(string sn){
	secondName=sn;
}

void Player::setPoints(int pct){
	points=pct;
}

void Player::afisPlayer()const{
	cout<<firstName<<" "<<secondName<<" "<<points<<endl;	
}

Player& Player::operator=(const Player &play){
	firstName=play.firstName;
	secondName=play.secondName;
	points=play.points;
	return *this;
}

int Player::getPoints()const{
	return points;
}
