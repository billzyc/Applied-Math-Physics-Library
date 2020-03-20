#include "constants.h"
#include "ball.h"
#include "grid.h"
#include <iostream>
#include <cmath>


namespace environment {
    double xResistance{ myConstants::airResistance };
    double yResistance{ myConstants::gravity };
}

void calculateLocation(Grid &currentGrid, Ball &currentBall, int secondsPassed){
    double x =  currentGrid.getInitialX() + currentGrid.positionKinematicFormula(currentBall.getInitialVelocityX(), secondsPassed, environment::xResistance);
    double y = currentGrid.getInitialY() + currentGrid.positionKinematicFormula(currentBall.getInitialVelocityY(), secondsPassed, environment::yResistance);
    currentGrid.setX(x);
    currentGrid.setY(y);
    std::cout << " current position - x: " << x << " y: " << y;
}

double timeToGround(Grid &currentLocation, Ball &currentBall){
    double a{environment::yResistance / 2};
    double b{currentBall.getInitialVelocityY()};
    double c{currentLocation.getInitialY()};
    double root {sqrt(b * b - 4 * a * c)};
    return abs((-b - root) / (2 * a));
}

int main() {
    Ball simulatedBall;
    Grid location;
    location.getHeight();
    char isAllCondition;
    std::cout << "add initial velocity and initial degree? Input y for yes, any key for no: ";
    std::cin >> isAllCondition;
    if(isAllCondition == 'y'){
        simulatedBall.getBallConditional();
    }

    int currentTime{0};
    while(location.getY() > 0.0){
        simulatedBall.calculateCurrentVelocity(currentTime, environment::xResistance, environment::yResistance);
        calculateLocation(location, simulatedBall, currentTime);
        std::cout << " at " << currentTime << " seconds" << std::endl;
        std::cout << std::endl;
        currentTime++;
    }

    std::cout << "it took " << timeToGround(location, simulatedBall ) << "s to stop" << std::endl;
    return 0;
}

