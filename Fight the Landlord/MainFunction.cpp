#include "HEAD.h"
void InitPoker(Farmer *farmer1,Farmer *farmer2,Landlord *landlord)
{
	for (int i = 0, k = 2, score = 15;i < 13;i++, score--) {
		for (int j = 0;j < 4;j++, k++) {
			if (ALL[k].Setdata(SUIT[j], KIND[i], score) == false) {
				cout << "Init error!" << endl;
				exit(-1);
			}
		}
	}
	string name1, name2, name3;
	GrabLandlord1(&name1, &name2, &name3);
	farmer1 = new Farmer(name1);
	farmer2 = new Farmer(name2);
	landlord = new Landlord(name3);

	landlord->SortPoker();
	
	(*farmer1).Show();
	cout << endl;
	(*farmer2).Show();
	cout << endl;
	(*landlord).Show();
	cout << endl;
	cout << "END" << endl;
	if (farmer1 == NULL || farmer2 == NULL || landlord == NULL) {
		cout << "Memory set error!" << endl;
	}
	cout << "Game start !" << endl;
}
string *GrabLandlord1(string *name1,string *name2,string *name3)
{
	int f[3] = { 0 };
	char c;
	cout << "Please enter the 3 people's name : " << endl;
	cin >> *name1>>*name2>>*name3;
	cout << "Who want going to the landlord ? " << endl;

	cout << *name1 << " Do you want ? ";
	fflush(stdin);
	c = getchar();
	if (c == 'Y' || c == 'y' || c == 1)
		f[0] = 1;
	cout << *name2 << " Do you want ? ";
	fflush(stdin);
	c = getchar();
	if (c == 'Y' || c == 'y' || c == 1)
		f[1] = 1;
	cout << *name3 << " Do you want ? ";
	fflush(stdin);
	c = getchar();
	if (c == 'Y' || c == 'y' || c == 1)
		f[2] = 1;
	string *str = GrabLandlord2(name1, name2, name3, f);
	if (str == NULL ||( !f[0] && f[1] && f[2])) {
		cout << "No one is willing to do the landlord ? But someone will do the landlord !" << endl;
		InitPoker(farmer1, farmer2, landlord);
	}
	if (str == name1) {
		*str = *name3;
		*name3 = *name1;
		*name1 = *str;
	}
	else if (str == name2) {
		*str = *name3;
		*name3 = *name2;
		*name1 = *str;
	}
	cout << "Congratulation ! ";
	cout << (*name3) << " is landlord !" << endl;
	return name3;
}
string *GrabLandlord2(string *name1, string *name2, string *name3, int f[])
{
	for (int i = 0;i < 3;i++) {
		if (f[i] == 0)
			continue;
		switch (i)
		{
		case 0:cout << *name1 << " Do you want ? ";break;
		case 1:cout << *name2 << " Do you want ? ";break;
		case 2:cout << *name3 << " Do you want ? ";break;
		}
		char c;
		fflush(stdin);
		c = getchar();
		if (c == 'N' || c == 'n' || c == 0)
			f[i] = 0;
	}
	int i = 2;
	while (i >= 0) {
		if (f[i]) {
			switch (i)
			{
			case 0:return name1;break;
			case 1:return name2;break;
			case 2:return name3;break;
			}
		}
		i--;
	}
	return NULL;
}
void GameIN()
{
	while () {


	}
}
string *RunBout()
{

	return winer;
}