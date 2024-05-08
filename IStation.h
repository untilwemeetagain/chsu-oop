#pragma once

#include "StationType.h"

#include <string>
#include <iostream>
#include <cstring>

class IStation
{
public:
    // Вывод информации о станции
    virtual void info() const = 0;

    // установка нового имени станции
    virtual void setName(std::string name) = 0;
    // установка нового типа станции
    virtual void setType(StationType st_type) = 0;
    // утсановка количества путей станции
    virtual void setTracks(int value) = 0;
    // установка наличия депо
    virtual void setDepo(bool value) = 0;

    // получить имя станции
    virtual std::string getName() const = 0;
    // получить тип станции
    virtual std::string getType() const = 0;
    // получить наличие депо
    virtual bool haveDepo() const = 0;
    // получить количество путей станции
    virtual int getTracks() const = 0;
};

