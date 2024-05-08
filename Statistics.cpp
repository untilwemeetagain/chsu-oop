#include "Statistics.h"

#include <iostream>

Statistics::Statistics()
{
    stations = {};
    total_tracks = 0;
}

void Statistics::print() const
{
    if (!stations.empty())
    {
        for (const auto& element : stations)
        {
            element.first->info();
            std::cout << "\n\n";
        }
    }
    else
    {
        std::cout << "Dictionary is empty!\n";
    }
    std::cout << "Total tracks: " << total_tracks << "\n";
}

void Statistics::add(IStation* st)
{
    if (stations.count(st))
    {
        stations[st]++;
    }
    else
    {
        stations.insert({ st, 1 });
    }
    total_tracks += st->getTracks();
}

void Statistics::add_all(LinkedList<IStation*>* st)
{
    for (int i = 0; i < st->size(); i++) 
        add(st->operator[](i));
}

void Statistics::del(IStation* st)
{
    total_tracks -= st->getTracks();
    stations.erase(st);
}

void Statistics::del_all(LinkedList<IStation*>* st)
{
    for (int i = 0; i < st->size(); i++) 
        del(st->operator[](i));
}

void Statistics::clear()
{
    total_tracks = 0;
    stations.clear();
}

