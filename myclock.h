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
		virtual bool isGoal(int);
		virtual vector<int> next(int);
		virtual int getInitial();
		virtual string parseConfig(int);
		//friend ostream& operator<<(ostream&, const int&);
};

#endif
