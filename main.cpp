//#include "my_set.h"
//#include"VirSet.h"
#include "set_template.h"
using namespace std;
int main()
{
	/*
	MySet a("A");
	a.add("apple");
	a.add("banana");
	MySet b("B");
	b.add("c++");
	b.add("java");
	b.add("apple");
	MySet c("C");
	c.add(a);
	c.add(b);
	MySet d("D");
	d.add(a);
	d.add(c);
	cout << c+d;
	*/
	
	StrSet s;
//	VirSet& s = new StrSet;
	s.addElement("apple");
	s.addElement("banana");
	s.addElement("pear");

	StrSet b;
	b.addElement("banana");
	b.addElement("orange");

	cout << s * b;

	system("pause");
	return 0;
}