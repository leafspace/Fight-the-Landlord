#pragma once
#include <iostream>
#include <string>
using namespace std;
const class Poker
{
private:
	string Suit;
	string Kind;
	int Score;
public:
	mutable string people = "0";
	Poker(string Sui = "0", string Kin = "0", int Sco = 0) :Suit(Sui), Kind(Kin), Score(Sco) {}
	~Poker() {  }
	bool Setdata(string, string, int);
	int Getscore(void);
	void Show(void);
};
class Farmer
{
protected:
	Poker P[17];
	string Name;
	int Score;
public:
	Farmer(string);
	~Farmer(void) {}
	void Show(void);
};
class Landlord:public Farmer
{
protected:
	Poker PAdd[3];
public:
	Landlord(string nam);
	~Landlord(void) {}
	void Show(void);
	void SortPoker(void);
};

void InitPoker(Farmer*, Farmer*, Landlord*);
string *GrabLandlord1(string *, string *, string *);
string *GrabLandlord2(string *, string *, string *, int[]);
void GameIN();

extern const string SUIT[];
extern const string KIND[];
extern Poker ALL[];
extern Farmer *farmer1, *farmer2;
extern Landlord *landlord;