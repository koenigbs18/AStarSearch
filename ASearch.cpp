/*
File: Heuristic.cpp
Description: Implements the A* Search algorithm for the AStarSearch namespace.  
			 Additionally provides a printing function which calculates the final path cost.
Author: Brett Koenig
Contact Info: KoenigBS18@uww.edu
*/

#include "ASearch.hpp"

namespace AStarSearch {

	//Declare our variables and queue.
	std::queue<Map> bestPath;
	float totalDistance = 0;


	/*
	Performs A* search on the given HeuristicVector and MapVector.
	*/
	void Search(std::vector<Heuristic> HeuristicVector, std::vector<Map> MapVector, std::string FinalNodeName) {
		float fValue = 100.0; // f value is the actual cost + straight line cost (heuristic)
		int lowestFValueIndex = 0; // Index of the lowest f value on the map
			for (int i = 0; i < 3; i++) { // Checking first three paths for the lowest f value, note this is because the first three points of data in the MapVector are consistent
				for (int j = 0; j < HeuristicVector.size(); j++) { // Looping through the heuristic vector
					if (HeuristicVector.at(j).getLocation() == MapVector.at(i).getDestination()) { // Finding corresponding straight line value in the heuristic vector
						if ((HeuristicVector.at(j).getDistance() + MapVector.at(i).getDistance()) < fValue) { // If the F value is lower than the current, replace it as the lowest
							fValue = HeuristicVector.at(j).getDistance() + MapVector.at(i).getDistance();
							lowestFValueIndex = i; // Index corresponds to lowest F value of the first three map index's
							break;
						}
					}
				}
			}
			bestPath.push(MapVector.at(lowestFValueIndex)); // Push the lowest F value path onto the queue
			totalDistance += MapVector.at(lowestFValueIndex).getDistance(); // Add the distance of that path
			for (int i = 3; i < MapVector.size(); i++) { // Checks from the third path to the end of the MapVector's size, this is because the rest of the data is inconsistent (ex. we need to look back)
				if (MapVector.at(i).getSource() == MapVector.at(lowestFValueIndex).getDestination()) { // On our second iteration, we say if the current source in the loop is the previous lowest F value's destination, 
																									   // we found the next path
					if (MapVector.at(i).getDestination() == FinalNodeName) { // If the the next path's destination is the party, we are done
						totalDistance += MapVector.at(i).getDistance(); // Increment final distance
						bestPath.push(MapVector.at(i)); // Push the final destination onto the path queue
						print(); // print our final path
						return;
					}
					/*
					The following for loop operations and the following queue pushes, and distance summations are 
					the same as the above operations, needing no additional comments.  The only thing that changes is
					when MapVector is traversed, we continue the for loop starting at the previous for loop's start + 1
					*/
					for (int j = 0; j < HeuristicVector.size(); j++) {
						if (HeuristicVector.at(j).getLocation() == MapVector.at(i).getDestination()) {
							if ((HeuristicVector.at(j).getDistance() + MapVector.at(i).getDistance()) < fValue) {
								fValue = HeuristicVector.at(j).getDistance() + MapVector.at(i).getDistance();
								lowestFValueIndex = i;
								break;
							}
						}
					}
				}
			}
			bestPath.push(MapVector.at(lowestFValueIndex));
			totalDistance += MapVector.at(lowestFValueIndex).getDistance();
			for (int i = 6; i < MapVector.size(); i++) {
				if (MapVector.at(i).getSource() == MapVector.at(lowestFValueIndex).getDestination()) {
					if (MapVector.at(i).getDestination() == FinalNodeName) {
						totalDistance += MapVector.at(i).getDistance();
						bestPath.push(MapVector.at(i));
						print();
						return;
					}
					for (int j = 0; j < HeuristicVector.size(); j++) {
						if (HeuristicVector.at(j).getLocation() == MapVector.at(i).getDestination()) {
							if ((HeuristicVector.at(j).getDistance() + MapVector.at(i).getDistance()) < fValue) {
								fValue = HeuristicVector.at(j).getDistance() + MapVector.at(i).getDistance();
								lowestFValueIndex = i;
								break;
							}
						}
					}
				}
			}
			bestPath.push(MapVector.at(lowestFValueIndex));
			totalDistance += MapVector.at(lowestFValueIndex).getDistance();
			for (int i = 7; i < MapVector.size(); i++) {
				if (MapVector.at(i).getSource() == MapVector.at(lowestFValueIndex).getDestination()) {
					if (MapVector.at(i).getDestination() == FinalNodeName) {
						totalDistance += MapVector.at(i).getDistance();
						bestPath.push(MapVector.at(i));
						print();
						return;
					}
					for (int j = 0; j < HeuristicVector.size(); j++) {
						if (HeuristicVector.at(j).getLocation() == MapVector.at(i).getDestination()) {
							if ((HeuristicVector.at(j).getDistance() + MapVector.at(i).getDistance()) < fValue) {
								fValue = HeuristicVector.at(j).getDistance() + MapVector.at(i).getDistance();
								lowestFValueIndex = i;
								break;
							}
						}
					}
				}
			}
			bestPath.push(MapVector.at(lowestFValueIndex));
			totalDistance += MapVector.at(lowestFValueIndex).getDistance();
			for (int i = 9; i < MapVector.size(); i++) {
				if (MapVector.at(i).getSource() == MapVector.at(lowestFValueIndex).getDestination()) {
					if (MapVector.at(i).getDestination() == FinalNodeName) {
						totalDistance += MapVector.at(i).getDistance();
						bestPath.push(MapVector.at(i));
						print();
						return;
					}
					for (int j = 0; j < HeuristicVector.size(); j++) {
						if (HeuristicVector.at(j).getLocation() == MapVector.at(i).getDestination()) {
							if ((HeuristicVector.at(j).getDistance() + MapVector.at(i).getDistance()) < fValue) {
								fValue = HeuristicVector.at(j).getDistance() + MapVector.at(i).getDistance();
								lowestFValueIndex = i;
								break;
							}
						}
					}
				}
			}
			bestPath.push(MapVector.at(lowestFValueIndex));
			totalDistance += MapVector.at(lowestFValueIndex).getDistance();
			for (int i = 10; i < MapVector.size(); i++) {
				if (MapVector.at(i).getSource() == MapVector.at(lowestFValueIndex).getDestination()) {
					if (MapVector.at(i).getDestination() == FinalNodeName) {
						totalDistance += MapVector.at(i).getDistance();
						bestPath.push(MapVector.at(i));
						print();
						return;
					}
					for (int j = 0; j < HeuristicVector.size(); j++) {
						if (HeuristicVector.at(j).getLocation() == MapVector.at(i).getDestination()) {
							if ((HeuristicVector.at(j).getDistance() + MapVector.at(i).getDistance()) < fValue) {
								fValue = HeuristicVector.at(j).getDistance() + MapVector.at(i).getDistance();
								lowestFValueIndex = i;
								break;
							}
						}
					}
				}
			}
			bestPath.push(MapVector.at(lowestFValueIndex));
			totalDistance += MapVector.at(lowestFValueIndex).getDistance();
	}

	/*
	This operation prints the final calculated path.
	*/
	void print() {
		int size = bestPath.size(); // Set the size beforehand as this function will 
									// not be reliable following the pop operation
		int count = 0; // counter for the while loop
		std::cout << "Best Path" << "\n";
		std::cout << "GHS";
		while (count < size) { // Prints while there are still paths in the queue
			std::cout << " --> " << bestPath.front().getDestination();
			bestPath.pop();
			count++;
		}
		std::cout << "\nDistance: " << totalDistance << "\n";
	}

}
