#include<vector>
#include<iostream>
#include<string>
#include "puzzle.h"
#ifndef MYVCLOCK_H
#define MYVCLOCK_H
using namespace std;
class MyVClock : public Puzzle<int, int>
{
	public:
		int maxHours;
		vector<int> steps;
		MyVClock(int maxHours, int initial, int goal, vector<int> steps);
		virtual bool isGoal(int) const;
		virtual vector<int> next(int);
		virtual int getInitial() const;
		virtual string print(const int &) const;
};

#endif
