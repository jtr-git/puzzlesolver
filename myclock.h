#include<vector>
#include<iostream>
#include<string>
#include "puzzle.h"
#ifndef MYCLOCK_H
#define MYCLOCK_H
using namespace std;
class MyClock : public Puzzle<int, int>
{
	int maxHours;
	public:
		MyClock(int maxHours, int initial, int goal);
		virtual bool isGoal(int) const;
		virtual vector<int> next(int);
		virtual int getInitial() const;
		virtual string parseConfig(int) const;
};

#endif
