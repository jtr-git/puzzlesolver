#include<map>
#include<vector>
#include "puzzle.h"

using namespace std;

template<class Config>
class Solver
{
	//initial configuration
	const Config initial;
	//pointer to a puzzle
	const Puzzle<Config> * const puzzle;
	//solution structure
	vector<vector<Config> > solution;
	//internal data structure for solving
	map<Config,vector<Config> > backReferer;
	vector<Config> queue;
	public :
	Solver(const Puzzle<Config> &puzzle): puzzle(&puzzle), initial(puzzle.getInitial())
	{
	}
	void solve();
	void print();
};

//function to solve a general puzzle
	template<class Config>
void Solver<Config>::solve()
{

	//traverse through the map and generate multiple solutions
	for(typename map<Config, vector<Config> >::iterator iter = backReferer.begin(); iter!= backReferer.end(); ++iter)
	{
		//for all vecto<Config> entries in backReferer, add them to different vectors in solution variable	
		
	}
}

//function to print the solution
	template<class Config>
void Solver<Config>::print()
{
	for(typename vector<vector<Config> >::iterator iter = solution.begin(); iter!=solution.end(); ++iter )
	{
		for(typename vector<Config>::iterator iter2 = iter->begin(); iter2!=iter->end();++iter2)
		{
			cout<<*iter2;
		}
	}
}
