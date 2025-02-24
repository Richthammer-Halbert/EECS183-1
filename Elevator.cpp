/*
 * Copyright 2023 University of Michigan EECS183
 *
 * Elevator.cpp
 * Project UID 848fee0125dbb5eb53ed294f20dbef81
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * Final Project - Elevators
 */

#include "Elevator.h"
#include <iostream>

using namespace std;

void Elevator::tick(int currentTime) {
    //TODO: Implement tick
    if(currentTime % TICKS_PER_ELEVATOR_MOVE == 0 && isServicing())
        {
            if(targetFloor > currentFloor)
            {
                currentFloor++;
            }
            else if(targetFloor < currentFloor)
            {
                currentFloor--;
            }
        }
        if(targetFloor == currentFloor)
        {
            servicing = false;
        }
}

void Elevator::serviceRequest(int floorNum) {
    //TODO: Implement serviceRequest
    if(floorNum >= 0 && floorNum <= NUM_FLOORS)
        {
            targetFloor = floorNum;
            servicing = true;
        }
    
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

void Elevator::print(ostream &outs) {
    outs << currentFloor;
    if (!servicing){
        outs << "w";
    } else {
        outs << "s" << targetFloor;
    }
}

Elevator::Elevator() {
    currentFloor = 0;
    servicing = false;
	targetFloor = 0;
}

void Elevator::setCurrentFloor(int currentFloorIn) {
    currentFloor = currentFloorIn;
}

bool Elevator::isServicing() const {
	return servicing;
}

int Elevator::getCurrentFloor() const {
    return currentFloor;
}

int Elevator::getTargetFloor() const {
    return targetFloor;
}
