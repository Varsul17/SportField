#ifndef WORK_1_PRINCIPLES_FIX_DATABASE_H
#define WORK_1_PRINCIPLES_FIX_DATABASE_H
#include <iostream>
#include <fstream>
#include <cstring>

class DataBase {

protected:
    std::fstream mainDate;
    char*** matrix;
    int counter;

public:
    DataBase();
    ~DataBase();
};


#endif //WORK_1_PRINCIPLES_FIX_DATABASE_H
