#include<iostream>
#include<string>
#include<sstream>
#include "myclock.h"
using namespace std;

MyClock::MyClock(int maxHours, int initial, int goal): Puzzle(initial%maxHours, goal%maxHours), maxHours(maxHours)
{
}

bool MyClock::isGoal(int current) const
{
	return current==this->goal;
}

vector<int> MyClock::next(int current)
{
	vector<int> nextVector;
	if(current>1)
	{
		nextVector.push_back(current-1);
	}
	else
	{	
		nextVector.push_back(current-1+maxHours);
	}
	nextVector.push_back(current+1);
	return nextVector;
}

int MyClock::getInitial() const
{
	return initial;
}

string MyClock::print(const int& a) const
{
	stringstream s;
	s<<a;
	return s.str();
}
