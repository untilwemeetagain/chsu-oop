#pragma once

#include "WorkStation.h"

class OrdinaryStation : public WorkStation
{
public:
    OrdinaryStation(std::string name, StationType typeE,
        bool depo, int tracks, int assigned_locos, bool canteen)
    : WorkStation(name, typeE, depo, tracks, assigned_locos)
    {
        setCanteen(canteen);
    };
 
    // Получение информации о станции
    void info() const;

    // Установка информации о столовой на станции
    void setCanteen(bool hv);
    // Получение информации о столовой на станции
    bool haveCanteen() const;

private:
    bool canteen;
};