#include <iostream>
#include <cstdlib>
#include <list>


using namespace std;

template <class T> class DList
{
protected:
	Unit* firstptr;
	Unit* lastptr;
	Unit* currentptr;
	unsigned size;

		template <class T> class Unit
		{
		private:
			T content;
			Unit* nextptr;
			Unit* prevptr;
		public:
			Unit()
			{
				nextptr = NULL;
				prevptr = NULL;
				content = static_cast<T>(NULL);
			}
			Unit* next()
			{
				return nextptr;
			}
			Unit* prev()
			{
				return prevptr;
			}
			T& val()
			{
				return &content;
			}
		};

	DList()
	{
		currentptr = NULL;
		firstptr = NULL;
		lastptr = NULL;
		size = 0;
	}
	void push_front(const T& val)
	{
		class Unit * newcell = new Unit;
		newcell->content = val;
		if (firstptr == NULL && lastptr == NULL)
		{
			firstptr = newcell;
			lastptr = newcell;
			newcell->nextptr = NULL;
			newcell->prevptr = NULL;
			size = 1;
		}
		else
		{
			firstptr->prevptr = newcell;
			newcell->prevptr = NULL;
			newcell->nextptr = firstptr;
			firstptr = newcell;
			size++;
		}
	}
	void pop_front();
	void push_back(const T& val)
	{
		class Unit * newcell = new Unit;
		newcell->content = val;
		if (firstptr == NULL && lastptr == NULL)
		{
			firstptr = newcell;
			lastptr = newcell;
			newcell->nextptr = NULL;
			newcell->prevptr = NULL;
			size = 1;
		}
		else
		{
			lastptr->nextptr = newcell;
			newcell->nextptr = NULL;
			newcell->prevptr = lastptr;
			lastptr = newcell;
			size++;
		}
	}
	void pop_back();
	Unit* insert(Unit* u, const T& val);
	Unit* first()
	{
		return firstptr;
	}
	Unit* last()
	{
		return lastptr;
	}
	Unit* erase(Unit* u)
	{

	}
	void clear();
	bool empty()
	{
		bool out = (firstptr == NULL && lastptr == NULL) ? true : false;
		return out;
	}
	unsigned size()
	{
		return size;
	}
	void reverse();
};

int main()
{

}
