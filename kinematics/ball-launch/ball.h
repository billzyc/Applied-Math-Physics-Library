//
// Created by Bill Chen on 2020-03-20.
//

#ifndef BALL_LAUNCH_BALL_H
#define BALL_LAUNCH_BALL_H

#include <cmath>

class Ball {
private:
    int m_degree{0};
    double m_velocityX{0};
    double m_velocityY{0};
    double m_velocity{0};
    double m_initial_velocity{0};
    double m_initial_velocityY{0};
    double m_initial_velocityX{0};


public:

    Ball(){}

    Ball(int degree, double velocity){
        m_velocityX = cos(m_degree * M_PI / 180) * m_velocity;
        m_velocityY = sin(m_degree * M_PI / 180) * m_velocity;
    }

    void getBallConditional();


    void setVelocityX(double velocityX){
        m_velocityX = velocityX;
    }

    void setVelocityY(double velocityY){
        m_velocityY = velocityY;
    }

    void setVelocity(double velocity){
        m_velocity = velocity;
    }

    void setInititalVelocityX(double velocityX){
        m_velocityX = velocityX;
    }

    void setInititalVelocityY(double velocityY){
        m_velocityY = velocityY;
    }

    void setInititalVelocity(double velocity){
        m_velocity = velocity;
    }

    void setDegree(double degree) {
        m_degree = degree;
    }

    double getVelocityX(){
        return m_velocityX;
    }

    double getVelocityY(){
        return m_velocityY;
    }

    double getVelocity(){
        return m_velocity;
    }

    double getInitialVelocityX(){
        return m_initial_velocityX;
    }

    double getInitialVelocityY(){
        return m_initial_velocityY;
    }

    double getInitialVelocity(){
        return m_initial_velocity;
    }

    int getDegree(){
        return m_degree;
    }

    double velocityKinematicFormula(double initialVelocity, int time, double acceleration);

    void calculateCurrentVelocity(int time, double resistanceX, double resistanceY);
};

#endif //BALL_LAUNCH_BALL_H
