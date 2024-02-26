#include <iostream>
#include <cstring>
#include  "User.h"
#include "MainProgram.h"
#include "Field.h"
#include "Branch.h"





int main() {
    Field myField("Field1", "Ashdod", "Soccer", 100, 50, 50.0);

    // Printing details of the field
    myField.printDetails();

    // Writing schedule to file for the field
    myField.writeScheduleToFile();


    return 0;
}
