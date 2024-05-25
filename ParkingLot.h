#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <queue>
#include <unordered_map>
#include <list>
#include <vector>
#include "Car.h"
#include "ParkingSpace.h"

class ParkingLot {
private:
    std::list<ParkingSpace> parkingSpots;  // Linked list to manage parking spots
    std::queue<Car> waitingQueue;  // Queue to manage cars waiting to be parked
    std::unordered_map<std::string, ParkingSpace *> parkedCars;  // Hash table for quick car lookup by license plate

    // Helper function to get a random empty spot
    ParkingSpace *getRandomEmptySpot();

public:
    // Constructor to initialize the parking lot with a specific number of total spots
    explicit ParkingLot(int totalSpots);

    // Add a car to the waiting queue
    void addCarToQueue(const Car &car);

    // Park a car from the queue into a random spot
    void parkCarInRandomSpot();

    // Remove a car from the parking lot by its license plate
    void removeCar(const std::string &licensePlate);

    // Remove all cars from the parking lot
    void removeAllCars();

    // View all parked cars
    void viewParkedCars();

    // Check if the waiting queue is empty
    bool isQueueEmpty() const;
};

#endif // PARKINGLOT_H
