#include "ParkingSpace.h"

// Initialize the ParkingSpace object with a parking ID and no car parked
ParkingSpace::ParkingSpace(int parkingId) : parkingId(parkingId), car(std::nullopt) {}
