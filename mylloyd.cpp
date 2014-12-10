#include<iostream>
#include<sstream>
#include<algorithm>
#include "mylloyd.h"

using namespace std;

MyLloyd::MyLloyd(vector<vector<int> > goal, vector<vector<int> > initial): Puzzle(initial,goal)
{
}

bool MyLloyd::isGoal(vector<vector<int> > current) const
{
	if (equal(goal.begin(), goal.end(), current.begin()))
	{
		return true;
	}
	else
	{
		return false;
	}
}
vector<vector<vector<int> > > MyLloyd::next(vector<vector<int> > matrix)
{	
	vector<vector<vector<int> > > nextConfigList;

	for(vector<vector<int> >::const_iterator row = matrix.begin(); row!=matrix.end(); ++row)
	{
		for(vector<int>::const_iterator col = row->begin(); col!=row->end(); ++col)
		//TODO - get next configs	
	}

	return nextConfigList;
}

vector<vector<int> > MyLloyd::getInitial() const
{
	return initial;
}

string MyLloyd::print(const vector<vector<int> > &matrix) const
{
	stringstream stream;
	for(vector<vector<int> >::const_iterator row = matrix.begin(); row!=matrix.end(); ++row)
	{
		for(vector<int>::const_iterator col = row->begin(); col!=row->end(); ++col) 
			stream<<*col<<",";
	}
	stream<<"\n";
	return stream.str();
}
