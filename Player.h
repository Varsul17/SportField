#ifndef SPORTFIELD_PLAYER_H
#define SPORTFIELD_PLAYER_H
#include "User.h"

class Player: public User {
private:
    char* VIP;

public :
    Player(): User(){Set_VIP();}

    void Set_VIP();
    char* Get_VIp();
};


#endif //SPORTFIELD_PLAYER_H
