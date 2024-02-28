#ifndef MAIN_CPP_MANAGER_H
#define MAIN_CPP_MANAGER_H
#include "User.h"

class Manager: public User {

private:
    char * location;
public:
    bool Set_Location();
    char* Get_Location(){return this->location;};
    Manager(): User(){while(!Set_Location());}
    ~Manager(){delete [] this->location;}
    friend ostream& operator<<(ostream& out, Manager& print){ out << static_cast<User&>(print); out << "Location of the branch: " << print.Get_Location() << endl; return out;}




};


#endif //MAIN_CPP_MANAGER_H
