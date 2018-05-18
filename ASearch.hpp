/*
File: ASearch.hpp
Description: Namespace function that provides the A*Search algorithm.
Author: Brett Koenig
Contact Info: KoenigBS18@uww.edu
*/

#ifndef ASEARCH_HPP
#define ASEARCH_HPP
#include "Heuristic.h"
#include "Map.h"
#include <vector>
#include <queue>
#include <string>
#include <iostream>
namespace AStarSearch {
	void Search(std::vector<Heuristic>, std::vector<Map>, std::string);
	void print();
}

#endif