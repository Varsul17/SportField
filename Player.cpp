#include "Player.h"

void Player::Set_VIP() {
    int choice;
    cout << "Do you want to be a VIP Client: 1 - YES, 2 - NO." << endl;
    cin >> choice;
//    cin >>choice;
    if (choice == 1)
        this->VIP = Set_String("Yes");
    else
        this->VIP = Set_String("NO");
}

