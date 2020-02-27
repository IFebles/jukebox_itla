#include <iostream>
#include <cstdlib>
#include <climits>
#include "Menu.h"

using namespace std;

Jukehdlr handler;

Menu::Menu()
{
	
}

void Menu::clscreen()
{
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
}

void Menu::setpause()
{
	#ifdef _WIN32
	system("pause");
	#else
	system("read -n1 -r -p \"Press any key to continue...\" key");
	#endif
}

void Menu::show()
{
	int resp = 0;

	while(resp != 8)
	{
		clscreen();
		cout << "* Welcome to the jukebox! *\n\n";
		cout << "1- Add new song" << endl;
		cout << "2- List songs" << endl;
		cout << "3- Show current song" << endl;
		cout << "4- Next song" << endl;
		cout << "5- Previous song" << endl;
		cout << "6- Activate list repetition" << endl;
		cout << "7- Delete" << endl;
		cout << "8- Exit" << endl;

		cout << endl << ">> ";
		cin >> resp;

		if(validate(resp))
			setroute(resp);
	}
}

bool Menu::validate(int resp)
{
	if(resp >= 1 && resp <= 8)
		return true;
	else
	{
		cout << "* Invalid option! *" << endl;
		setpause();
		return false;
	}
}

void Menu::setroute(int resp)
{
	switch(resp)
	{
		case 1:
			addsong();
		break;
		case 2:
			showall();
		break;
		case 3:
			showcurrent();
		break;
		case 4:
			playnext();
		break;
		case 5:
			playprevious();
		break;
		case 6:
			repeatlist();
		break;
		case 7:
			remove();
		break;
		case 8:
			cout << "* Goodbye! *" << endl;
		break;
	}

	setpause();
}

void Menu::addsong()
{
	string songname = "";

	// To avoid having cout printing twice
	cin.ignore(INT_MAX, '\n');

	while(songname == "")
	{
		cout << "Input the song's name: ";
		getline(cin, songname);
	}

	string artname = "";

	while(artname == "")
	{
		cout << "Input the artist's name: ";
		getline(cin, artname);
	}

	handler._myxlist.add(songname, artname);

	cout << "* Added! *" << endl;
}

void Menu::showall()
{
	handler._myxlist.showall();

	cout << endl;
}

void Menu::showcurrent()
{
	handler.showcurrent();
	cout << endl;
}

void Menu::playnext()
{
	cout << "Trying to play the next song..." << endl;
	handler.next();
	cout << endl;
}

void Menu::playprevious()
{
	cout << "Trying to play the previous song..." << endl;
	handler.previous();
	cout << endl;
}

void Menu::repeatlist()
{
	cout << "List repetition " << handler.repeatable() << endl;
}

void Menu::remove()
{
	int inx = 0;

	while(inx == 0)
	{
		cout << "Input the position of the song to delete: ";
		cin >> inx;
	}

	handler._myxlist.remove(inx-1);
}
