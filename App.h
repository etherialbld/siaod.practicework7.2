#pragma once

#include <vector>
#include <queue>
#include <iostream>
#include <string>

class App
{
public:
	App();
	std::vector < std::vector <int> > graphInit();
	void primsAlgorithm(std::vector < std::vector <int> > graph);
};

