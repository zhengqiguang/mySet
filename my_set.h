#pragma once
#include <iostream>
#include <set>
#include<string>



using namespace std;
class MySet
{
protected:
	
	const int id;//对象编号，不允许修改，初始化时赋值
	static int count;//记录一共的对象数
	set<string>* element = 0;//指向元素为字符串的集合的指针
	set<MySet>* set = 0;//指向元素为集合的集合的指针
	bool isbasic;//集合元素为字符串时，为true;
	
public:
	const string name;//集合名，不允许修改，初始化时赋值

	MySet(): id(count++){}//无参构造函数，只有ID
	MySet(string name) : name(name), id(count++){}//参数是集合名的构造函数
	//构造函数集合内元素由第一个参数给出，集合名由第二个参数给出
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

	MySet add(const string& elementName);//集合中添加字符串元素
	MySet add(const MySet& newSet);//集合中添加集合元素
	MySet remove(string name);//删除字符串元素
	MySet remove(const MySet& s);//删除集合元素
	MySet without(const string& name);//集合中排出某元素，返回排除后的集合

	bool has(string name) const;//查找某元素是否存在
	bool has(MySet set) const;//查找某元素是否存在
	int size() const;//返回集合元素个数
	bool isEmpty() const;//判断是否是空集

	~MySet() {}

	MySet operator+(const MySet& set);//集合的并集
	MySet operator*(const MySet& set);//集合的交集
	MySet& operator=(const MySet& set);//赋值运算符(不用了)
	MySet operator-(const MySet& set);//减法运算符，集合A-B是从A中除去B有含有的元素
	bool operator<(const MySet& s) const;//小于运算符，为set中排序而设置，依据ID排序
	friend ostream& operator<<(ostream& cout, const MySet& e);//输出
};