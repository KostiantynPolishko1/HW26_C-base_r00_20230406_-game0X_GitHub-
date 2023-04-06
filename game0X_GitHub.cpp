#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

//Write a "tic-tac-toe" game
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
		//counter of step for stop game
		count++;

	} while (true);
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
