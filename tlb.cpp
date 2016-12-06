#define _SCL_SECURE_NO_WARNINGS
#ifndef TLB_CPP
#define TLB_CPP
#include <iostream>
#include <limits>
#include "tlb.h"

unsigned long TLB::insert(const unsigned long &pageNum, char * page) 
{
	std::map<unsigned long, unsigned long>::iterator frame = table.find(pageNum);
	if (frame != table.end())
	{
		return frame->second;
	}

	for (int i = 0; i < 256; ++i)
	{
		physicalStore[numFrames][i] = page[i];
	}

	table.insert(std::pair<unsigned long, unsigned long>(pageNum, numFrames));

	return numFrames++;
}

bool TLB::isLoaded(const unsigned long &pageNum)
{
	std::map<unsigned long, unsigned long>::iterator f = table.find(pageNum);
	if (f != table.end())
	{
		return true;
	}

	return false;
}

unsigned long TLB::getFrame(const unsigned long &pageNum)
{
	std::map<unsigned long, unsigned long>::iterator f = table.find(pageNum);
	if (f != table.end())
	{
		return f->second;
	}

	return std::numeric_limits<unsigned long>::max();
}


char TLB::readData(const unsigned long &frameNum, const unsigned long &offset) const
{
	return physicalStore[frameNum][offset];
}

#endif // !TLB_CPP
