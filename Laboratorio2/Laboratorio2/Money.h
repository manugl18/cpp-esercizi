#pragma once
#include <string>
#include <iostream>

using namespace std;

class Money {
private:
	int euros;
	int cents;
public:
	Money(int euros = 0, int cents = 0);

	//Getter
	int get_euros()const;
	int get_cents()const;

	//Setter
	void set_euros(int euros);
	void set_cents(int cents);

	//Operator
	
};

Money::Money(int euros, int cents) {
	this->euros = euros;
	this->cents = cents;
}

// GETTER
int Money::get_euros() const{
	return this->euros;
}

int Money::get_cents() const{
	return this->cents;
}

// SETTER
void Money::set_euros(int euros) {
	this->euros = euros;
}

void Money::set_cents(int cents) {
	this->cents = cents;
}

Money operator+(Money m1, Money m2) {
	int euros = m1.get_euros() + m2.get_euros();
	int cents = m1.get_cents() + m2.get_cents();

	if (cents > 100) {
		euros += cents / 100;
		cents %= 100;
	}
	return Money(euros, cents);

	
}
inline ostream& operator<<(ostream& os, const Money& m1) {
	os << m1.get_euros() << "," << m1.get_cents();
	return os;
}