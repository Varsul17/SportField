#include "User.h"

char *User::Set_String(char * str) {
    char *res = new char[strlen(str) + 1];
    strcpy(res, str);
    return res;
}


bool User::Check_Name(char *str) {
    for (int i = 0; i < strlen(str); ++i) {
        if (!Check_Upper(str[i]) && !Check_Lower(str[i]))
            return false;
        if ((i == 0) && (Check_Lower(str[i])))
            str[i] = Lower_To_Upper(str[i]);
    }
    return true;
}


void User::Set_Name() { //need to add blank line.
    char first_name[MAX];
    char last_name[MAX];
    cout << "Enter your first name: " << endl;
    msg01();
    cin >> first_name;
    while (!Check_Name(first_name) || !(Check_Range(1, NAME_LIM, int(strlen(first_name))))) {
        cout << "The name you enter was incorrect, please try again:" << endl;
        msg01();
        cin >> first_name;
    }
    cout << "Enter your Last name" << endl;
    msg01();
    cin >> last_name;
    while (!Check_Name(last_name) || !(Check_Range(1, NAME_LIM, int(strlen(last_name))))) {
        cout << "The name you enter was incorrect, please try again:" << endl;
        msg01();
        cin >> last_name;
    }
    first_name[strlen(first_name)] = ' ';
    strcat(first_name, last_name);
    cout << first_name;
    this->name = Set_String(first_name);
}


void User::Set_Gender() {
    char gend[MAX];
    bool error = true;
    do {
        cout << "Enter Your Gender, please enter M/F" << endl;
        cin >> gend;
        if (strlen(gend) != 1) {
            cout << "You entered to many characters please enter M/F only, please try again." << endl;
            continue;
        }
        if (gend[0] == 'f' || gend[0] == 'F' || gend[0] == 'm' || gend[0] == 'M')
            error = false;
        else
            cout << "Incorrect option please try again" << endl;
    } while (error);
    if (Check_Lower(gend[0]))
        gend[0] = Lower_To_Upper(gend[0]);
    this->gender = gend[0];
}


/* Input: The function doesn't get anything.
 * Output: The function return true or false.
 * EXP: The function gets mail form the user.
 *      The function check the following rules:
 *      - The mail is not a blank line.
 *      - The mail can contain only letter, numbers, dots, underlines, and at sign.
 *      - The mail must have at sign (@).
 *      - The mail must have a dot after the at sign.
 *      The function only return true if all the rules are true, otherwise false.    */
bool User::Set_Email() {
    char email[MAX];
    cout << "Enter an email:" << endl;
    msg02();
    cin.getline(email, MAX);
    int len = int(strlen(email));
    if (len > 35) {
        cout << "The Email is to long, please try again." << endl;
        return false;
    }
    if (len == 0) {
        cout << "You entered a blank line, please try again." << endl;
        return false;
    }
    int index_dot = -1, index_at_sign = -1;;
    for (int i = 0; i < strlen(email); ++i) {
        if (email[i] == AT_SIGN)
            index_at_sign = i;
        else if (email[i] == DOT)
            index_dot = i;
        else if (!Check_Let(email[i]) && (!Check_Number(email[i]) && (email[i] != UNDERLINE))) {
            cout << email[i] << endl;
            cout << "You Entered incorrect char, please try again." << endl;
            return false;
        }
    }
    if (index_at_sign == -1) {
        cout << "There isn't at sign in the email you entered, please try again." << endl;
        return false;
    }
    if (index_dot == -1) {
        cout << "There isn't dot in the email you entered, please try again." << endl;
        return false;
    }
    if (index_dot < index_at_sign) {
        cout << "A dot cannot appear before the at sign, please try again." << endl;
        return false;
    }
    if (index_dot == len - 1) {
        cout << "An email cannot end in dot, an ending must be added, please try again." << endl;
        return false;
    }
    cout << "you did it! " << endl;
    this->email = Set_String(email);
    return true;
}


bool User::Set_ID() {
    cout << "Enter an ID, must be 9 digits"
}