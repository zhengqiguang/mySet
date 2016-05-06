#pragma once
#include <iostream>
#include <set>
#include <unordered_set>
#include<string>



using namespace std;
class MySet
{
protected:
	
	int id;
	static int count;
	set<string>* element = 0;
	set<MySet>* set = 0;
	bool isbasic;
	
	
public:
	const string name;

	MySet(): id(count++){}
	MySet(string name) : name(name), id(count++){}
	MySet(const MySet s, string name) : MySet(name)
	{
		this->isbasic = s.isbasic;
		if (s.element)
		{
			this->element = new std::set<string>;
			*this->element = *s.element;
		}
		if (s.set)
		{
			this->set = new std::set<MySet>;
			*this->set = *s.set;
		}
	}

	MySet add(const string& elementName);
	MySet add(const MySet& newSet);
	MySet remove(string name);
	MySet remove(MySet& s);


	bool has(string name) const;
	bool has(MySet set) const;
	int size() const;
	bool isEmpty() const;

	~MySet() {}


	MySet& operator=(const MySet& s);
	MySet operator-(const string& name);
	MySet operator-(const MySet& set);
	bool operator<(const MySet& s) const;
	friend ostream& operator<<(ostream& cout, const MySet& e);
};