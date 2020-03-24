//
// Created by Bill Chen on 2020-03-24.
//
#include <cmath>

#include "Charge.h"
#include "constants.h"

double Charge::calculateDistance(Charge &secondCharge){
    double xDifference {m_posX - secondCharge.get_posX()};
    double yDifference {m_posY - secondCharge.get_posY()};
    return sqrt(pow(xDifference, 2.0) + pow(yDifference, 2.0));
}

double Charge::coulombsLaw(Charge &secondCharge){
    double coulombConstant {1 / (4 * myConstants::pi * myConstants::eNaught)};
    double distance {this->calculateDistance(secondCharge)};
    return coulombConstant * (m_charge * secondCharge.get_charge() / pow(distance, 2.0));
}