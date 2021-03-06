#include "mywater.h"
#include "solver.h"
#include<stdlib.h>

using namespace std;

int main(int argc, char ** argv)
{
	if(argc<3)
	{
		cout<<"Usage : ./water quantity container1 container2..."<<endl;
		return 1;	
	}
	int quantity = atoi(argv[1]);
	vector<int> jugs;
	for(int i = 2; i < argc; ++i )
	{
		jugs.push_back(atoi(argv[i]));
	}

	//initialize the water puzzle object
	MyWater water(quantity, jugs);

	Solver<vector<int>, int> solver(water);
	//call the solve function to get a solution
	cout<<"Solving water puzzle"<<endl;
	cout<<solver.solve()<<endl;
	return 0;
}
