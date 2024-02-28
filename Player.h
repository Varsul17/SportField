#ifndef SPORTFIELD_PLAYER_H
#define SPORTFIELD_PLAYER_H
#include "User.h"

class Player: public User {
private:
    char* VIP;

public :
    Player(): User(){Set_VIP();}
    ~Player(){delete [] this->VIP;}

    void Set_VIP();
    char* Get_VIP(){return VIP;}
    friend ostream& operator<<(ostream& out, Player& print){ out << static_cast<User&>(print); out << "VIP: " << print.Get_VIP() << endl; return out;}
};


#endif //SPORTFIELD_PLAYER_H
