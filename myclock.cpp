#include<iostream>
#include<sstream>
#include "myclock.h"
using namespace std;

MyClock::MyClock(int initial, int goal) : Puzzle(initial,goal) 
{
}

bool MyClock::isGoal(int current)
{
	return current==this->goal;
}

vector<int> MyClock::next(int current)
{
	vector<int> nextVector;
	nextVector.push_back(current-1);
	nextVector.push_back(current+1);
	return nextVector;
}

int MyClock::getInitial() const
{
	return initial;
}

string MyClock::parseConfig(int a)
{
	stringstream ss;
	ss<<a;
	return ss.str();
}

//ostream& operator<<(ostream& strm, const int &a)
//{
//	strm<<a;
//	return strm;
//}
