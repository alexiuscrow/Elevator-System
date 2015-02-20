#ifndef BUILDING_H
#define BUILDING_H

#include "floor.h"
#include "elevator.h"
#include <vector>

class Building
{
private:
	unsigned int m_countOfFloors;
	std::string m_nameOfBuilding;
protected:
	std::vector<Floor*> m_floors;
	Elevator* m_elevator;
public:
	Building(std::string nameOfBuilding, unsigned int countOfFloors);
	~Building();
	Floor*& getFloor(int numOfFloor);
	Elevator* getElevator();
	int getCountOfFloors();
	std::string getNameOfBuilding();
};
	

#endif