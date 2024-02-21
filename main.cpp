#include <iostream>
#include <cstring>
#include  "User.h"


int main() {
    User check;
//    check.Set_Name();
//    check.Set_Gender();
    cout << "Enter an Email" << endl;
    bool valid = false;
    while (!valid){
        if (check.Set_Email())
            valid = true;
    }
    return 0;
}
