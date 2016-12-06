#pragma once
#ifndef TLB_H
#define TLB_H
#include <iostream>
#include <map>

class TLB 
{
	public:
		// Inserts the new entry into the table if the entry is already in table returns frame number (max datatype if exists)
		unsigned long insert(const unsigned long &pageNum, char * page);
		// Checks if the page is loaded and returns a bool true = exits
		bool isLoaded(const unsigned long &pageNum);
		// Returns the frame number for the given page number if the page number is not found returns the max datatype
		unsigned long getFrame(const unsigned long &pageNum);
		// Returns the value at the fram number and offset returns max int on no frame loaded
		char readData(const unsigned long &frameNum, const unsigned long &offset)const;

		TLB() { numFrames = 0; }

	private:
		unsigned long numFrames;
		std::map<unsigned long, unsigned long> table;
		char physicalStore[256][256];
};

#include "tlb.cpp"

#endif // !TLB_H
