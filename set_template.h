#pragma once
#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;


template <class Type>
class mySetT
{
protected:
	const int id;
public:
	const string name;
protected:
	static int count;//一类集合的总数量
	set<Type>* e = 0;
	string initName(int id){string name;stringstream buf;buf << "ID:" << id;buf >> name;return name;}//初始化集合名的辅助函数

public:
	mySetT() : name(initName(id)), id(count++), e(new set<Type>) {}//无参构造函数，自动命名
	mySetT(string name) :name(name), id(count++), e(new set<Type>)  {}//用户命名的构造函数

	mySetT<Type> addElement(const Type& element);//添加元素
	mySetT<Type> removeElement(const Type& element);//移除元素

	static mySetT<Type> unionOf(const mySetT<Type>& a, const mySetT<Type>& b);//求两个集合的并集
	static mySetT<Type> intersectionOf(const mySetT<Type>& a, const mySetT<Type>& b);//求两个集合的交集

	int size() const { return e->size(); }//返回集合元素个数
	bool has(const Type& element) const { if (e->find(element) != e->end())return true; return false; }//判断是否含有元素element
	bool isEmpty() const { return (!e || size() == 0); }//判断是否为空集
	bool isSubsetOf(const mySetT<Type>& s) const;//判断是否是s的子集
	bool isEuqal(const mySetT<Type>& a, const mySetT<Type>& b)const;//判断两个集合是否相等
	bool operator<(const mySetT<Type>& s)const;//为关联容器提供的比较函数

	mySetT<Type> operator=(const mySetT<Type> s)const;//赋值
	mySetT<Type> operator+(const mySetT<Type> s)const;//并集
	mySetT<Type> operator-(const mySetT<Type> s)const;//差集
	mySetT<Type> operator*(const mySetT<Type> s)const;//交集

	friend ostream& operator<<(ostream& cout, mySetT<Type>& s);//输出集合
};

template <class Type> 
int mySetT<Type>::count = 0;

typedef mySetT<string> StrSet;
typedef mySetT<StrSet> SetSet;


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
inline mySetT<Type> mySetT<Type>::intersectionOf(const mySetT<Type>& a, const mySetT<Type>& b)
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

template<class Type>
inline bool mySetT<Type>::isSubsetOf(const mySetT<Type>& s) const
{
	for (auto it : *e)
	{
		if (!s.has(it))
			return false;
	}
	return true;
}

template<class Type>
inline bool mySetT<Type>::isEuqal(const mySetT<Type>& a, const mySetT<Type>& b)const
{
	return a.isSubsetOf(b) && b.isSubsetOf(a);
}

template<class Type>
inline bool mySetT<Type>::operator<(const mySetT<Type>& s) const
{
//	if (this->size() < s.size())
//		return true;
	if (this->name < s.name)
		return true;
	if (this->id < s.id)
		return true;
	return false;
}

template<class Type>
inline mySetT<Type> mySetT<Type>::operator=(const mySetT<Type> s) const
{
	*(this->e) = *s.e;

	return *this;
}

template<class Type>
inline mySetT<Type> mySetT<Type>::operator+(const mySetT<Type> s) const
{
	return unionOf(*this, s);
}

template<class Type>
inline mySetT<Type> mySetT<Type>::operator-(const mySetT<Type> s) const
{
	mySetT<Type> ans;
	ans = *this;
	for (auto it : *(intersectionOf(*this, s).e))
	{
		ans.removeElement(it);
	}

	return ans;
}

template<class Type>
inline mySetT<Type> mySetT<Type>::operator*(const mySetT<Type> s) const
{
	return intersectionOf(*this, s);
}


template<class Type>
inline ostream & operator<<(ostream & cout, mySetT<Type>& s){ cout << s.name << ":"; }

inline ostream & operator<<(ostream & cout, StrSet & s)
{
	if (s.isEmpty())
	{
		cout << "(/)";
		return cout;
	}
	cout << "{";
	for (auto it : *s.e)
	{
		cout << it << ",";
	}
	cout << "\b}";
	return cout;
}

inline ostream & operator<<(ostream & cout, SetSet & s)
{
	if (s.isEmpty())
	{
		cout << "(/)";
		return cout;
	}
	cout << "{";
	for (auto it : *s.e)
	{
		cout << it << ",";
	}
	cout << "\b}";
	return cout;
}
