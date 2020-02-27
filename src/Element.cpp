#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include "Element.h"

using namespace std;

Element::Element(string sname, string aname) : _title(sname), _artist(aname),
_duration(""), _prev(NULL), _next(NULL)
{
	ostringstream temp;
	srand(time(NULL));
	temp << rand() % 6 << ":";
	temp << rand() % 60;
	_duration += temp.str();
}

std::string Element::getTitle() {
	return _title;
}

std::string Element::getArtist() {
	return _artist;
}

std::string Element::getDuration() {
	return _duration;
}

Element* Element::getPrevious(){
	return _prev;
}

Element* Element::getNext(){
	return _next;
}