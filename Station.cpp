#include "Station.h"

Station::Station(std::string name, StationType st_type, bool depo, int tracks)
{
    setName(name);
    setType(st_type);
    setDepo(depo);
    setTracks(tracks);
}

Station::~Station()
{
}

void Station::info() const
{
    std::cout << "Current Station: " << getName()
        << "\n----------------------"
        << "\nType: " << getType()
        << "\nHave depo: " << haveDepo()
        << "\nTracks: " << getTracks();
}

void Station::setName(std::string new_name)
{
    this->name = new_name;
}

void Station::setType(StationType st_type)
{
    switch (st_type)
    {
    case StationType::passenger:
        type = "Passenger Station";
        break;
    case StationType::freight:
        type = "Freight Station";
        break;
    case StationType::sort:
        type = "Sorting Station";
        break;
    case StationType::crossing:
        type = "Crossing Station";
        break;
    }
}

void Station::setTracks(int count)
{
    if (count <= 0)
        throw std::invalid_argument("Negative or zero tracks.");

    this->tracks = count;
}

void Station::setDepo(bool hv)
{
    this->depo = hv;
}

std::string Station::getName() const
{
    return name;
}

std::string Station::getType() const
{
    return type;
}

bool Station::haveDepo() const
{
    return depo;
}

int Station::getTracks() const
{
    return tracks;
}

bool Station::operator==(int m)
{
    return getTracks() == m;
}

bool Station::operator<(const Station& obj)
{
    return getTracks() < obj.getTracks();
}

bool Station::operator>(const Station& obj)
{
    return getTracks() > obj.getTracks();
}

std::ostream& operator<<(std::ostream& out, const Station& st)
{
    out << "Station: " << st.getName()
        << "\n----------------------"
        << "\nType: " << st.getType()
        << "\nHave depo: " << (st.haveDepo() ? "Yes" : "No")
        << "\nTracks: " << st.getTracks()
        << "\n";
    return out;
}
