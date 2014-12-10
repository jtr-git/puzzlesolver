#include<iostream>
#include<sstream>
#include<algorithm>
#include "mylloyd.h"

using namespace std;

MyLloyd::MyLloyd(vector<vector<int> > initial, vector<vector<int> > goal): Puzzle(initial,goal)
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
vector<vector<vector<int> > > MyLloyd::next(const vector<vector<int> > current)
{	
	vector<vector<vector<int> > > nextConfigList;

	vector<vector<int> > matrix = current; 
	int temp = -1;
	vector<vector<int> >::iterator tempRow;
	vector<int>::iterator tempCol;
	for(vector<vector<int> >::iterator row = matrix.begin(); row!=matrix.end(); ++row)
	{
		for(vector<int>::iterator col = row->begin(); col!=row->end(); ++col)
			if(*col==0)
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
					temp = -1;
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
					temp = -1;
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
					temp = -1;
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

					temp = -1;

				}
			}
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
		stream<<endl;
	}
	
	return stream.str();
}
