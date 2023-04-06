#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

//Написать игру «Крестики-нолики»

int main()
{
	//Start point
	//x - user
	//o - compture
	srand(time(0));
	char desk[3][3]{};

	for (int i = 0; i < 3; i++) // fill the desk
		for (int j = 0; j < 3; j++)
			desk[i][j] = '-';

	return 0;
}
