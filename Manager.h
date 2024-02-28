#ifndef MAIN_CPP_MANAGER_H
#define MAIN_CPP_MANAGER_H
#include "User.h"

class Manager: public User {

private:
    char * location;
    Manager(): User(){while(Set_Location());}

    bool Set_Location();
    char* Get_Location();




};


#endif //MAIN_CPP_MANAGER_H
