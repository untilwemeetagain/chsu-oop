#pragma once

#include "IStation.h"

class Station : public virtual IStation
{
public:
    Station(std::string name, StationType typeE, bool depo, int tracks);

    ~Station();
    
    // вывод на консоль хар-ки станции
    void info() const override;
    // установка нового имени станции
    void setName(std::string new_name) override;
    // установка нового типа станции
    void setType(StationType st_type) override;
    // утсановка новой числа путей
    void setTracks(int count) override;
    // установка депо
    void setDepo(bool hv) override;

    // получить имя станции
    std::string getName() const override;
    // получить тип станции
    std::string getType() const override;
    // узнать если ли депо
    bool haveDepo() const override;
    // получить количество путей
    int getTracks() const override;

    // Перегрузка операторов
    bool operator ==(int m);
    bool operator<(const Station& obj);
    bool operator>(const Station& obj);
    friend std::ostream& operator<<(std::ostream& os, const Station& st);

private:        
    std::string name;    // Название станции       
    std::string type;    // Тип ж/д станции       
    bool depo;           // Наличие депо
    int tracks;          // Количество путей
};