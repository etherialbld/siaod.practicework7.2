#pragma once

#include <vector>
#include <queue>
#include <iostream>
#include <string>

class App
{
private:
	std::vector < std::vector <int> > graph;
public:
	void graphInit();
	void primsAlgorithm(std::vector < std::vector <int> > graph);
};

