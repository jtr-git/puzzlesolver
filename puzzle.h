#ifndef PUZZLE_H
#define PUZZLE_H

#include<iostream>
#include<vector>
#include<string>

using namespace std;

template<class Config>
class Puzzle
{ 
	public: 
		Config initial;
		Config goal;
		Config current;

		Puzzle(Config initial, Config goal) : initial(initial), current(initial), goal(goal)
	{}

		virtual bool isGoal(Config) = 0;
		virtual vector<Config> next(Config) = 0;
		virtual Config getInitial() = 0;
		virtual string parseConfig(Config) = 0;
};

#endif
