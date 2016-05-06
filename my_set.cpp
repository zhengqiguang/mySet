#include "my_set.h"

ostream& operator<<(ostream& cout, const MySet& e)
{
	if (e.size() == 0)//元素个数为零时输出"{/}"表示空集
	{
		cout << "{/}";
		return cout;
	}
	if (e.isbasic && e.element && !e.set)
	{
		cout << e.name <<":{";
		for (auto& it : *e.element)
		{
			cout << it << ", ";
		}
		cout << "\b\b}";
		return cout;
	}
	else if (!e.isbasic && !e.element && e.set)
	{
		cout << e.name <<":{ ";
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
	if (set)//本集合非basic，却要添加一个basic元素，错误，返回集合本身
		return *this;
	if (!element)
		element = new std::set<string>();
	isbasic = true;
	element->insert(elementName);
	return *this;
}

MySet MySet::add(const MySet& newSet)
{
	if (element)//本集合是baisc，却要添加一个集合元素，错误，返回集合本身
		return *this;
	if (!set)
		set = new std::set<MySet>();
	isbasic = false;
	set->insert(newSet);
	return *this;
}

bool MySet::has(string name) const
{
	if (element)
		if (element->find(name) != element ->end())
			return true;
	return false;
}

bool MySet::has(MySet set) const
{
	if (this->set)
		if (this->set->find(set) != this->set->end())
			return true;
	return false;
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

MySet MySet::remove(const MySet & s)
{
	this->set->erase(s);
	return *this;
}

MySet MySet::operator+(const MySet & set)
{
	MySet s(*this, this->name + "+" + set.name);
	if (s.isbasic == false && set.isbasic == false)
	{
		for (auto& it : *set.set)
		{
			s.set->insert(it);
		}
	}
	if (s.isbasic == true && set.isbasic == true)
	{
		for (auto& it : *set.element)
		{
			s.element->insert(it);
		}
	}
	return s;

}

MySet MySet::operator*(const MySet & set)
{
	MySet s(*this, this->name + "*" + set.name);
	if (s.isbasic == false && set.isbasic == false)
	{
		for (auto& it : *this->set)
		{
			if(!set.has(it))
				s.remove(it);
		}
	}
	if (s.isbasic == true && set.isbasic == true)
	{
		for (auto& it : *this->element)
		{
			if (!set.has(it))
				s.remove(it);
		}
	}
	return s;
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

MySet MySet::without(const string & name)
{
	MySet s(*this ,this -> name + "-" + name);
	s.element->erase(name);
	return s;
}

MySet MySet::operator-(const MySet & set)
{
	MySet s(*this, this->name + "-" + set.name);

	if (!set.set && set.element)
	{
		if (!this->isbasic)
			return s;
		for (auto it : *set.element)
		{
//			s = s - it;
			s.remove(it);
		}
		return s;
	}
	else if (set.set && !set.element)
	{
		for (auto &it : *set.set)
		{
//			s = s - it;
			s.remove(it);
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