#ifndef PARKINGSPACE_H
#define PARKINGSPACE_H

#include <optional>
#include "Car.h"

class ParkingSpace {
public:
    int parkingId; // Unique ID of the parking space
    std::optional<Car> car; // Optional Car object to indicate if a car is parked

    // Constructor to initialize a parking space with ID
    explicit ParkingSpace(int spotId);
};

#endif // PARKINGSPACE_H
