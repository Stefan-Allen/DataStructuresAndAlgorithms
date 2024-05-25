#include "ParkingLot.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int main() {
    ParkingLot parkingLot(5); // Create a parking lot with 5 spots

    // Create a list of cars
    std::vector<Car> cars = {

            Car("XYZ789", "Honda", "Blue"),
            Car("BCD789", "Nissan", "Silver"),
            Car("LMN456", "Tesla", "Black"),
            Car("JKL321", "Ford", "Green"),
            Car("GHI789", "BMW", "White"),
            Car("YZA456", "Hyundai", "Brown"),
            Car("ABC123", "Toyota", "Red"),
            Car("MNO123", "Audi", "Grey"),
            Car("STU789", "Volkswagen", "Pink"),
            Car("PQR456", "Mercedes", "Purple"),
            Car("DEF456", "Chevrolet", "Green"),
            Car("VWX123", "Kia", "Red")
    };

    // Shuffle the cars
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cars.begin(), cars.end(), g);

    // Randomly decide which cars will enter the parking lot
    for (const auto &car: cars) {
        if (std::uniform_int_distribution<>(0, 1)(g)) {
            parkingLot.addCarToQueue(car);
        }
    }

    // Park all cars in the queue in random spots
    while (!parkingLot.isQueueEmpty()) {
        parkingLot.parkCarInRandomSpot();
    }

    // View parked cars
    std::cout << "\nParked Cars:\n";
    parkingLot.viewParkedCars();

    // Remove all cars
    std::cout << "\nRemoving all cars...\n";
    parkingLot.removeAllCars();

    // View parked cars again to confirm removal
    std::cout << "\nParked Cars after removal:\n";
    parkingLot.viewParkedCars();

    return 0;
}
