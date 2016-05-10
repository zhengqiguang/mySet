#pragma once
#include <iostream>
#include <string>
#include <set>
using namespace std;
template <class Type>
class mySetT
{
protected:
	const int id;
	static int count;
	set<Type>* e = 0;

public:
	const string name;

	mySetT() :id(count++), e(new set<Type>) {}
	mySetT(string name) :name(name), id(count++), e(new set<Type>)  {}


	mySetT<Type> addElement(const Type& element);
	mySetT<Type> removeElement(const Type& element);

	static mySetT<Type> unionOf(const mySetT<Type>& a, const mySetT<Type>& b);
	static mySetT<Type> intersectionOf(mySetT<Type>& a, mySetT<Type>& b);

	int size() const { return e->size(); }
	bool has(const Type& element) const { for (auto it : *e)if (it == element) return true; return false; }
	bool isEmpty() const { return (!e || size() == 0); }

};

template <class Type> 
int mySetT<Type>::count = 0;

typedef mySetT<string> strSet;


template<class Type>
inline mySetT<Type> mySetT<Type>::addElement(const Type& element)
{
	e->insert(element);
	return *this;
}

template<class Type>
inline mySetT<Type> mySetT<Type>::removeElement(const Type& element)
{
	e->erase(element);
	return *this;
}

template<class Type>
inline mySetT<Type> mySetT<Type>::unionOf(const mySetT<Type>& a, const mySetT<Type>& b)
{
	mySetT<Type> s;
	*s.e = *a.e;
	for (auto it : *b.e)
	{
		s.e->insert(it);
	}

	return s;
}

template<class Type>
inline mySetT<Type> mySetT<Type>::intersectionOf(mySetT<Type>& a, mySetT<Type>& b)
{
	mySetT<Type> s;
	*s.e = *a.e;
	for (auto it : *a.e)
	{
		if (!b.has(it))
			s.e->erase(it);
	}
	return s;
}
