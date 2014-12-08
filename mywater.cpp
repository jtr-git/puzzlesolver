#include<iostream>
#include<sstream>
#include "mywater.h"

using namespace std;

MyWater::MyWater(int goal, vector<int> initial): Puzzle(initial,goal)
{
	for(vector<int>::iterator iter = initial.begin(); iter!=initial.end(); ++iter)
		capacity.push_back(*iter);
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
	bool reached = isGoal(current);
	vector<int> original = current;
	if(!reached)
	{
		//generate next possible configurations
		 
		
		for(vector<int>::iterator cap = capacity.begin(), cur = current.begin();cap!=capacity.end(), cur!=current.begin(); ++cap, ++cur)
		{
			vector<int>::iterator cap2 = cap;
			++cap2;
			vector<int>::iterator cur2 = cur;
			++cur;

			for(;cap2=capacity.end(),cur2!=current.end();++cap2,++cur2)
			{
				if(*cap2>(*cap))
				{
					if(*cur2 + *cur > *cap2)
					{
						*cur = *cap2 - *cur2;
						*cur2 = *cap2;
						nextConfig.push_back(current);
						current = original;
					}
					else
					{
						*cur2 = *cur2 + *cur;
						*cur = 0;
						nextConfig.push_back(current);
						current = original;
					}
				}
				else
				{
					if(*cur + *cur2 > *cap)
					{
						*cur2 = *cap - *cur;
						*cur = *cap;
					}
					else
					{
						*cur = *cur + *cur2;
						*cur2 = 0;
						nextConfig.push_back(current);
						current = original;
					}
				}
			}

			//empty jug
			*cur = 0;
			nextConfig.push_back(current);
			current = original;

			//fill jug
			*cur = *cap;
			nextConfig.push_back(current);
			current = original;
		}
	}

	else
	{
		nextConfig.clear();
	}

}

vector<int> MyWater::getInitial() const
{
	return initial;
}

string MyWater::parseConfig(vector<int> config) const
{
	stringstream stream;
	for(vector<int>::iterator iter = config.begin(); iter!=config.end(); ++iter)
	{
		stream<<*iter<<",";
	}
	return stream.str();
}
