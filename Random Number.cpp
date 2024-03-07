#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<Windows.h>
#include<ctime>
using namespace std;
string state="";
int health = 3;
void underline()
{
	for (int i = 0; i < 110; ++i) {
		cout << '-';
	}
	cout << "\n";
}
void interface_()
{
	underline();
	cout << "|" << "\t\t\t" << "----------------------------------------------------------------\t\t" << "     |" << endl
		<< "|" << "\t\t\t" << "|     Welcome To My Game Guess The Random Number   (*^_^*)     |\t\t" << "     |" << endl
	    <<"|"<<"\t\t\t"<< "----------------------------------------------------------------\t\t" << "     |" << endl;
	underline();
}
int option()
{
	interface_();
	int choice;
	do
	{
		underline();
		cout << "|\t\t\tEnter Your Level Please,  \t\t\t\t\t\t\t     |\n";
		cout << "|\t\t\t" << "[1]-EASY\t\t\t\t\t\t\t\t\t     |\n"
			<< "|\t\t\t" << "[2]-MEDIUM\t\t\t\t\t\t\t\t\t     |\n"
			<< "|\t\t\t" << "[3]-HARD\t\t\t\t\t\t\t\t\t     |\n"
			<< "|\t\t\t" << "Enter Your Choice : ";
		cin >> choice;
	}
		while (choice > 3 || choice < 1);
	cout << "\t\t\t\t\t\t\t\t\t\t\t|\n";
	return choice;
}
void level_interface(int difficult)
{
	cout << "|\t\t\t |                   Guessing Number From 1 - "<<difficult<<"\t\t| \t\t     | \n";
	cout << "|" << "\t\t\t" << " ----------------------------------------------------------------\t\t" << "     |" << endl;
	cout << "|" << "\t\t\t" << " ----------------------------------------------------------------\t\t" << "     |" << endl;
	cout << "|\t\t         |        Trial : " << health << "/3" << "\t\t\t     ";
	if (health == 3)
		cout << "State  :  " << "\t        |\t\t     |\n";
	else
	{
		if (state == "High")
			cout << "State  :  " << state << "\t|\t\t     |\n";
		else
			cout << "State  :  " << state << "\t|\t\t     |\n";

	}
	cout << "|" << "\t\t\t" << " ----------------------------------------------------------------\t\t" << "     |" << endl;
}
void level(int difficult)
{
	    //level_interface();
	    health = 3;
		state = "";
		srand(time(NULL));
		int random = rand() % difficult+ 1;
		int get;
		do
		{
	    level_interface(difficult);
		//cout << random<<endl;
			if (health < 1)
			{
				cout << "|                        |           Game Over.. The Number Is "<<random<<"                        |\t\t     |\n";
				break;
			}
			cout << "| Guess The Number Please From 1 - "<<difficult<<" : ";
			cin >> get;
			if (get > random)
			{
				cout << "|\t\t\t\t  -----------------------\t\t\t\t\t\t     |\n";
				cout << "|\t\t\t\t\  |  High....Try Again  |\t\t\t\t\t\t     |\n";
				state = "High";
				health--;
				//continue;
			}
			else if (get < random)
			{
				cout << "|\t\t\t\t  -----------------------\t\t\t\t\t\t     |\n";
				cout << "|\t\t\t\t  |  Low....Try Again   |\t\t\t\t\t\t     |\n";
				state = "Low";
				health--;
				//continue;
			}
			else
			{
				cout << "|\t\t\t\t  -----------------------\t\t\t\t\t\t     |\n";
				cout << "|\t\t\t\t  | Correct... Good Job |\t\t\t\t\t\t     |\n";
			}
			underline();
		    for (int i = 3; i >0; i--)
		    {
		    	cout << "Waiting For " << i<<"..s" << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		    	Sleep(1000);
		    }
		    	system("cls");
				interface_();

		} while (get != random);
	cout << "|" << "\t\t\t" << " ----------------------------------------------------------------\t\t" << "     |" << endl;
}
int main()
{
	int trial = 1;
	while (trial)
	{
		int select_level = option();
		system("CLS");
		interface_();
		switch (select_level)
		{
		case 1:
			level(10);
			break;
		case 2:
			level(50);
			break;
		case 3:
			level(100);
			break;
		}
		char again;
		cout << "You Want To Play Again ? (Y/N) : ";
		cin >> again;
		if (again == 'Y' || again == 'y')
			trial = 1;
		else
			trial = 0;
		system("cls");
	}
	system("CLS");
	underline();
	cout << "|\t\t\t\t\t\t\tThank You (*^_^*)\t\t\t\t     |\n";
	underline();
	return 0;
}
