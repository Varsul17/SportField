//
// Created by segev on 2/26/2024.
//

#include "MainProgram.h"
#define NumberOfColl 9

MainProgram::MainProgram()
{
    int choice;
    do {
        std::cout << "Hello ! Welcome to Sami Sports Field Rental.\n"
                     "If you are an existing member in the system press 1. \n"
                     "for New member press 2.\n";
        std::cin >> choice;

        if (choice != 1 && choice != 2)
            std::cout << "The selection is not supported by the system. Please select again.\n";

    } while (choice != 1 && choice != 2);

    switch (choice)
    {
        case 1:
        {
            break;
        }
        case 2:
        {
            do {
                std::cout << "Glad you decided to join us!\n"
                             "To register as a new player press 1\n"
                             "To register as a new manager press 2\n";
                std::cin  >> choice;

                if (choice != 1 && choice != 2)
                    std::cout << "The selection is not supported by the system. Please select again.\n";

            } while (choice != 1 && choice != 2);

            switch (choice)
            {
                case 1:
                {
                    std::cout << "Welcome !\n"
                                 "In order to complete your registration as a new member in our system,\n"
                                 "we need some additional details from you.\n";
                    Player player;
                    addPlayer(player);
                    std::cout << "Thank you " << player.Get_First_Name() << " " << player.Get_Last_Name()
                              << " You are now an existing customer in our system.\n"
                                 " You can now log in.\n";
                    choice = 2;
                    break;
                }
                case 2:
                {
                    break;
                }
                default:
                {
                    break;
                }
            }
            break;
        }
        default:
        {
            break;
        }
    }
}

void MainProgram::addPlayer(Player playerToAdd)
{
    char*** tempMatrix = new char ** [counter+1];
    std::cout << playerToAdd.Get_Gender();

    for (int i = 0; i < counter; ++i)
    {
        tempMatrix[i] = new char*[NumberOfColl];

        for (int j = 0; j < NumberOfColl; ++j)
        {
            tempMatrix[i][j] = new char[strlen(matrix[i][j]) + 1];
            strcpy(tempMatrix[i][j], matrix[i][j]);
        }
    }

    tempMatrix[counter] = new char *[NumberOfColl];

    tempMatrix[counter][0] = new char[strlen(playerToAdd.Get_ID()) + 1];
    strcpy(tempMatrix[counter][0], playerToAdd.Get_ID());

    tempMatrix[counter][1] = new char[strlen(playerToAdd.Get_First_Name()) + 1];
    strcpy(tempMatrix[counter][1], playerToAdd.Get_First_Name());

    tempMatrix[counter][2] = new char[strlen(playerToAdd.Get_Last_Name()) + 1];
    strcpy(tempMatrix[counter][2], playerToAdd.Get_Last_Name());

    tempMatrix[counter][3] = new char[strlen(playerToAdd.Get_Bithday()) + 1];
    strcpy(tempMatrix[counter][3],playerToAdd.Get_Bithday() );

    tempMatrix[counter][4] = new char[strlen(playerToAdd.Get_Phone()) + 1];
    strcpy(tempMatrix[counter][4], playerToAdd.Get_Phone());

    tempMatrix[counter][5] = new char[strlen(playerToAdd.Get_Username()) + 1];
    strcpy(tempMatrix[counter][5], playerToAdd.Get_Username());

    tempMatrix[counter][6] = new char[strlen(playerToAdd.Get_Password()) + 1];
    strcpy(tempMatrix[counter][6], playerToAdd.Get_Password());

    tempMatrix[counter][7] = new char[strlen(playerToAdd.Get_Address()) + 1];
    strcpy(tempMatrix[counter][7], playerToAdd.Get_Address());

    tempMatrix[counter][8] = new char[strlen(playerToAdd.Get_VIp()) + 1];
    strcpy(tempMatrix[counter][8], playerToAdd.Get_VIp());

    tempMatrix[counter][9] = new char[strlen(playerToAdd.Get_Gender()) + 1];
    strcpy(tempMatrix[counter][9], playerToAdd.Get_Gender());


    for (int i = 0; i < counter+1; ++i)
    {
        for (int j = 0; j < NumberOfColl; ++j)
        {
            std::cout << tempMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    counter++;
    matrix = tempMatrix;
}
