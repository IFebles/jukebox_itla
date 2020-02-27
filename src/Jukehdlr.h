#include "LinkedList.h"

class Jukehdlr : LinkedList
{
public:
	Jukehdlr();
	void showcurrent();
	void next();
	void previous();
	std::string repeatable();
	LinkedList _myxlist;
private:
	Element* _current;
	bool _repeat;
};