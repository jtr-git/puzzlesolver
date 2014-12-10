#include<iostream>
#include<sstream>
#include "mywater.h"

using namespace std;

MyWater::MyWater(int goal, vector<int> capacity): Puzzle(goal), capacity(capacity)
{
	//initial(capacity.size(), 0);
	for(vector<int>::iterator iter = capacity.begin(); iter!=capacity.end(); ++ iter)
		initial.push_back(0);	
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
	//generate next possible configurations

	vector<int>::const_iterator cap = capacity.begin();		
	for(vector<int>::iterator cur = temp.begin();cap!=capacity.end(), cur!=temp.end(); ++cap, ++cur)
	{
		vector<int>::const_iterator cap2 = capacity.begin() + 1;
		vector<int>::iterator cur2 = temp.begin() + 1;

		//pouring from one jug to another
		for(;cap2!=capacity.end(),cur2!=temp.end();++cap2,++cur2)
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
	//cout<<parseConfig(current)<<"... Generated ..."<<endl;
	//for(vector<vector<int> >::iterator iter =  nextConfig.begin(); iter!=nextConfig.end(); ++iter)
	//{
//		cout<<parseConfig(*iter)<<endl;
//	}
	return nextConfig;
}

vector<int> MyWater::getInitial() const
{
	return initial;
}

string MyWater::print(const vector<int> & current) const
{
	stringstream stream;
	vector<int>::const_iterator cap = capacity.begin();
	vector<int>::const_iterator cur = current.begin();
	for(;cur!=current.end(), cap!=capacity.end(); ++cur, ++cap)
	{
		stream<<*cap<<"("<<*cur<<"), ";
	}
	return stream.str();
}
