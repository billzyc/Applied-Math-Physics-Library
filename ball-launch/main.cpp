#include "constants.h"

#include <iostream>
#include <cmath>

struct ball {
    int degree{0};
    double velocityX{0};
    double velocityY{0};
    double velocity{0};
};

struct grid {
    double y{0};
    double x{0};
};

namespace environment {
    double xResistance{ myConstants::airResistance };
    double yResistance{ myConstants::gravity };
}

double velocityKinematicFormula (double initialVelocity, int time, double acceleration) {
    return initialVelocity + acceleration * time;
}

double positionKinematicFormula (double initialVelocity, int time, double acceleration) {
    return ((initialVelocity * time) + (acceleration * time * time / 2));
}

grid getHeight(){
    grid location;
    std::cout << "enter the height of the initial ball in meters: ";
    std::cin >> location.y;
    return location;
}

ball getBallConditional(){
    ball currentBall;
    std::cout << "enter the velocity of the initial ball in m/s: ";
    std::cin >> currentBall.velocity;
    std::cout << "enter the degree of the initial ball in degrees above the horizon: ";
    std::cin >> currentBall.degree;
    currentBall.velocityX = cos(currentBall.degree * M_PI / 180) * currentBall.velocity;
    currentBall.velocityY = sin(currentBall.degree * M_PI / 180) * currentBall.velocity;
    return currentBall;
}

ball calculateBallConditional(ball currentBall, int time){
    currentBall.velocityX = velocityKinematicFormula(currentBall.velocityX, time, environment::xResistance);
    currentBall.velocityY = velocityKinematicFormula(currentBall.velocityY, time, environment::yResistance);
    currentBall.velocity = sqrt(pow (currentBall.velocityX, 2.0) + pow (currentBall.velocityY, 2.0));
    return currentBall;
}


grid calculateLocation(grid currentLocation, ball currentBall, int secondsPassed){
    currentLocation.x =  currentLocation.x + positionKinematicFormula(currentBall.velocityX, secondsPassed, environment::xResistance);
    currentLocation.y = currentLocation.y + positionKinematicFormula(currentBall.velocityY, secondsPassed, environment::yResistance);
    return currentLocation;
}

double timeToGround(grid currentLocation, ball currentBall){
    double a{environment::yResistance / 2};
    double b{currentBall.velocityY};
    double c{currentLocation.y};
    double root {sqrt(b * b - 4 * a * c)};
    return abs((-b - root) / (2 * a));

}

int main() {
    int currentTime{0};
    grid initialLocation{getHeight()};
    ball initialBall;
    char isAllCondition;
    std::cout << "add initial velocity and initial degree? Input y for yes, any key for no: ";
    std::cin >> isAllCondition;
    if(isAllCondition == 'y'){
        initialBall = getBallConditional();
    }

    ball currentBall{initialBall};
    grid currentLocation{initialLocation};
    while(currentLocation.y > 0.0){
        currentBall = calculateBallConditional(initialBall, currentTime);
        currentLocation = calculateLocation(initialLocation, initialBall, currentTime);
        std::cout << "current position - x: " << currentLocation.x << " y: " << currentLocation.y;
        std::cout << " at " << currentTime << " seconds" << std::endl;
        std::cout << "current velocity: " << currentBall.velocity << " with ";
        std::cout << currentBall.degree << " degrees"<< std::endl;
        std::cout << std::endl;
        currentTime++;
    }

    std::cout << "it took " << timeToGround(initialLocation, initialBall) << " s to stop" << std::endl;
    return 0;
}

