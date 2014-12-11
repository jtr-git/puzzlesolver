#include "myvclock.h"
#include "solver.h"
#include<stdlib.h>
using namespace std;

int main(int argc, char ** argv)
{
	if(argc<5)
	{
		cout<<"Usage : ./clock total current correct step1 step2..."<<endl;
		return 1;	
	}
	
	vector<int> steps;

	for(int i = 4; i < argc; i++)
	{
		steps.push_back(atoi(argv[i]));
	}
		
	//initialize the clock puzzle object
	MyVClock vclock(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), steps);
	//pass the puzzle to a solver object
	Solver<int, int> solver(vclock);
	//call the solve function to get a solution
	cout<<"Solving"<<endl;
	cout<<solver.solve()<<endl;
	return 0;
}
