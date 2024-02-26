#ifndef SPORTFIELD_PLAYER_H
#define SPORTFIELD_PLAYER_H
#include "User.h"

class Player: public User {
private:
    char* VIP;

public :
    Player(): User(){Set_VIP();}

    void Set_VIP(){this->VIP = "No";}
    char* Get_VIp(){return VIP;}
    //GAL
};


#endif //SPORTFIELD_PLAYER_H
