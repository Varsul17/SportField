//
// Created by segev on 2/21/2024.
//

#define NumberOfColl 10
#include "Menu.h"

Menu::Menu() {


    int flag = 0;

    do {
        std::cout << "Hello! Welcome to Sammy Fitness.\n"
                     " new user? Or a member of our system?\n"
                     " For new user tap 1.\n"
                     " Existing user tap 2 : \n"
                  << std::endl;
        std::cin >> flag;
    }while(flag != 1 && flag != 2);

    if (flag ==1)
    {
        std::cout << "Thanks!\n We are glad you have decided to join our fitness family.\n Just a few small details and we are ready!\n";
        std::cout << "Insert id number.\n";
        std::cin >> tempId;

        std::cout << "Insert first name.\n";
        std::cin >> tempName;

        std::cout << "Insert last name.\n";
        std::cin >> tempLastName;

        std::cout << "Insert Birthday date in format: dd/mm/yyyy.\n";
        std::cin >> tempBirthday;

        std::cout << "Insert phone number: \n";
        std::cin >> tempPhone;

        std::cout << "Insert user name:\n";
        std::cin >> tempUserName;

        std::cout << "Insert password: \n";
        std::cin >> tempPassword;

        std::cout << "Insert Address: \n";
        std::cin >> tempAddress;

        std::cout << "Would you like to be a vip customer write yes or no: \n";
        std::cin >> tempVip;

        std::cout << "What is your gender, male or female?: \n";
        std::cin >> tempGender;

        addData(tempId, tempName,tempLastName,tempBirthday,tempPhone,
                tempUserName,tempPassword,tempAddress,tempVip,tempGender);

    }
    else if (flag == 2)
    {
        removeData();
    }
    else
    {

    }


}

void Menu::addData(char* id, char* name, char* lastName, char* Birthday,char* phone,
                   char* userName,char* password,char* address,char* vip,char* gender)
{
    tempMatrix = new char ** [counter+1];

    for (int i = 0; i < counter; ++i)
    {
        tempMatrix[i] = new char*[NumberOfColl];

        for (int j = 0; j < NumberOfColl; ++j)
        {
            tempMatrix[i][j] = new char[strlen(matrix[i][j]) + 1];
            strcpy(tempMatrix[i][j], matrix[i][j]);
        }
    }
    std::cout <<counter << std::endl;

    tempMatrix[counter] = new char *[NumberOfColl];

    tempMatrix[counter][0] = new char[strlen(id) + 1];
    strcpy(tempMatrix[counter][0], id);

    tempMatrix[counter][1] = new char[strlen(name) + 1];
    strcpy(tempMatrix[counter][1], name);

    tempMatrix[counter][2] = new char[strlen(lastName) + 1];
    strcpy(tempMatrix[counter][2], lastName);

    tempMatrix[counter][3] = new char[strlen(Birthday) + 1];
    strcpy(tempMatrix[counter][3],Birthday );

    tempMatrix[counter][4] = new char[strlen(phone) + 1];
    strcpy(tempMatrix[counter][4], phone);

    tempMatrix[counter][5] = new char[strlen(userName) + 1];
    strcpy(tempMatrix[counter][5], userName);

    tempMatrix[counter][6] = new char[strlen(password) + 1];
    strcpy(tempMatrix[counter][6], password);

    tempMatrix[counter][7] = new char[strlen(address) + 1];
    strcpy(tempMatrix[counter][7], address);

    tempMatrix[counter][8] = new char[strlen(vip) + 1];
    strcpy(tempMatrix[counter][8], vip);

    tempMatrix[counter][9] = new char[strlen(gender) + 1];
    strcpy(tempMatrix[counter][9], gender);


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

void Menu::removeData()
{
    bool flag = false;
    std::cout << "To stop the subscription, enter your ID card: " << std::endl;
    std::cin >> tempId;
    for (int i = 0; i < counter; ++i)
    {
        if (strcmp(tempId,matrix[i][0]) == 0)
        {
            std::cout << matrix[i][1] << " " << matrix[i][2] << " We are sorry to hear about the cancellation of your subscription.\n"
                                                                " We will always be happy to welcome you back.\n Thanks and all the best!\n";
            for (int j = 0; j < NumberOfColl; ++j)
            {
                strcpy(matrix[i][j],"$");
                flag = true;
            }
        }
        if (flag)
            break;
    }

    for (int i = 0; i < counter; ++i)
    {
        for (int j = 0; j < NumberOfColl; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
