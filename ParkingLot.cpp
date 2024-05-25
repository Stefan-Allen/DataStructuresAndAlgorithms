#include "ParkingLot.h"
#include <iostream>
#include <algorithm>
#include <random>

// Initialize the parking lot with the given number of spots
ParkingLot::ParkingLot(int totalSpots) {
    for (int i = 1; i <= totalSpots; ++i) {
        parkingSpots.emplace_back(i);  // Add a new parking space with a unique ID
    }
}

// Add a car to the waiting queue
void ParkingLot::addCarToQueue(const Car &car) {
    waitingQueue.push(car);  // Add the car to the queue
    std::cout << "Car added to queue: " << car.Plate << std::endl;  // Print confirmation
}

// Get a random empty spot from the parking lot
ParkingSpace *ParkingLot::getRandomEmptySpot() {
    std::vector<ParkingSpace *> emptySpots;
    for (auto &spot: parkingSpots) {
        if (!spot.car.has_value()) {  // Check if the spot is empty
            emptySpots.push_back(&spot);  // Add the empty spot to the list
        }
    }

    if (emptySpots.empty()) {
        return nullptr;  // No empty spots available
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(emptySpots.begin(), emptySpots.end(), g);  // Shuffle the empty spots to pick a random one

    return emptySpots.front();  // Return the first empty spot from the shuffled list
}

// Park a car from the queue into a random empty spot
void ParkingLot::parkCarInRandomSpot() {
    if (waitingQueue.empty()) {
        std::cout << "No cars in the waiting queue" << std::endl;
        return;
    }

    Car car = waitingQueue.front();  // Get the car at the front of the queue
    ParkingSpace *spot = getRandomEmptySpot();
    if (spot == nullptr) {
        std::cout << "No empty spots available for " << car.Plate << ". Car leaves the parking lot." << std::endl;
        waitingQueue.pop();  // Remove the car from the queue
        return;
    }

    waitingQueue.pop();  // Remove the car from the queue
    spot->car = car;  // Park the car in the empty spot
    parkedCars[car.Plate] = spot;  // Add the car to the hash table for quick lookup
    std::cout << "Car parked: " << car.Plate << " in spot " << spot->parkingId << std::endl;
}

// Remove a car from the parking lot by its license plate
void ParkingLot::removeCar(const std::string &licensePlate) {
    auto it = parkedCars.find(licensePlate);  // Find the car in the hash table
    if (it == parkedCars.end()) {
        std::cout << "Car not found in parking lot" << std::endl;
        return;
    }

    ParkingSpace *spot = it->second;  // Get the parking space of the car
    std::cout << "Removing car: " << licensePlate << " from spot " << spot->parkingId << std::endl;
    spot->car.reset();  // Remove the car from the parking space
    parkedCars.erase(it);  // Remove the car from the hash table
}

// Remove all cars from the parking lot
void ParkingLot::removeAllCars() {
    while (!parkedCars.empty()) {
        removeCar(parkedCars.begin()->first);  // Remove each car by its license plate
    }
}

// View all parked cars
void ParkingLot::viewParkedCars() {
    for (const auto &spot: parkingSpots) {
        if (spot.car.has_value()) {
            const Car &car = spot.car.value();  // Get the car parked in the spot
            std::cout << "Spot " << spot.parkingId << ": " << car.Plate << ", " << car.model << ", " << car.colour
                      << std::endl;
        }
    }
}

// Check if the waiting queue is empty
bool ParkingLot::isQueueEmpty() const {
    return waitingQueue.empty();
}
