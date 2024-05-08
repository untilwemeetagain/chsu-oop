#pragma once

#include "PatrolStation.h"
#include "OrdinaryStation.h"

class UniversalStation : public PatrolStation, public OrdinaryStation
{
public:
    UniversalStation(std::string name, StationType typeE,
        bool depo, int tracks, int assigned_locos, bool canteen,
        double capacity)
        : PatrolStation::PatrolStation(name, typeE, depo, tracks, assigned_locos, capacity),
        OrdinaryStation::OrdinaryStation(name, typeE, depo, tracks, assigned_locos, canteen)
    {
    };


    void info() const;
};

void UniversalStation::info() const
{
    std::cout << "Universal Station: " << PatrolStation::getName()
        << "\n----------------------"
        << "\nType: " << OrdinaryStation::getType()
        << "\nHave depo: " << (PatrolStation::haveDepo() ? "Yes" : "No")
        << "\nTracks: " << OrdinaryStation::getTracks()
        << "\nAssigned locos: " << PatrolStation::getAssignedLocos()
        << "\nCapacity: " << getCapacity()
        << "\nCanteen: " << (haveCanteen() ? "Yes!!!" : "No :(");
}