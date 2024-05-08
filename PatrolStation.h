#pragma once

#include "WorkStation.h"

class PatrolStation : public WorkStation
{
public:
    PatrolStation(std::string name, StationType typeE,
        bool depo, int tracks, int assigned_locos, double capacity)
        : WorkStation(name, typeE, depo, tracks, assigned_locos)
    {
        setCapacity(capacity);
    };

    // Информация о patrol станции
    void info() const;

    // Установление нового значения пропускной способности
    void setCapacity(double new_capacity);
    // Получение текущего значения пропускной способности
    double getCapacity() const;

private:
    double capacity;
};