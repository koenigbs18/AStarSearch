/*
File: Heuristic.cpp
Description: Implements features for the Heuristic class, including initialization and get functions.
Author: Brett Koenig
Contact Info: KoenigBS18@uww.edu
*/

#include <string>
#include <iostream>
#include <fstream>
#include "Heuristic.h"

// Node name, distance to the node
Heuristic::Heuristic(std::string loc, float dist) : location(loc), straightLineDistance(dist) {
}

std::string Heuristic::getLocation() {
	return location;
}

float Heuristic::getDistance() {
	return straightLineDistance;
}