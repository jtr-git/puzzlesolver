#include<map>
#include<vector>
#include<deque>
#include "puzzle.h"

using namespace std;

template<class Config,class Goal>
class Solver
{	
	Puzzle<Config, Goal> * const puzzle;
	const Config initial;
	map<Config,Config> backReferer;
	public :
	Solver(Puzzle<Config, Goal> &puzzle): puzzle(&puzzle), initial(puzzle.getInitial())
	{
	}
	string solve();
	string print(Config, bool);
};

	template<class Config, class Goal>
string Solver<Config, Goal>::solve()
{
	Config goalConfig;
	bool solvable = false;
	vector<Config> nextConfigs;
	deque<Config> myQueue;
	myQueue.push_back(initial);
	backReferer.insert(pair<Config,Config>(initial, initial));

	//iterate the queue
	for(typename deque<Config>::iterator iter = myQueue.begin(); iter!=myQueue.end() && !puzzle->isGoal(*iter); ++iter)
	{
		//for every element in the queue, get next configurations
		nextConfigs = puzzle->next(*iter);
		//iterate next configurations
		for(typename vector<Config>::iterator iter2 = nextConfigs.begin(); iter2!=nextConfigs.end(); ++iter2)
		{
			//if goal found
			if(puzzle->isGoal(*iter2))
			{
				solvable=true;
				goalConfig = *iter2;
				backReferer.insert(pair<Config,Config>(*iter2, *iter));
				return print(goalConfig, solvable);
			}

			//if configuration has not been seen before and is not goal
			else if(backReferer.find(*iter2)==backReferer.end())
			{
				//add to queue
				myQueue.push_back(*iter2);
				//add a reference from the config to previous
				backReferer.insert(pair<Config,Config>(*iter2,*iter));
			}
			else
			{
				//skip adding
			}
		}
		myQueue.pop_front();
	}
	return "Error : undefined behavior";
}

	template<class Config, class Goal>
string Solver<Config, Goal>::print(Config goalConfig, bool solvable)
{
	string output;
	if(!solvable)
	{
		output = "No solution";
		return output;
	}
	else
	{
		output = "Solution : \n";
		Config temp = goalConfig;
		while(temp!=puzzle->getInitial())
		{
			output = output + puzzle->print(temp) + "\n";
			temp = backReferer[temp];
		}
		//print initial
		output = output + puzzle->print(temp) + "\n";
	}
	return output;
}
