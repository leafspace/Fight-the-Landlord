#include "HEAD.h"
const string SUIT[4] = { "Diamond","Club","Heart","Spades" };
const string KIND[13] = { "2","A","K","Q","J","10","9","8","7","6","5","4","3" };
Poker ALL[54] = {
	Poker("NONE","BKing",18),
	Poker("NONE","LKing",16)
};
Farmer *farmer1 = NULL, *farmer2 = NULL;
Landlord *landlord = NULL;
int main()
{
	InitPoker(farmer1,farmer2,landlord);
	GameIN();
	return 0;
}