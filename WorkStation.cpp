#include "WorkStation.h"

void WorkStation::info() const
{
    std::cout << "Work Station: " << getName()
        << "\n----------------------"
        << "\nType: " << getType()
        << "\nHave depo: " << (haveDepo() ? "Yes" : "No")
        << "\nTracks: " << getTracks()
        << "\nAssigned locos: " << getAssignedLocos();
}

int WorkStation::getAssignedLocos() const
{
    return assigned_locos;
}

void WorkStation::setAssignedLocos(int count)
{
    this->assigned_locos = count;
}