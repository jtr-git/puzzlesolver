#include<map>
#include<vector>
#include<deque>
#include "puzzle.h"

using namespace std;

template<class Config,class Goal>
class Solver
{
	const Config initial;
	Puzzle<Config, Goal> * const puzzle;
	map<Config,Config> backReferer;
	public :
	Solver(Puzzle<Config, Goal> &puzzle): puzzle(&puzzle), initial(puzzle.getInitial())
	{
	}
	void solve();
	void print();
};

	template<class Config, class Goal>
void Solver<Config, Goal>::solve()
{
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
			//if configuration has not been seen before
			if(backReferer.find(*iter2)==backReferer.end())
			{
				//add to queue
				myQueue.push_back(*iter2);
				//add a reference from the config to previous
				backReferer.insert(pair<Config,Config>(*iter2,*iter));
				if(puzzle->isGoal(*iter2))
					return;
			}
		}
		myQueue.pop_front();
	}
}

	template<class Config, class Goal>
void Solver<Config, Goal>::print()
{
	Config temp = backReferer.rbegin()->first;
	while(temp!=puzzle->getInitial())
	{
		cout<<puzzle->parseConfig(temp)<<endl;
		temp = backReferer[temp];
	}
	//print initial
	cout<<puzzle->parseConfig(temp)<<endl;
}
