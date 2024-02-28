//
// Created by segev on 2/26/2024.
//

#include "MainProgram.h"
#define NumberOfColl 9

void matrixCopy(char***& matrix, char*** mat2, int counter)
{
    // Release existing resources
    if (matrix != nullptr)
    {
        for (int i = 0; i < counter - 1; ++i)
        {
            for (int j = 0; j < NumberOfColl; ++j)
            {
                delete[] matrix[i][j];
            }
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    // Allocate new memory
    matrix = new char**[counter];

    // Copy data
    for (int i = 0; i < counter; ++i)
    {
        matrix[i] = new char*[NumberOfColl];

        for (int j = 0; j < NumberOfColl; ++j)
        {
            matrix[i][j] = new char[strlen(mat2[i][j]) + 1];
            strcpy(matrix[i][j], mat2[i][j]);
        }
    }
}

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
                    //Player player;
                    addPlayer();
//                    std::cout << "Thank you " << player.Get_First_Name() << " " << player.Get_Last_Name()
//                              << " You are now an existing customer in our system.\n"
//                                 " You can now log in.\n";
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

void MainProgram::addPlayer()
{
    char*** tempMatrix = new char**[counter + 1];

    for (int i = 0; i < counter; ++i)
    {
        tempMatrix[i] = new char*[NumberOfColl];

        for (int j = 0; j < NumberOfColl; ++j)
        {
            tempMatrix[i][j] = new char[strlen(matrix[i][j]) + 1];
            strcpy(tempMatrix[i][j], matrix[i][j]);
            std::cout << tempMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    tempMatrix[counter] = new char*[NumberOfColl];

//    char* id = playerToAdd.Get_ID();
//    char* firstName = playerToAdd.Get_First_Name();
//    char* lastName = playerToAdd.Get_Last_Name();
//    char* birthday = playerToAdd.Get_Birthday();
//    char* phone = playerToAdd.Get_Phone();
//    char* username = playerToAdd.Get_Username();
//    char* password = playerToAdd.Get_Password();
//    char* address = playerToAdd.Get_Address();
//    char* vip = playerToAdd.Get_VIP();
//    char* gender = playerToAdd.Get_Gender();

    tempMatrix[counter][0] = new char[strlen("sapir") + 1];
    strcpy(tempMatrix[counter][0], "sapir");

    tempMatrix[counter][1] = new char[strlen("shalom") + 1];
    strcpy(tempMatrix[counter][1], "shalom");

    tempMatrix[counter][2] = new char[strlen("shalom") + 1];
    strcpy(tempMatrix[counter][2], "shalom");

    tempMatrix[counter][3] = new char[strlen("shalom") + 1];
    strcpy(tempMatrix[counter][3], "shalom");

    tempMatrix[counter][4] = new char[strlen("shalom") + 1];
    strcpy(tempMatrix[counter][4], "shalom");

    tempMatrix[counter][5] = new char[strlen("shalom") + 1];
    strcpy(tempMatrix[counter][5], "shalom");

    tempMatrix[counter][6] = new char[strlen("shalom") + 1];
    strcpy(tempMatrix[counter][6], "shalom");

    tempMatrix[counter][7] = new char[strlen("shalom") + 1];
    strcpy(tempMatrix[counter][7], "shalom");

    tempMatrix[counter][8] = new char[strlen("shalom") + 1];
    strcpy(tempMatrix[counter][8], "shalom");

    tempMatrix[counter][9] = new char[strlen("shalom") + 1];
    strcpy(tempMatrix[counter][9], "shalom");


    counter++;
    matrixCopy(matrix,tempMatrix,counter);

    std::cout << "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111" <<std::endl;

    for (int i = 0; i < counter; ++i)
    {
        for (int j = 0; j < NumberOfColl; ++j)
        {
            std::cout << tempMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "22222222222222222222222222222222222222222222222222222222222222222222222222222222222222" <<std::endl;

//    for (int i = 0; i < counter-1; ++i)
//    {
//        for (int j = 0; j < NumberOfColl; ++j)
//        {
//            delete[] tempMatrix[i][j];
//            std::cout << tempMatrix[i][j] << " ";
//        }
//        std::cout <<std::endl;
//        delete[] tempMatrix[i];
//    }
//    delete[] tempMatrix;

    std::cout << "this is good";
}
