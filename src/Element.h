
class Element
{
	public:
		Element(std::string,std::string);
		std::string getTitle();
		std::string getArtist();
		std::string getDuration();
		Element* getPrevious();
		Element* getNext();
	private:
		std::string _title;
		std::string _artist;
		std::string _duration;
		Element* _prev;
		Element* _next;

	friend class LinkedList;
};