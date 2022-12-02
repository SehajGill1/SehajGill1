/*
- Sehaj Gill, CS 1337.502, Program #4
- Software: Hp Laptop Core i5 10th Gen, Windows 10, OnlineGDB used.
- Game Engine Program
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;

                            /* Game Engine Program */
struct grid
{
	int row;
	int col;
	char symbol;
};

struct creature
{
	string name;
	int row;
	int col;
	char symbol;
};

struct user
{
	string name;
	string quest;
	string nonsense;

	int row;
	int col;
	char symbol;
};

//load file function
void loadFile(struct user *star, vector<creature>* monsters, vector <grid>* terrain)
{	
	ifstream myFile;
	string tempString;
	char tempChar;
	int tempInt;
	int creatureMax;
	int creatureLoop;
	int squareMax;
	int squareLoop;

	//opening the file
	myFile.open("Save.txt");
	cout << myFile.good() << ":" << myFile.bad() << ":" << myFile.fail() << endl;

	//read user
	getline(myFile, star->name, ',');     //get name
	getline(myFile, star->quest, ',');       //quest
	getline(myFile, star->nonsense, ',');    //nonsense
	
	getline(myFile, tempString, ',');
	star->symbol = tempString[0];
	
	getline(myFile, tempString, ',');
	star->row = stoi(tempString);
	
	getline(myFile, tempString, '\n');
	star->col = stoi(tempString);

	//load creatures
	getline(myFile, tempString);
	cout <<"[" << tempString <<"]" << endl;
	creatureMax = stoi(tempString);
	struct creature* creaturePtr = nullptr;
	
	for (creatureLoop = 0; creatureLoop < creatureMax; creatureLoop++)
	{
	    //allocate dynamically
		creaturePtr = new creature();
		getline(myFile, tempString, ',');
		
		creaturePtr->name = tempString;
		getline(myFile, tempString, ',');
		
		creaturePtr->symbol = tempString[0];
		getline(myFile, tempString, ',');
		
		creaturePtr->row = stoi(tempString);
		getline(myFile, tempString, '\n');
		
		creaturePtr->col = stoi(tempString);
		monsters->push_back(*creaturePtr);
	}
	
	//load the grid
	getline(myFile, tempString);
	cout << "[" << tempString << "]" << endl;
	squareMax = stoi(tempString);
	struct grid* squarePtr = nullptr;
	for (squareLoop = 0; squareLoop < squareMax; squareLoop++)
	{
	    //dynamically allocate
		squarePtr = new grid();

		getline(myFile, tempString, ',');
		squarePtr->symbol = tempString[0];

		getline(myFile, tempString, ',');
		squarePtr->row = stoi(tempString);

		getline(myFile, tempString, '\n');
		squarePtr->col = stoi(tempString);

		terrain->push_back(*squarePtr);
	}
	myFile.close();
	return;
}

void fillTerrain(user* studentPtr, vector<creature>* monsterPtr, vector<grid>* terrainPtr)
{
	int row;
	int col;

	studentPtr->symbol = 'S';
	studentPtr->row = 4;
	studentPtr->col = 4;

	int loop = 0;
	for (loop = 0; loop < 6; loop++)
	{
		row = rand() % 8 + 1;
		col = rand() % 8 + 1;
		creature* creaturePtr = new creature();
		creaturePtr->row = row;
		creaturePtr->col = col;
		creaturePtr->symbol = 'g';
		monsterPtr->push_back(*creaturePtr);
	}

	int option;
	char symbol='.';
	for (row = 0; row < 10; row++)
	{
		for (col = 0; col < 10; col++)
		{
			option = rand() % 4;
			symbol = '.';
			switch (option)
			{
			case 0:
				symbol = '$';
				break;
			case 1:
				symbol = '#';
				break;
			case 2:
				symbol = '@';
				break;
			}

			cout <<option<<","<< row << "," << col << "," << symbol << endl;
			grid * gridptr = new grid;
			gridptr->row = row;
			gridptr->col = col;
			gridptr->symbol = symbol;
			terrainPtr->push_back(*gridptr);
		}
	}
	return;
}

void displayTerrain(user student, vector<creature> monsters, vector<grid> terrain)
{
	char map[10][10];
	int row;
	int col;

	for (row = 0; row < 10; row++)
	{
		for (col = 0; col < 10; col++)
		{
			map[row][col] = '.';
		}
	}

	int terrainMax;
	int terrainLoop;
	grid gtemp;
	terrainMax = terrain.size();
	for (terrainLoop = 0; terrainLoop < terrainMax; terrainLoop++)
	{
		gtemp = terrain[terrainLoop];
		map[gtemp.row][gtemp.col] = gtemp.symbol;
	}
	
	int monsterMax;
	int monsterLoop;
	monsterMax = monsters.size();
	
	for (monsterLoop = 0; monsterLoop < monsterMax; monsterLoop++)
	{
		creature temp = monsters[monsterLoop];
		map[temp.row][temp.col] = temp.symbol;
	}
	map[student.row][student.col] = student.symbol;

	for (row = 0; row < 10; row++)
	{
		for (col = 0; col < 10; col++)
		{
			cout << setw(2) << map[row][col];
		}
		cout << endl;
	}
	return;
}


void myName(string name, string Course)
{
    name = "Sehaj Gill";
    Course = "CS 1337.502";
    
    cout << name << endl;
    cout << Course << endl;
    cout << "Program #4" << endl;
    cout << "-----------" << endl;
}

int main()
{
    string name, Course;
    myName(name, Course);
    
	user star;
	vector <creature> monstersVec;
	vector <grid> terrain;
	
	srand(clock());

	loadFile(&star, &monstersVec, &terrain);
	cout << star.name << endl;
	cout << star.quest << endl;
	cout << star.nonsense << endl;
	cout << star.symbol << endl;
	cout << "(" << star.row << "," << star.col << ")" << endl;

	for (creature temp : monstersVec)
	{
		cout << temp.name;
		cout << ",";
		cout << temp.symbol;
		cout << ",";
		cout << temp.row;
		cout << ",";
		cout << temp.col;
		cout << endl;
	}

	for (grid tempGrid : terrain)
	{
		cout << tempGrid.symbol;
		cout << ",";
		cout << tempGrid.row;
		cout << ",";
		cout << tempGrid.col;
		cout << endl;
	}
	
	fillTerrain(&star,&monstersVec,&terrain);
	displayTerrain(star,monstersVec,terrain);
	
	return 0;
}