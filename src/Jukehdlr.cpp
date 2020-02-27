#include <iostream>
#include "Jukehdlr.h"

using namespace std;

Jukehdlr::Jukehdlr() : _current(NULL), _repeat(false), _myxlist() { }

void Jukehdlr::showcurrent()
{
	if(_myxlist._count == 0)
	{
		cout << "* The list is empty! *" << endl;
		return;
	}

	if(_current == NULL)
		_current = _myxlist._first;


	cout << endl << "Current song:" << endl;
	cout << _current->getTitle() << ", "
	<< _current->getArtist() << " " << _current->getDuration() << endl;
}

void Jukehdlr::next()
{
	if(_myxlist._count == 0)
	{
		cout << "* The list is empty! *" << endl;
		return;
	}

	if(_current == NULL)
		_current = _myxlist._first;

	if(_current->getNext() != NULL)
		_current = _current->getNext();
	else if(_repeat)
		_current = _myxlist._first;
	else
		cout << endl << "* On the last song already *" << endl;

	cout << endl << "Current song:" << endl;
	cout << _current->getTitle() << ", "
	<< _current->getArtist() << " " << _current->getDuration() << endl;
}

void Jukehdlr::previous()
{
	if(_myxlist._count == 0)
	{
		cout << "* The list is empty! *" << endl;
		return;
	}

	if(_current == NULL)
		_current = _myxlist._first;

	if(_current->getPrevious() != NULL)
		_current = _current->getPrevious();
	else
		cout << endl << "* On the first song already *" << endl;

	cout << endl << "Current song:" << endl;
	cout << _current->getTitle() << ", "
	<< _current->getArtist() << " " << _current->getDuration() << endl;
}

string Jukehdlr::repeatable()
{
	_repeat = !_repeat;
	return _repeat ? "activated": "deactivated";
}