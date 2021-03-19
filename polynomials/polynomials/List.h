#pragma once

template <class ValType>
struct link
{
	ValType value;
	link* next;
};

template<class ValType>
class List;

template<class ValType>
class listIterator
{
	friend class List<ValType>;
private:

	link<ValType>* current;

public:
	listIterator()
	{
		current = NULL;

	}

	ValType& getValue()
	{
		return current->value;
	}

	bool nextMonom()
	{
		bool b = current->next != NULL;
		return b;
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

template <class ValType>
class List
{
	link <ValType>* first;

public:

	List()
	{
		first = new link<ValType>;
		first->next = NULL;
	}
	void add(ValType t)
	{
		link<ValType>* tmp = new link<ValType>;
		tmp->value = t;
		tmp->next = first;
		first = tmp;

	}


	listIterator<ValType> begin()
	{
		listIterator<ValType> it;
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