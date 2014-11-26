#include<map>
#include "puzzle.h"
using namespace std;
template<class Config>
class Solver
{
	Config initial;
	const Puzzle<Config> * const puzzle;
	//solution structure
	map<int,Config> queue;
	public :
	Solver(const Puzzle<Config> &puzzle): puzzle(&puzzle)
	{
	}
};
