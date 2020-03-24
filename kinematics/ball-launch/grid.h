//
// Created by Bill Chen on 2020-03-20.
//

#ifndef BALL_LAUNCH_GRID_H
#define BALL_LAUNCH_GRID_H

class Grid {

private:
    double m_initialX{0};
    double m_initialY{0};
    double m_y{0};
    double m_x{0};

public:

    struct coordinates {
        int x;
        int y;
    };

    Grid(){}

    void setInitialY(double y){
        m_initialY =y;
    }

    void setInitialX(double x){
        m_initialX =x;
    }

    void setY(double y){
        m_y = y;
    }

    void setX(double x){
        m_x = x;
    }

    double getInitialX(){
        return m_initialX;
    }

    double getInitialY(){
        return m_initialY;
    }

    double getX(){
        return m_x;
    }

    double getY(){
        return m_y;
    }


    void getHeight();

    double positionKinematicFormula (double initialVelocity, int time, double acceleration);
};

#endif //BALL_LAUNCH_GRID_H
