#include <iostream>
#include <cstring>
#include  "User.h"


int main() {
    User check;
//    check.Set_Name();
//    check.Set_Gender();
    bool flag = false;
    while (!flag){
        if (check.Set_Email())
            flag = true;
    }
    return 0;
}
