#pragma once
#ifndef TLB_H
#define TLB_H
#include <iostream>
#include <map>

class TLB 
{
	public:
		// Inserts the new entry into the table if the entry is already in table returns false
		bool insert(const unsigned int pageNum, const unsigned int frameNum);
		// Checks if the page is loaded and returns a bool true = exits
		bool isLoaded(const unsigned int pageNum);
		// Returns the frame number for the given page number if the page number is not found returns the max datatype
		unsigned int getFrame(const unsigned int pageNum);
	private:
		std::map<unsigned int, unsigned int> table;
};

#include "tlb.cpp"

#endif // !TLB_H
