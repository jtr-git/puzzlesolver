#include<vector>
#include<iostream>
#include<string>
#include "puzzle.h"

#ifndef MYLLOYD_H
#define MYLLOYD_H

using namespace std;

class MyLloyd : public Puzzle<vector<vector<string> >, vector<vector<string> > >
{
	public:
		MyLloyd(vector<vector<string> >, vector<vector<string> >);	
		virtual bool isGoal(vector<vector<string> >) const;
		virtual vector<vector<vector<string> > > next(vector<vector<string> >);
		virtual vector<vector<string> > getInitial() const;
		string print(const vector<vector<string> >&) const;
};

#endif
