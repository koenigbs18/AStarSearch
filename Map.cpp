/*
File: Map.cpp
Description: Implements functionality for the Map, including initialization and simple get functions.
Author: Brett Koenig
Contact Info: KoenigBS18@uww.edu
*/
#include <string>
#include "Map.h"

Map::Map(std::string src, std::string dest, float dist) : source(src), destination(dest), distance(dist) {

}

std::string Map::getSource() {
	return source;
}

std::string Map::getDestination() {
	return destination;
}

float Map::getDistance() {
	return distance;
}