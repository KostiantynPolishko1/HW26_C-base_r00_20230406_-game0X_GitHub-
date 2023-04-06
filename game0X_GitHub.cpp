#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

//Write a "tic-tac-toe" game

bool gameWin(char desk[3][3], char s);

void dataScience(char desk[3][3])
{
	int count = 0;
	do
	{
		string t;
		if (count == 0) t = "Start. ";
		if (count == 9) t = "Finish. ";
		if (count > 1 && count < 9) t = "Restart. ";

		cout << t << "Step: " << count << endl;

		cout << "Desk for game \"X\" & \"Y\"\n\n";
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				cout << "[" << desk[i][j] << "]";
			cout << endl;
		}

		if (count == pow(3, 2))
		{
			break;
		}
		cout << "\nUser, enter position of X & Y (1...3): ";
		int x, y;//user coordinates
		cin >> x >> y;

		if (x < 1 || x >3 || y < 1 || y >3) //checking of user coordinates
		{
			cout << "Coordinates is out of range. Repeat new X & Y (1...3): \n";
			continue;
		}

		if (desk[x - 1][y - 1] == 'x' || desk[x - 1][y - 1] == 'o') //checking of occupied position for user
		{
			cout << "Position is occupied. Repeat new X & Y (1...3): \n";
			continue;
		}

		desk[x - 1][y - 1] = 'x';

		if (gameWin(desk, 'x'))
			break;

		//counter of step for stop game
		count++;
		if (count == pow(3, 2))
		{
			cout << "\nStop game\n";
			continue;
		}
		cout << "\nComputer, enter position of X & Y (1...3): ";
		int x2, y2;//comp coordinates
		do
		{
			x2 = rand() % 3;
			y2 = rand() % 3;
		} while (desk[x2][y2] != '-'); //checking of occupied position for computer
		desk[x2][y2] = 'o';

		if (gameWin(desk, 'o'))
			break;

		//counter of step for stop game
		count++;

	} while (true);
}

bool gameWin(char desk[3][3], char s)
{
	//gameWinner
	int w0 = 0, w1 = 0, w2 = 0, w3 = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (desk[i][j] == s)//matches by horizontal lines
				w0++;

			if (desk[j][i] == s)//matches by vertical lines
				w1++;

			if (desk[j][j] == s)//matches by diagonal line from left up to right down
				w2++;

			if (desk[2 - j][j] == s)//opposite matches by diagonal line from right up to left down
				w3++;
		}
		if (w0 == 3 || w1 == 3 || w2 == 3 || w3 == 3)
		{
			return true;
			break;
		}
		w0 = 0, w1 = 0, w2 = 0, w3 = 0;
	}
	return false;
}

void printGameResult(char desk[3][3])
{
	if (gameWin(desk, 'x'))
		cout << "\nUser won\n";

	if (gameWin(desk, 'o'))
		cout << "\nComputer won\n";

	if (gameWin(desk, 'x') == false && gameWin(desk, 'o') == false)
		cout << "\nNo one has won\n";

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << "[" << desk[i][j] << "]";
		cout << endl;
	}
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
	printGameResult(desk);

	return 0;
}
