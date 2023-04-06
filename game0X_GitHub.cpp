#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

//Write a "tic-tac-toe" game
void dataScience(char desk[3][3])
{
	cout << "Desk for game \"X\" & \"Y\"\n\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << "[" << desk[i][j] << "]";
		cout << endl;
	}

	cout << "\nUser, enter position of X & Y (1...3): ";
	int x, y;//user coordinates
	cin >> x >> y;

	cout << "\nComputer, enter position of X & Y (1...3): ";
	int x2, y2;//comp coordinates
	do
	{
		x2 = rand() % 3;
		y2 = rand() % 3;
	} while (desk[x2][y2] != '-'); //checking of occupied position for computer
	desk[x2][y2] = 'o';

	cout << endl;
}

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

	//Function
	dataScience(desk);

	return 0;
}
