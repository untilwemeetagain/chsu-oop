#include "OrdinaryStation.h"

void OrdinaryStation::info() const
{
    std::cout << "Ordinary Station: " << getName()
        << "\n----------------------"
        << "\nType: " << getType()
        << "\nHave depo: " << (haveDepo() ? "Yes" : "No")
        << "\nTracks: " << getTracks()
        << "\nAssigned locos: " << getAssignedLocos()
        << "\nCanteen: " << (haveCanteen() ? "Yes!!!" : "No :(")
        << "\n";
}

void OrdinaryStation::setCanteen(bool hv)
{
    this->canteen = hv;
}

bool OrdinaryStation::haveCanteen() const
{
    return canteen;
}