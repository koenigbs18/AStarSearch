/*
File: Main.cpp
Description: Utilizes the A* Search algorithm provided in ASearch.hpp (namespace AStarSearch) in order to determine
			 the best path between nodes from the text file "map.txt".  Provided are heuristic data for each node
			 in "heuristic.txt".  Does not write to any files, just prints the results.
Author: Brett Koenig
Contact Info: KoenigBS18@uww.edu
*/

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <cstdlib>
#include <Windows.h>
#include "ASearch.hpp"
#include "Heuristic.h"
#include "Map.h"

// Declare Heuristic and Map vectors
std::vector<Heuristic> HeuristicVector;
std::vector<Map> MapVector;

int main() {
	std::ifstream HeuristicData("heuristic.txt"); // Open ifstream to heuristic data file
	std::ifstream MapData("map.txt"); // open ifstream to map data file
	for (std::string line; std::getline(HeuristicData, line); ) { // While there are lines to read, continue
		char temp = ' '; // Declare temporary char for traversing the line
		int count = 0; // Count's the current index while traversing the line
		int delimLocation = 0; // Location of the delimiter to be used in substrings
		while (temp != ',') { // Find the index of the delimiter
			temp = line.at(count); // Traverse individual char's of the line
			count++;
		}
		delimLocation = (count-1);
		/*
		TempH: Substrings to the initial delimiter location and calls atof on the distance to convert to a float.
		*/
		Heuristic tempH(line.substr(0, delimLocation), std::atof(line.substr(delimLocation + 1, line.size() - delimLocation).c_str()));
		HeuristicVector.push_back(tempH); // Add the temporary heuristic to the vector
	}
	HeuristicData.close(); // Close the Heuristic ifstream

	/*
	Same operations as HeuristicData with a few exceptions, properly commented
	*/
	for (std::string line; std::getline(MapData, line); ) {
		char temp = ' ';
		int count = 0;
		int firstDelimLocation = 0;
		int secondDelimLocation = 0;
		while (temp != ',') {
			temp = line.at(count);
			count++;
		}
		firstDelimLocation = (count - 1);
		temp = ' ';
		count++;
		while (temp != ',') {
			temp = line.at(count);
			count++;
		}
		secondDelimLocation = (count - 1);
		std::string source = line.substr(0, firstDelimLocation);
		/*
		tempM: Performs substrings on the first two delimiters, then converts the distance to a float
		*/
		Map tempM(line.substr(0, firstDelimLocation), line.substr(firstDelimLocation + 1, secondDelimLocation - (source.size() + 1)), std::atof(line.substr(secondDelimLocation + 1, line.size() - secondDelimLocation).c_str()));
		MapVector.push_back(tempM);
	}
	MapData.close(); // Close the MapData ifstream

	AStarSearch::Search(HeuristicVector, MapVector, "William Pond Halloween Party"); // Call the Search function in namespace AStarSearch

	return 0;
}
