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
		const Config initial;
		const Config goal;

		Puzzle(Config initial, Config goal) : initial(initial), goal(goal) {}
		virtual bool isGoal(Config) const = 0;
		virtual vector<Config> next(Config) const = 0;
		virtual Config getInitial() const = 0;
		virtual string parseConfig(Config) const= 0;
};

#endif
