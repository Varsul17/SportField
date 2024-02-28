//
// Created by segev on 2/26/2024.
//

#ifndef SPORTFIELD_MAINPROGRAM_H
#define SPORTFIELD_MAINPROGRAM_H
#include <iostream>
#include "User.h"
#include "Player.h"
#include "DataBase.h"



class MainProgram : public DataBase{
private:

public:
    MainProgram();

    void addPlayer();

};


#endif //SPORTFIELD_MAINPROGRAM_H
