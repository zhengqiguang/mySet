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
	MySet d("D");
	d.add(a);
	d.add(c);
	cout << c+d;
	
	system("pause");
	return 0;
}