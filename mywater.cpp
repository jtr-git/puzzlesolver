#include<iostream>
#include<sstream>
#include "mywater.h"

using namespace std;

MyWater::MyWater(int goal, vector<int> initial): Puzzle(goal), capacity(initial)
{
}

bool MyWater::isGoal(vector<int> current) const
{
	for(vector<int>::iterator iter = current.begin(); iter!=current.end(); ++iter)
	{
		if(*iter==goal)
		{
			return true;
		}
	}
	return false;
}

vector<vector<int> > MyWater::next(vector<int> current)
{	
	vector<int> temp = current;
	if(!isGoal(temp))
	{
		//generate next possible configurations

		vector<int>::const_iterator cap = initial.begin();		
		for(vector<int>::iterator cur = temp.begin();cap!=initial.end(), cur!=temp.end(); ++cap, ++cur)
		{
			vector<int>::const_iterator cap2 = initial.begin();
			vector<int>::iterator cur2 = temp.begin();

			//pouring from one jug to another
			for(;cap2=initial.end(),cur2!=temp.end();++cap2,++cur2)
			{
				//first jug to second
				if((*cur2 + * cur)  == *cap2)
				{
					*cur = 0;
					*cur2 = *cap2;
				}
				else if(*cur2 + *cur > *cap2)
				{
					//partial fill
					*cur = *cur - (*cap2 - *cur2);
					*cur2 = *cap2;
					nextConfig.push_back(temp);
					temp = current;
				}
				else
				{
					//full transfer
					*cur2 = *cur2 + *cur;
					*cur = 0;
					nextConfig.push_back(temp);
					temp = current;

				}

				//second jug to first
				if((*cur + *cur2) == *cap)
				{
					*cur = *cap;
					*cur2 = 0;
				}
				else if(*cur + *cur2 > *cap)
				{
					//partial fill
					*cur2 = *cur2 - (*cap - *cur);
					*cur = *cap;
					nextConfig.push_back(temp);
					temp = current;
				}
				else
				{
					//full transfer
					*cur = *cur + *cur2;
					*cur2 = 0;
					nextConfig.push_back(temp);
					temp = current;
				}
			}

			//empty jug
			*cur = 0;
			nextConfig.push_back(temp);
			temp = current;

			//fill jug
			*cur = *cap;
			nextConfig.push_back(temp);
			temp = current;
		}
	}

	else
	{
		nextConfig.clear();
	}

	return nextConfig;
}

vector<int> MyWater::getInitial() const
{
	return initial;
}

string MyWater::parseConfig(vector<int> current) const
{
	stringstream stream;
	vector<int>::const_iterator cap = initial.begin();
	for(vector<int>::iterator iter = current.begin(); iter!=current.end(), cap!=initial.end(); ++iter, ++cap)
	{
		stream<<*cap<<"("<<*iter<<"), ";
	}
	return stream.str();
}
