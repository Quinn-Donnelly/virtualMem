#ifndef TLB_CPP
#define TLB_CPP
#include <iostream>
#include <limits>
#include "tlb.h"

bool TLB::insert(const unsigned int pageNum, const unsigned int frameNum) 
{
	if (table.find(pageNum) != table.end())
	{
		return false;
	}

	table.insert(std::pair<unsigned int, unsigned int>(pageNum, frameNum));

	return true;
}

unsigned int TLB::isLoaded(const unsigned int pageNum)
{
	std::map<unsigned int, unsigned int>::iterator f = table.find(pageNum);
	if (f != table.end())
	{
		return f->second;
	}

	return std::numeric_limits<unsigned int>::max();
}


#endif // !TLB_CPP
