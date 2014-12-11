#include "mylloyd.h"
#include "solver.h"

#include<stdlib.h>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

static int noOfRows = 0;
static int noOfCols = 0;

bool dimensionLine = true;
bool onedone = false;

int main(int argc, char ** argv)
{
	vector<vector<string> > initial;
	vector<vector<string> > goal;
	vector<string> parseToVector(string);
	vector<string> parseFromCmdLine(string);
	if(argc!=3)
	{
		cout<<"Usage 1 : ./lloyd file1 file2"<<endl;
		cout<<"Usage 2 : ./lloyd - -"<<endl;
		return 1;	
	}

	//if files are to be read
	else if(*argv[1]!='-' && *argv[2]!='-')
	{
		string inputFileString = argv[1];
		string outputFileString = argv[2];

		ifstream inputFile(argv[1],ifstream::in);
		string rowString;
		while(getline(inputFile, rowString))
		{
			if(rowString.length()!=0)
			{
				if(!dimensionLine && noOfRows > 0)
				{
					if(onedone)
					{
						goal.push_back(parseToVector(rowString));
					}
					else
					{
						initial.push_back(parseToVector(rowString));
					}
					noOfRows--;
				}
				else
				{
					parseToVector(rowString);
				}
			}
			else
			{
				onedone=true;
				//ignore empty line
				dimensionLine = true;
			}
		}
	}

	//read from command line
	else
	{
		string rowString;
		string opt;
		cout<<"Enter initial matrix row by row"<<endl;
		while(opt!="n")
		{	
			getline(cin,rowString);
			initial.push_back(parseFromCmdLine(rowString));
			cout<<"Enter more (y/n)?"<<endl;
			getline(cin, opt);
		}
		opt = "y";
		cout<<"Enter goal matrix row by row"<<endl;
		while(opt!="n")
		{
			getline(cin,rowString);
			goal.push_back(parseFromCmdLine(rowString));
			cout<<"Enter more (y/n)?"<<endl;
			getline(cin, opt);
		}
	}

	MyLloyd lloyd(initial, goal);
	Solver< vector<vector<string> >, vector<vector<string> > > solver(lloyd);

	//call the solve function to get a solution
	cout<<"Solving lloyd puzzle"<<endl;
	if(*argv[2]!='-')
	{
		//write output to file
		ofstream outFile(argv[2]);
		outFile<<solver.solve();
		outFile.close();
	}
	else
	{
		cout<<solver.solve()<<endl;
	}
	return 0;
}

vector<string> parseFromCmdLine(string input)
{
	string column;
	vector<string> row;
	istringstream stream(input);
	while(getline(stream,column,' '))
	{
		row.push_back(column);
	}
	return row;
}

vector<string> parseToVector(string input)
{
	istringstream stream(input);
	vector<string> row;
	string col;
	//split string
	while(getline(stream,col,' '))
	{
		if(dimensionLine)
		{
			if(noOfRows == 0)
			{
				noOfRows = atoi(col.c_str());
			}
			else
			{
				noOfCols = atoi(col.c_str());
				dimensionLine = false;
			}
		}

		else
		{
			//add to a vector before returning
			row.push_back(col);
			noOfCols--;
		}
	}
	return row;
}
