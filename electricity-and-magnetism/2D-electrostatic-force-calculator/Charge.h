//
// Created by Bill Chen on 2020-03-24.
//

#ifndef ELECTROSTATIC_FORCE_CALCULATOR_CHARGE_H
#define ELECTROSTATIC_FORCE_CALCULATOR_CHARGE_H



class Charge {

private:

    double m_posX{0};
    double m_posY{0};
    double m_charge{0};
    double m_totalElectricForce{0};

public:
    Charge(){}

    Charge(double x, double y, double charge): m_posX{x}, m_posY{y}, m_charge{charge}{}

    double get_posX(){
        return m_posX;
    }

    double get_posY(){
        return m_posY;
    }

    double get_charge(){
        return m_charge;
    }

    double get_totalElectricForce(){
        return m_totalElectricForce;
    }

    void set_posX(double x){
        m_posX = x;
    }

    void set_posY(double y){
        m_posY = y;
    }

    void set_charge(double charge){
        m_charge = charge * 1e-6;
    }

    void set_totalElectricForce(double force){
        m_totalElectricForce = force;
    }

    void set_addElectricForce(double force){
        m_totalElectricForce = m_totalElectricForce + force;
    }

    double calculateDistance(Charge &secondCharge);

    double coulombsLaw(Charge &secondCharge);
};




#endif //ELECTROSTATIC_FORCE_CALCULATOR_CHARGE_H
