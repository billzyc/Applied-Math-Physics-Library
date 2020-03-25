#include <iostream>
#include <cmath>
#include <vector>

#include "Charge.h"

typedef std::vector<Charge> chargeList;

chargeList getChargesInfo(int numberOfCharges){
    chargeList charges(numberOfCharges);
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
    return charges;
}

int main() {
    int numberOfCharges{0};
    std::cout << "Enter number of total charges: ";
    std::cin >> numberOfCharges;
    chargeList charges{getChargesInfo(numberOfCharges)};
    int targetChargeIndex{};
    std::cout << "choose charge 1 to " << numberOfCharges << " as the target charge: ";
    std::cin >> targetChargeIndex;
    targetChargeIndex = targetChargeIndex - 1;
    double totalCharge {charges[targetChargeIndex].calculateTotalForce(charges, numberOfCharges)};
    std::cout << "total force on charge " << targetChargeIndex+1 << " is " << totalCharge << " N" << std::endl;
}

