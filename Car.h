#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
public:
    std::string Plate;  // License plate of the car
    std::string model;  // Model of the car
    std::string colour; // Colour of the car

    // Constructor to initialize a car with its plate, model, and colour
    Car(std::string Plate, std::string model, std::string colour);
};

#endif //CAR_H
