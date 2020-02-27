#include "Jukehdlr.h"

class Menu
{
	public:
		Menu();
		void show();
	private:
		void clscreen();
		void setpause();
		bool validate(int);
		void setroute(int);
		void addsong();
		void showall();
		void showcurrent();
		void playnext();
		void playprevious();
		void repeatlist();
		void remove();
};