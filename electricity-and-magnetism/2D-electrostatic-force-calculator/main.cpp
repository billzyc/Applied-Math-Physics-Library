#include <iostream>
#include <cmath>
#include <vector>

#include "Charge.h"

double calculateTotalForce(std::vector<Charge> charges, int numberOfCharges, int targetChargeIndex){
    Charge targetCharge = charges[targetChargeIndex];
    for (int i{0}; i<numberOfCharges; i++){
        if(i != targetChargeIndex){
            double force = targetCharge.coulombsLaw(charges[i]);
            targetCharge.set_addElectricForce(force);
        }
    }
    return targetCharge.get_totalElectricForce();
}

int main() {
    int numberOfCharges{0};
    std::cout << "Enter number of total charges: ";
    std::cin >> numberOfCharges;
    std::vector<Charge> charges(numberOfCharges);
    for(int i{0}; i < numberOfCharges; i++){
        Charge newCharge;
        double x;
        double y;
        double amountOfCharge;
        charges[i] = newCharge;
        std::cout << "Enter x position of Charge " << i+1 << " : ";
        std::cin >> x;
        charges[i].set_posX(x);
        std::cout << "Enter y position of Charge " << i+1 << " : ";
        std::cin >> y;
        charges[i].set_posY(y);
        std::cout << "Enter amount of charge in body of this charge " << i+1 << " in microcoulombs: ";
        std::cin >> amountOfCharge;
        charges[i].set_charge(amountOfCharge);
    }
    int targetChargeIndex{};
    std::cout << "choose charge 1 to " << numberOfCharges << " as the target charge: ";
    std::cin >> targetChargeIndex;
    targetChargeIndex = targetChargeIndex - 1;
    double totalCharge = calculateTotalForce(charges, numberOfCharges, targetChargeIndex);
    std::cout << "total force on charge " << targetChargeIndex+1 << " is " << totalCharge << " N" << std::endl;
}

