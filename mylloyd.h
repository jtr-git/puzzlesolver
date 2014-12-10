#include<vector>
#include<iostream>
#include<string>
#include "puzzle.h"

#ifndef MYLLOYD_H
#define MYLLOYD_H

using namespace std;

class MyLloyd : public Puzzle<vector<vector<int> >, vector<vector<int> > >
{
	public:
		MyLloyd(vector<vector<int> >, vector<vector<int> >);	
		virtual bool isGoal(vector<vector<int> >) const;
		virtual vector<vector<vector<int> > > next(vector<vector<int> >);
		virtual vector<vector<int> > getInitial() const;
		string print(const vector<vector<int> >&) const;
};

#endif
