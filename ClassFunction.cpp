#include"HEAD.h"
#include <time.h>
bool Poker::Setdata(string Sui = "0", string Kin = "0", int Sco = 0)
{
	if ((&Suit) == NULL || (&Kind) == NULL || (&Score) == NULL)
		return false;
	Suit = Sui;
	Kind = Kin;
	Score = Sco;
	return true;
}
void Poker::Show(void)
{
	cout << Kind << " ";
}
int Poker::Getscore(void)
{
	return Score;
}
Farmer::Farmer(string Nam)
{
	Name = Nam;
	int num[17] = { 0 };
	srand((unsigned)time(NULL));
	for (int i = 0;i < 17;i++) {
		num[i] = rand() % 54;
		if (ALL[num[i]].people != "0")
			i--;
		else
			ALL[num[i]].people = Name;
	}
	for (int i = 0;i < 17;i++) {
		for (int j = 0;j < 16 - i;j++) {
			if (num[j] > num[j + 1]) {
				int t;
				t = num[j];
				num[j] = num[j + 1];
				num[j + 1] = t;
			}
		}
	}
	//将产生的牌位置直接拉入类成员
	for (int i = 0;i < 17;i++) {
		P[i] = ALL[num[i]];
	}
}
Landlord::Landlord(string Nam):Farmer(Nam)
{
	for (int i = 0, j = 0;i < 3;i++) {
		while (ALL[j++].people != "0") {}
		j--;
		ALL[j].people = Name;
		PAdd[i] = ALL[j];
		
	}
}
void Farmer::Show(void)
{
	cout << Name << ": " << endl;
	for (int i = 0;i < 17;i++) {
		P[i].Show();
	}
}
void Landlord::Show(void)
{
	Farmer::Show();
	for (int i = 0;i < 3;i++) {
		PAdd[i].Show();
	}
}
void Landlord::SortPoker(void)
{
	Poker T[20];
	for (int i = 0;i < 17;i++) {
		T[i] = P[i];
	}
	for (int i = 0;i < 3;i++) {
		T[17 + i] = PAdd[i];
	}
	for (int i = 0;i < 20;i++) {
		for (int j = 0;j < 19 - i;j++) {
			if (T[j].Getscore() < T[j + 1].Getscore()) {
				Poker t;
				t = T[j];
				T[j] = T[j + 1];
				T[j + 1] = t;
			}
		}
	}
	for (int i = 0;i < 17;i++) {
		P[i] = T[i];
	}
	for (int i = 0;i < 3;i++) {
		PAdd[i] = T[17 + i];
	}
}