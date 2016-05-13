#pragma once
#include <string>
using namespace std;
class VirSet
{
public:
	const int id;
	const string name;
	VirSet():name("NoName"), id(count++){}
	VirSet(string name):name(name), id(count++){}
protected:
	static int count;
};
int VirSet::count = 0;