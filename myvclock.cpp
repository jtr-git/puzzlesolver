#include<iostream>
#include<string>
#include<sstream>
#include "myvclock.h"
using namespace std;

MyVClock::MyVClock(int maxHours, int initial, int goal, vector<int> steps): Puzzle(initial%maxHours, goal%maxHours), maxHours(maxHours), steps(steps)
{
}

bool MyVClock::isGoal(int current) const
{
	return current==this->goal;
}

vector<int> MyVClock::next(int current)
{
	vector<int> nextVector;
	for(vector<int>::iterator step = steps.begin(); step != steps.end(); ++step)
	{
			nextVector.push_back((current + *step + maxHours)%maxHours);
	}
	return nextVector;
}

int MyVClock::getInitial() const
{
	return initial;
}

string MyVClock::print(const int& a) const
{
	stringstream s;
	s<<a;
	return s.str();
}
