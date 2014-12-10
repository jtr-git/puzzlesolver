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

	vector<int> row1;
	vector<int> row2;
	vector<int> row2Other;
	vector<int> row3;
	vector<int> row3Other;

	row1.push_back(1);
	row1.push_back(2);
	row1.push_back(3);

	row2.push_back(4);
	row2.push_back(5);
	row2.push_back(6);

	row3.push_back(7);
	row3.push_back(8);
	row3.push_back(0);

	row2Other.push_back(4);
	row2Other.push_back(5);
	row2Other.push_back(0);

	row3Other.push_back(7);
	row3Other.push_back(8);
	row3Other.push_back(6);

	initial.push_back(row1);
	initial.push_back(row2Other);
	initial.push_back(row3Other);

	goal.push_back(row1);
	goal.push_back(row2);
	goal.push_back(row3);

	MyLloyd lloyd(initial, goal);

	Solver< vector<vector<int> >, vector<vector<int> > > solver(lloyd);

	//call the solve function to get a solution
	cout<<"Solving lloyd puzzle"<<endl;
	solver.solve();

	return 0;
}
