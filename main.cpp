//#include "my_set.h"

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
	
	strSet s("A");
	s.addElement("apple");
	s.addElement("banana");
	s.addElement("pear");

	strSet b;
	b.addElement("banana");
	b.addElement("orange");

	cout << strSet::unionOf(s, b).size();
	cout << strSet::intersectionOf(s,b).size();

	system("pause");
	return 0;
}