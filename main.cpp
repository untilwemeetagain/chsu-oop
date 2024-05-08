#include <iostream>

#include "LinkedList.h"
#include "Statistics.h"

#include "Station.h"
#include "WorkStation.h"
#include "PatrolStation.h"
#include "UniversalStation.h"

int main()
{
    srand(time(0));

    LinkedList<IStation*> ll;

    Station st("Cherepovets-1", StationType::passenger, true, 89);
    Station st2("Vologda-2", StationType::passenger, true, 20);
    Station st3("Tynda", StationType::passenger, true, 60);
    Station st4(st3);
    WorkStation st5("WorkStation", StationType::freight, true, 25, 6);
    PatrolStation st6("PatrolStation", StationType::passenger, false, 40, 4, 30.9);
    UniversalStation st7("UniversalStation", StationType::sort, true, 50, 1000, true, 133.7);

    st3.setName("Novaya Chara");
    st3.setTracks(30);
    st5.setTracks(50);

    ll.push_back(&st); 
    ll.push_back(&st2); 
    ll.push_back(&st3); 
    ll.push_back(&st4);
    ll.push_back(&st5);
    ll.push_front(&st6);
    ll.push_front(&st7);

    std::cout << "Stations count: " << ll.size();

    Statistics stat;
    
    std::cout << "\n\n~ > Adding " << ll.size() << " stations to statistics...\n";
    stat.add_all(&ll);

    std::cout << "\nSTATISTICS:\n";
    stat.print();

    std::cout << "\n~ > Deleting station 2 - Vologda-2...\n";
    stat.del(&st2);
    
    std::cout << "\nSTATISTICS:\n";
    stat.print();
    st6.info();

    std::cout << "\n\n~ > Deleting all stations...\n";
    stat.clear();

    std::cout << "\nSTATISTICS:\n";
    stat.print();
    
    std::cout << "\n~ > Testing exceptions...\n\n";

    try
    {
        PatrolStation ps("patrol station", StationType::sort, true, -10, 4, 30.3);
        ps.info();
    }
    catch (const std::invalid_argument& error)
    {
        std::cout << error.what() << std::endl;
    }
    catch (const std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "Error" << std::endl;
    }

    return 0;
}
