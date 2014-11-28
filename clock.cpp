#include "myclock.h"
#include "solver.h"

using namespace std;

int main(int argc, char ** argv)
{
	//initialize the clock puzzle object
	MyClock clock(5,12);
	//pass the puzzle to a solver object
	Solver<int> solver(clock);
	//call the solve function to get a solution
	solver.solve();
	//print solution
	solver.print();
}
