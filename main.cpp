#include "my_set.h"
using namespace std;
int main()
{
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
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;
	
	cout << "a - b :"<< (a - b).name << a - b << endl;
	cout << "b - a :" << b - a << endl;
	cout << "c - a :" << c - a << endl;
	cout << c.remove(a) << endl;
	cout << a.add("pear");
	system("pause");
	return 0;
}