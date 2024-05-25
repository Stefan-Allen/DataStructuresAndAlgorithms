#include "Car.h"

#include <utility>

// Initialize the Car object with the provided plate, model, and colour
Car::Car(std::string Plate, std::string model, std::string colour)
        : Plate(std::move(Plate)), model(std::move(model)), colour(std::move(colour)) {}
