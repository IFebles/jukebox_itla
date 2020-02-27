#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() : _first(NULL), _last(NULL), _count(0)
{

}

void LinkedList::add(string songname, string artname)
{
	//cout << "Imma here!" << endl;
	Element* elem = new Element(songname, artname);

	if(_last == NULL)
		_first = _last = elem;
	else
	{
		elem->_prev = _last;
		_last->_next = elem;
		_last = elem;
	}

	_count++;
}

void LinkedList::showall()
{
	if(_count == 0)
	{
		cout << "* The list is empty! *" << endl;
		return;
	}

	Element* elem = _first;

	for(int x = 0; x < _count; x++)
	{
		cout << x+1 << ") " << elem->_title << ", "
		<< elem->_artist << " " << elem->_duration << endl;
		elem = elem->_next;
	}
}

void LinkedList::remove(int index)
{
	if(_count == 0)
	{
		cout << "* The list is empty! *" << endl;
		return;
	}
	if(index < 0)
	{
		cout << "* The position must be positive! *" << endl;
		return;
	}
	else if(index >= _count)
	{
		cout << "* Position out of bounds! *" << endl;
		return;
	}

	Element* elem = _first;

	for(int x = 0; x < index; x++)
		elem = elem->_next;

	//Si hay anterior al seleccionado:
	if(elem->_prev)
		elem->_prev->_next = elem->_next;
	else
		_first = elem->_next;

	//Si hay siguiente al seleccionado
	if(elem->_next)
		elem->_next->_prev = elem->_prev;
	else
		_last = elem->_prev;

	delete elem;

	_count--;

	cout << "* Deleted! *" << endl;
}