/*
- Sehaj Gill, CS 1337.502, Program #4
- Software: Hp Laptop Core i5 10th Gen, Windows 10, OnlineGDB used.
- World Builder Program
*/

#include<iostream>
#include<iomanip>
#include<vector>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<fstream>

using namespace std;

                                /* World Builder Program */

void myName(string name, string Course)
{
    name = "Sehaj Gill";
    Course = "CS 1337.502";
    
    cout << name << endl;
    cout << Course << endl;
    cout << "Program #4" << endl;
    cout << "-------------" << endl;
    cout << endl;
}

struct user
{
	string name;
	string quest;
	string nonsense;

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

struct grid
{
	int row;
	int col;
	char symbol;
};


//create user function
void createUser(user *student)
{
    string Name;
    cout << "What is your name?" << endl;
    cin.ignore();
    getline(cin, Name);
    
    string Quest;
    cout << "What is your quest?" << endl;
    getline(cin, Quest);
    
    srand(time(NULL));
	int x = rand() % 3 + 1;

    string nonsense;
    
	if (x == 1)
	{
		cout << "What is your favorite color?" << endl;
	}
	else if (x == 2)
	{
		cout << "What is the capital of Assyria?" << endl;
	}
	else if (x == 3)
	{
		cout << "What is the airspeed velocity of an unladen swallow?" << endl;
	}
    getline(cin, nonsense);
    
    char Symbol;
    cout << "What is your symbol?" << endl;
    cin >> Symbol;
    
    int row;
    cout << "What row are you in?" << endl;
    cin >> row;
    
    int col;
    cout << "What column are you in?" << endl;
    cin >> col;
    
    student->name = Name;
    student->quest = Quest;
    student->nonsense = nonsense;
    student->symbol = Symbol;
    student->row = row;
    student->col = col;
}

//create creature function
void createCreature(vector<creature> *monsters)
{
    string Name;
    cout << "What is its name?" << endl;
    cin >> Name;
    
    char Symbol;
    cout << "What is its symbol?" << endl;
    cin >> Symbol;
    
    int row;
    cout << "What row is it in?" << endl;
    cin >> row;
    
    int col;
    cout << "What column is it in?" << endl;
    cin >> col;
    
    //using dynamic memory
    struct creature * newCreature;
    newCreature = new struct creature;
    
    newCreature->name = Name;
    newCreature->row = row;
    newCreature->col = col;
    newCreature->symbol = Symbol;
    
    monsters->push_back(*newCreature);
}

//create terrain function
void createTerrain(vector<grid> * terrain)
{
    int row;
    cout << "What row will this be?" << endl;
    cin >> row;
    
    string data;
    cout << "Please type 10 characters" << endl;
    cin >> data;
    
    //if data is not 10 characters long
    while(data.size() != 10)
    {
        cout << "Type 10 characters" << endl;
        cin >> data;
    } 
    cout << "Thank you, Processing" << endl << endl;
    
    struct grid * newGrid;
    for(int i = 0; i < 10; i++)
{
    newGrid = new struct grid;
    newGrid->row = row;
    newGrid->col = i;
    newGrid->symbol = data[i];
    
    terrain->push_back(*newGrid);
        }
    return;
}

void saveFile(user student, vector<creature> monsters, vector<grid> terrain)
{
    ofstream myfile;
    myfile.open("Save.txt", ios::in);
    
    myfile << student.name << "," << student.quest << "," << student.nonsense << "," << student.row << "," << student.col;
    myfile << monsters.size() << endl;
    
    for(creature i : monsters)
    myfile << i.name << "," << i.symbol << "," << i.row << "," << i.col << endl;
    
    myfile << terrain.size() << endl;
    
    for(grid i : terrain)
    myfile << i.symbol << "," << i.row << "," << i.col << endl;
    
    myfile.close();
    
}

void theMenu(user student, vector<creature> monsters, vector<grid> terrain)
{
    int menu;
    vector <creature> monVec;
    vector <grid> terrainVec;

    do
    {
        
    cout << "1. Create User" << endl;
    cout << "2. Create Creature" << endl;
    cout << "3. Create a row of terrain" << endl;
    cout << "4. Save File" << endl;
    cout << "5. Quit" << endl;
    cout << "===========================" << endl << endl;
    
    cin >> menu;
    
    switch(menu)
    {
        case 1:
        createUser(&student);
        break;
        
        case 2:
        createCreature(&monVec);
        break;
        
        case 3:
        createTerrain(&terrainVec);
        break;
        
        case 4:
        saveFile(student, monVec, terrainVec);
        break;
        
        case 5:
        break;
        
        default:
        cout << "Invalid Selection!" << endl << endl;
        }
    }
    while(menu != 5);
}

int main()
{
    srand(clock());
    
    string name, Course;
    myName(name, Course);
    
    user student;
    vector<creature> monsters;
    vector<grid> terrain;
    
    theMenu(student, monsters, terrain);
    
}