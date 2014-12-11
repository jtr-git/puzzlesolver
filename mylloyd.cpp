#include<iostream>
#include<sstream>
#include<algorithm>
#include "mylloyd.h"

using namespace std;

MyLloyd::MyLloyd(vector<vector<string> > initial, vector<vector<string> > goal): Puzzle(initial,goal)
{
}

bool MyLloyd::isGoal(vector<vector<string> > current) const
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
vector<vector<vector<string> > > MyLloyd::next(const vector<vector<string> > current)
{	
	vector<vector<vector<string> > > nextConfigList;

	vector<vector<string> > matrix = current; 
	string temp;
	vector<vector<string> >::iterator tempRow;
	vector<string>::iterator tempCol;
	for(vector<vector<string> >::iterator row = matrix.begin(); row!=matrix.end(); ++row)
	{
		for(vector<string>::iterator col = row->begin(); col!=row->end(); ++col)
			if(*col==".")
			{
				//move right
				if((col+1) != row->end())
				{	
					tempCol = col+1;
					temp = *tempCol;
					*tempCol = *col;
					*col = temp;	
					nextConfigList.push_back(matrix);
					matrix = current;
				}
				//move left
				if(col != row->begin())
				{
					tempCol = col-1;
					temp = *tempCol;
					*tempCol = *col;
					*col = temp;
					nextConfigList.push_back(matrix);
					matrix = current;
				}
				//move down
				if((row+1)!=matrix.end())
				{
					tempRow = row+1;
					tempCol = (tempRow->begin() + (col - row->begin()));
					temp = *col;
					*col = *tempCol;
					*tempCol = temp;
					nextConfigList.push_back(matrix);
					matrix = current;
				}
				//move up
				if(row!=matrix.begin())
				{
					tempRow = row-1;
					tempCol = (tempRow->begin() + (col - row->begin()));
					temp = *col;
					*col = *tempCol;
					*tempCol = temp;
					nextConfigList.push_back(matrix);
					matrix = current;
				}
			}
	}

	return nextConfigList;
}

vector<vector<string> > MyLloyd::getInitial() const
{
	return initial;
}

string MyLloyd::print(const vector<vector<string> > &matrix) const
{
	stringstream stream;
	for(vector<vector<string> >::const_iterator row = matrix.begin(); row!=matrix.end(); ++row)
	{
		for(vector<string>::const_iterator col = row->begin(); col!=row->end(); ++col) 
			stream<<*col<<",";
		stream<<endl;
	}
	
	return stream.str();
}
