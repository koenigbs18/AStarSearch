/*
File: Heuristic.h
Description: Heuristic class assigns nodes with a heuristic cost in order to determine best path.
Author: Brett Koenig
Contact Info: KoenigBS18@uww.edu
*/

#ifndef HEURISTIC_H
#define HEURISTIC_H
#include <string>
class Heuristic {
public:
	Heuristic(std::string, float);
	std::string getLocation();
	float getDistance();
private:
	std::string location;
	float straightLineDistance;
};

#endif