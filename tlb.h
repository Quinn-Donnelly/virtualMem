#pragma once
#ifndef TLB_H
#define TLB_H
#include <iostream>
#include <map>
#include "tlb.cpp"

class TLB 
{
	public:
		// Inserts the new entry into the table if the entry is already in table returns false
		bool insert(const unsigned int pageNum, const unsigned int frameNum);
		// Checks if the page is loaded and returns the frame number if it is else it returns max datatype
		unsigned int isLoaded(const unsigned int pageNum);
	private:
		std::map<unsigned int, unsigned int> table;
};


#endif // !TLB_H
