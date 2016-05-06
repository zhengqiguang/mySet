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

void MySet::add(const string& elementName)
{
	if (set)
		return;
	if (!element)
		element = new std::set<string>();
	isbasic = true;
	element->insert(elementName);
}

void MySet::add(const MySet newSet)
{
	if (element)
		return;
	if (!set)
		set = new std::set<MySet>();
	isbasic = false;
	set->insert(newSet);
}

int MySet::size() const
{
	return isEmpty() ? 0 : (isbasic ? element->size() : set ->size());
}

bool MySet::isEmpty() const
{
	return (element == 0 && set == 0) || (element != 0 && element -> size() == 0) || (set != 0 && set -> size() == 0);
}

MySet::~MySet()
{/*
	if (element)
		delete element;
	else if (set)
		delete set;
		*/
}

void MySet::remove(string name)
{
	for (auto& it : *this->element)
	{
		
	}
	this->element->erase(name);
}

MySet & MySet::operator=(const MySet & s)
{
	// TODO: 在此处插入 return 语句
//	this->name = s.name;
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
//	s.element = new std::set<string>;

//	s = *this;

	s.element->erase(name);
//	s.name = this->name + " - " + name;
	return s;
}

MySet MySet::operator-(const MySet & set)
{
	MySet s;
	if (this->element)
		s.element = new std::set <string>;
	if(this ->set)
		s.set = new std::set <MySet>;
	s = *this;
	if (!set.set && set.element)
	{
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
	return 0;
}

bool MySet::operator<(const MySet& s) const
{
	return this->id < s.id;
}

int MySet::count = 0;