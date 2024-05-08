#pragma once

#include "Station.h"

class WorkStation : public Station
{
public:
    WorkStation(std::string name, StationType typeE,
        bool depo, int tracks, int assigned_locos)
        : Station(name, typeE, depo, tracks)
    {
        setAssignedLocos(assigned_locos);
    };

    // Информация о рабочей станции
    virtual void info() const;

    // Задать количество приписанных локомотивов
    void setAssignedLocos(int count);
    // Получить количество приписанных локомотивов
    int getAssignedLocos() const;

private:
    // Количество приписанных локомотивов
    int assigned_locos;
};

