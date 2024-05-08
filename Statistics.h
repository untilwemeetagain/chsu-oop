#pragma once

#include "LinkedList.h"
#include "Station.h"

#include <map>

class Statistics
{
public:
    Statistics();
    // вывод содержимого словаря на экран
    void print() const;
    // добавление 1 объекта АТД
    void add(IStation* device);
    // добавление всех объектов АТД в КК
    void add_all(LinkedList<IStation*>* device);
    // удаление 1 объекта АТД
    void del(IStation* device);
    // удаление всех объектов АТД в КК
    void del_all(LinkedList<IStation*>* device);
    // очистка словаря
    void clear();

private:
    // словарь
    std::map<IStation*, double> stations;
    // итоговая цена
    double total_tracks;
};