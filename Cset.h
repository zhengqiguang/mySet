#pragma once
#include <set>
#include"VirSet.h"
class CSet : protected VirSet
{
protected:
	set<VirSet> e;
};