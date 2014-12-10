#include<vector>
#include<iostream>
#include<string>
#include "puzzle.h"

#ifndef MYWATER_H
#define MYWATER_H

using namespace std;

class MyWater : public Puzzle<vector<int>,int >
{
	const vector<int> capacity;
	public:
		MyWater(int goal, vector<int> initial);
		virtual bool isGoal(vector<int>) const;
		virtual vector<vector<int> > next(vector<int>);
		virtual vector<int> getInitial() const;
		virtual string print(const vector<int> &) const;
};

#endif
