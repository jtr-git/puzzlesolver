#include "mylloyd.h"
#include "solver.h"
#include<stdlib.h>
#include<string>

using namespace std;

int main(int argc, char ** argv)
{
	if(argc!=3)
	{
		cout<<"Usage 1 : ./lloyd file1 file2"<<endl;
		cout<<"Usage 2 : ./lloyd - -"<<endl;
		return 1;	
	}
	
	string inputFile = argv[1];
	string outputFile = argv[2];

	
	//parse initial file to get output
		
	//initialize the water puzzle object
	vector<vector<int> > initial;
	vector<vector<int> > goal;
	MyLloyd lloyd(initial, goal);

	Solver< vector<vector<int> >, vector<vector<int> > > solver(lloyd);
	
	//call the solve function to get a solution
	cout<<"Solving lloyd puzzle"<<endl;
	solver.solve();
	
	return 0;
}
