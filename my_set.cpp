#include "my_set.h"

ostream& operator<<(ostream& cout, const MySet& e)
{
	if (e.isbasic && e.element && !e.set)
	{
		cout << "{";
		for (auto& it : *e.element)
		{
			cout << it << ", ";
		}
		cout << "\b\b}";
		return cout;
	}
	else if (!e.isbasic && !e.element && e.set)
	{
		cout << "{ ";
		for (auto& it : *e.set)
		{
			cout << it << ", ";
		}
		cout << "\b\b }";
	}
	return cout;
}

MySet MySet::add(const string& elementName)
{
	if (set)
		return *this;
	if (!element)
		element = new std::set<string>();
	isbasic = true;
	element->insert(elementName);
	return *this;
}

MySet MySet::add(const MySet& newSet)
{
	if (element)
		return *this;
	if (!set)
		set = new std::set<MySet>();
	isbasic = false;
	set->insert(newSet);
	return *this;
}

int MySet::size() const
{
	return isEmpty() ? 0 : (isbasic ? element->size() : set ->size());
}

bool MySet::isEmpty() const
{
	return (element == 0 && set == 0) || (element != 0 && element -> size() == 0) || (set != 0 && set -> size() == 0);
}

MySet MySet::remove(string name)
{
	this->element->erase(name);
	return *this;
}

MySet MySet::remove(MySet & s)
{
	this->set->erase(s);
	return *this;
}

MySet & MySet::operator=(const MySet & s)
{
	if(s.element)
		*this->element = *s.element;
	if(s.set)
		*this->set = *s.set;
	this->isbasic = s.isbasic;
	return *this;
}

MySet MySet::operator-(const string & name)
{
	MySet s(*this ,this -> name + " - \"" + name + "\"");
	s.element->erase(name);
	return s;
}

MySet MySet::operator-(const MySet & set)
{
	MySet s(*this, this->name + " - " + set.name);

	if (!set.set && set.element)
	{
		if (!this->isbasic)
			return s;
		for (auto it : *set.element)
		{
			s = s - it;
		}
		return s;
	}
	else if (set.set && !set.element)
	{
		for (auto &it : *set.set)
		{
			s = s - it;
		}
		return s;
	}
	return s;
}

bool MySet::operator<(const MySet& s) const
{
	return this->id < s.id;
}

int MySet::count = 0;