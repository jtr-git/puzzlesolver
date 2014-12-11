#include "myclock.h"
#include "solver.h"
#include<stdlib.h>
using namespace std;

int main(int argc, char ** argv)
{
	if(argc!=4)
	{
		cout<<"Usage : ./clock total current correct"<<endl;
		return 1;	
	}
	
	//initialize the clock puzzle object
	MyClock clock(atoi(argv[1]),atoi(argv[2]), atoi(argv[3]));
	//pass the puzzle to a solver object
	Solver<int, int> solver(clock);
	//call the solve function to get a solution
	cout<<"Solving"<<endl;
	cout<<solver.solve()<<endl;
	return 0;
}
