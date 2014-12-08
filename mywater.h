#include<vector>
#include<iostream>
#include<string>
#include "puzzle.h"

#ifndef MYWATER_H
#define MYWATER_H

using namespace std;

class Jug
{
	int max_cap;
	int current;	
	public:
	Jug(int max_cap) : max_cap(max_cap), current(0)
	{}
};

class MyWater : public Puzzle<vector<int>,int >
{
	vector<int> capacity;
	public:
		MyWater(int goal, vector<int> initial);
		virtual bool isGoal(vector<int>) const;
		virtual vector<vector<int> > next(vector<int>);
		virtual vector<int> getInitial() const;
		virtual string parseConfig(vector<int>) const;
};

#endif
