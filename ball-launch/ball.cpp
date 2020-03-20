//
// Created by Bill Chen on 2020-03-20.
//

#include "ball.h"
#include <iostream>
#include <cmath>


void Ball::getBallConditional() {
    Ball currentBall;
    std::cout << "enter the velocity of the initial ball in m/s: ";
    std::cin >> m_initial_velocity;
    m_velocity = m_initial_velocity;
    std::cout << "enter the degree of the initial ball in degrees above the horizon: ";
    std::cin >> m_degree;
    m_initial_velocityX = cos(m_degree * M_PI / 180) * m_velocity;
    m_velocityX = m_initial_velocityX;
    m_initial_velocityY = sin(m_degree * M_PI / 180) * m_velocity;
    m_velocityY = m_initial_velocityY;
}


double Ball::velocityKinematicFormula(double initialVelocity, int time, double acceleration) {
    return initialVelocity + acceleration * time;
}

void Ball::calculateCurrentVelocity(int time, double resistanceX, double resistanceY){
    m_velocityX = velocityKinematicFormula(m_initial_velocityX, time, resistanceX);
    m_velocityY = velocityKinematicFormula(m_initial_velocityY, time, resistanceY);
    m_velocity = sqrt(pow (m_velocityX, 2.0) + pow (m_velocityY, 2.0));
    std::cout << " current velocity: " << m_velocity;
}