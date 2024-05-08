#include "PatrolStation.h"

void PatrolStation::info() const
{
    std::cout << "Patrol Station: " << getName()
        << "\n----------------------"
        << "\nType: " << getType()
        << "\nHave depo: " << (haveDepo() ? "Yes" : "No")
        << "\nTracks: " << getTracks()
        << "\nAssigned locos: " << getAssignedLocos()
        << "\nCapacity: " << getCapacity();
}

void PatrolStation::setCapacity(double new_capacity)
{
    if (new_capacity < double(0))
        throw std::invalid_argument("Capacity cannot be less than zero.");

    this->capacity = new_capacity;
}

double PatrolStation::getCapacity() const
{
    return this->capacity;
}