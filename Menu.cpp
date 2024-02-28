//
// Created by segev on 2/21/2024.
//

#define NumberOfColl 10
#include "Menu.h"

Menu::Menu() {


    int flag = 0;

    do {
        std::cout << "Hello! Welcome to Sammy Fitness.\n"
                     "new user? Or a member of our system?\n"
                     "For new user tap 1: \n"
                     "Interested in leaving our family? tap 2: \n"
                     "Editing personal details Tap 3: \n"
                  << std::endl;
        std::cin >> flag;
    }while(flag != 1 && flag != 2 && flag != 3);

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
    else if (flag == 3)
    {
        editData();
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

void Menu::editData()
{
    bool flag = false;
    int lineNumber;
    std::cout << "To edit your information in the system, enter your id number: \n";
    std::cin >> tempId;

    std::cout << "Enter your password: \n";
    std::cin >> tempPassword;

    for (int i = 0; i < counter; ++i)
    {
        if (strcmp(tempId,matrix[i][0]) == 0)
        {
            if (strcmp(tempPassword,matrix[i][6]) == 0)
            {
                flag = true;
                lineNumber = i;
                break;
            }
        }
    }

    if (flag)
    {
        int choice;

        do {

        std::cout <<"Which of the options do you want to change?\n"
                    "Changing the phone number press 1\n"
                    "Changing the username, press 2\n"
                    "Changing the password, press 3\n"
                    "Changing the address press 4\n";
        std::cin >> choice;

            if (choice < 1 || choice > 4)
                std::cout << "Wrong choice. Please select an option from the menu.";

        } while (choice != 1 && choice != 2 && choice != 3 && choice != 4);

        switch (choice){

            case 1:
            {
                std::cout << "You chose to change the phone number. Please enter the new number: \n";
                std::cin >> tempPhone;
                //index = 4
                editDateSupport(4,tempPhone,lineNumber);
                print();
                break;
            }
            case 2:
            {
                std::cout << "You chose to change the username. Please enter the new username: \n";
                std::cin >> tempUserName;
                //index = 5
                editDateSupport(5,tempUserName,lineNumber);
                break;
            }
            case 3:
            {
                std::cout << "You have chosen to change the password. Please enter the new password: \n";
                std::cin >> tempPassword;
                //index = 6
                editDateSupport(6,tempPassword,lineNumber);
                break;
            }
            case 4:
            {
                std::cout << "You have chosen to change the address. Please enter the new address: \n";
                std::cin >> tempAddress;
                //index = 7
                editDateSupport(7,tempAddress,lineNumber);
                break;
            }
            default:
            {
                std::cout << "error: The submenu does not support your selection!\n";
                break;
            }
        }
    }
}

void Menu::editDateSupport(int index, char *str, int lineNumber)
{
    delete[] matrix[lineNumber][index];
    matrix[lineNumber][index] = new char [strlen(str)+1];
    strcpy(matrix[lineNumber][index],str);
}

void Menu::print()
{
    for (int i = 0; i < counter; ++i)
    {
        for (int j = 0; j < NumberOfColl; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


