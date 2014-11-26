#include "myclock.h"
#include "solver.h"

using namespace std;

int main(int argc, char ** argv)
{
	MyClock clock(5,12);
	cout<<clock.isGoal(11)<<endl;
	Solver<int> solver(clock);
}
