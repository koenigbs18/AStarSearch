/*
File: Map.h
Description: Map class details connections between two nodes in string format, along with their given travel cost/distances.
Author: Brett Koenig
Contact Info: KoenigBS18@uww.edu
*/
#ifndef MAP_H
#define MAP_H
#include <string>
class Map {
public:
	Map(std::string, std::string, float);
	std::string getSource();
	std::string getDestination();
	float getDistance();
private:
	std::string source, destination;
	float distance;
};

#endif