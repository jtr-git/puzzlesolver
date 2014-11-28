#include<vector>
#include<iostream>
#include<string>
#include "puzzle.h"
#ifndef MYCLOCK_H
#define MYCLOCK_H
using namespace std;
class MyClock : public Puzzle<int>
{
	public:
		MyClock(int initial, int goal);
		virtual bool isGoal(int) const;
		virtual vector<int> next(int) const;
		virtual int getInitial() const;
		virtual string parseConfig(int) const;
		//friend ostream& operator<<(ostream&, const int&);
};

#endif
