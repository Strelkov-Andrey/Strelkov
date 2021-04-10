#include<iostream>

using namespace std;

struct link
{
	int value;
	link* next;
};

class List;

class listIterator
{
	friend class List;
private:

	link* current;

public:
	listIterator()
	{
		current = NULL;

	}

	link* getLink()
	{
		return current;
	}

	listIterator operator=(const listIterator& iter) {
		current = iter.current;
		return *this;
	}
	listIterator operator ++()
	{
		current = current->next;
		return *this;
	}

	bool operator==(const listIterator& m) const {
		return (current == m.current);
	}


	bool operator!=(const listIterator& m) const {
		return (current != m.current);
	}


};

class List
{
	

public:
	link* first;

	List()
	{
		first = new link;
		first->next = NULL;
	}
	void add(int t)
	{
		link* tmp = new link;
		tmp->value = t;
		tmp->next = first;
		first = tmp;

	}


	listIterator begin()
	{
		listIterator it;
		it.current = first;
		return it;
	}
	/*void print()
	{
		link* tmp = first;
		while (tmp != NULL)
		{
			cout << tmp->value << " ";
			tmp = tmp->next;
		}
	}*/

};

bool searchloop1(List l)
{
	bool b=false;
	link* p1, *p2;
	p1 = l.first;
	p2 = l.first->next;
	while(true)
	{
		p1 = p1->next;
		p2 = p2->next->next;
		if(p1==p2)
		{
			b = true;
			break;
		}
		else if((p2==NULL)||(p2->next==NULL))
		{
			break;
		}
	}
	return b;
}

bool searchloop2(List l)
{
	bool b = false;
	link* n, * c, * p;
	p = l.first;
	c = l.first;
	n = l.first->next;
	while (true)
	{
		c = n;
		n = n->next;
		c->next = p;
		p = c;
		
		if (c == l.first)
		{
			b = true;
			break;
		}
		else if ((n == NULL) || (n->next == NULL))
		{
			break;
		}
	}
	while (true)
	{
		c = n;
		n = n->next;
		c->next = p;
		p = c;
		if (c == l.first)
		{
			break;
		}
		else if ((n == NULL) || (n->next == NULL))
		{
			break;
		}
	}
	return b;
}

int main()
{
	List l;
	for (int i = 0; i < 20; i++)
	{
		l.add(i);
	}

	listIterator it = l.begin();
	for (int i = 0; i < 20; i++)
	{
		++it;
	}
	

	link* k = it.getLink();
	it = l.begin();
	for (int i = 0; i < 7; i++)
	{
		++it;
	}
	k->next = it.getLink();
	bool b1 = searchloop1(l);
	bool b2 = searchloop2(l);
	
	cout << b1 << " " << b2;

	return 0;
}