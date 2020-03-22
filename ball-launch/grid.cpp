//
// Created by Bill Chen on 2020-03-20.
//

#include "grid.h"
#include <iostream>


void Grid::getHeight(){
    std::cout << "enter the height of the initial ball in meters: ";
    std::cin >> m_initialY;
    m_y = m_initialY;
}

double Grid::positionKinematicFormula (double initialVelocity, int time, double acceleration) {
    return ((initialVelocity * time) + (acceleration * time * time / 2));
}
