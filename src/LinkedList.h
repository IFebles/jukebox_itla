#include "Element.h"

class LinkedList
{
	public:
		LinkedList();
		void add(std::string, std::string);
		void showall();
		void remove(int);
		int _count;
	private:
		Element* _first;
		Element* _last;

	friend class Jukehdlr;
};