//
// Created by segev on 2/21/2024.
//

#ifndef WORK_1_PRINCIPLES_FIX_MENU_H
#define WORK_1_PRINCIPLES_FIX_MENU_H
#include <iostream>
#include "DataBase.h"



class Menu: public DataBase{
private:
    char tempId[50];
    char tempName[50];
    char tempLastName[50];
    char tempBirthday[50];
    char tempPhone[50];
    char tempUserName[50];
    char tempPassword[50];
    char tempAddress[50];
    char tempVip[50];
    char tempGender[50];
    char*** tempMatrix;
public:
    Menu();
    void addData(char* id, char* name, char* lastName, char* Birthday,char* phone,
                 char* userName,char* password,char* address,char* vip, char* gender);

    void removeData();
    void editData();
    void editDateSupport(int index, char* str, int line);
    void print();
};


#endif //WORK_1_PRINCIPLES_FIX_MENU_H
