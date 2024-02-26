#include "User.h"


bool User::Blank_Line(int len) {
    if (len == 0) {
        cout << "You entered a blank line, please try again." << endl;
        return true;
    }
    return false;
}

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
    char f_name[MAX];
    char l_name[MAX];
    cout << "Enter your first name: " << endl;
    msg01();
    cin >> f_name;
    while (!Check_Name(f_name) || !(Check_Range(1, NAME_LIM, int(strlen(first_name))))) {
        cout << "The name you enter was incorrect, please try again:" << endl;
        msg01();
        cin >> f_name;
    }
    cout << "Enter your Last name" << endl;
    msg01();
    cin >> l_name;
    while (!Check_Name(l_name) || !(Check_Range(1, NAME_LIM, int(strlen(last_name))))) {
        cout << "The name you enter was incorrect, please try again:" << endl;
        msg01();
        cin >> l_name;
    }
    this->first_name = Set_String(f_name);
    this->last_name = Set_String(l_name);
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
    this->gender = gend;
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
bool User::Set_Email() { // Add Not only @.
    char email_check[MAX];
    cout << "Enter an email:" << endl;
    msg02();
    cin.getline(email_check, MAX);
    int len = int(strlen(email_check));
    if (len > EMAIL_LIM) {
        cout << "The Email is to long, please try again." << endl;
        return false;
    }
    if (Blank_Line(len))
        return false;
    int index_dot = -1, index_at_sign = -1;;
    for (int i = 0; i < len; ++i) {
        if (email_check[i] == AT_SIGN)
            index_at_sign = i;
        else if (email_check[i] == DOT)
            index_dot = i;
        else if (!Check_Let(email_check[i]) && (!Check_Number(email_check[i]) && (email_check[i] != UNDERLINE))) {
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
    this->email = Set_String(email_check);
    return true;
}


bool User::Set_ID() { // Maybe add an option to checked valid ID.
    char ID_check[MAX];
    cout << "Enter an ID, must be only 9 digits" << endl;
    cin.getline(ID_check, MAX);
    int len = int(strlen(ID_check));
    if (Blank_Line(len))
        return false;
    if (len != ID_LIM) {
        cout << "You enter incorrect number of digits, please try again." << endl;
        return false;
    }
    for (int i = 0; i < len; ++i) {
        if (!Check_Number(ID_check[i])) {
            cout << "You entered incorrect char, please try again." << endl;
            return false;
        }
    }
    this->ID = Set_String(ID_check);
    return true;
}


bool User::Set_Phone() {
    char phone_check[MAX];
    cout << "Enter your phone number:" << endl;
    msg03();
    cin.getline(phone_check, MAX);
    int len = int(strlen(phone_check));
    if (Blank_Line(len))
        return false;
    if (len != PUP_LIM) {
        cout << "You enter incorrect number of digits, please try again." << endl;
        return false;
    }
    if (phone_check[0] != '0')
        cout <<"Your number doesn't start with 0, please try again." << endl;
    if (phone_check[1] != '5')
        cout <<"Your number doesn't start with 05, please try again." << endl;
    for (int i = 0; i < len; ++i) {
        if (!Check_Number(phone_check[i])) {
            cout << "You entered incorrect char, please try again." << endl;
            return false;
        }
    }
    this->phone = Set_String(phone_check);
    return true;
}


bool User::Set_Username() {
    char username_check[MAX];
    cout << "Select username:" << endl;
    msg04();
    cin.getline(username_check, MAX);
    int len = int(strlen(username_check));
    if (Blank_Line(len))
        return false;
    if (len > PUP_LIM) {
        cout << "The username you chose is to long, please try again." << endl;
        return false;
    }
    for (int i = 0; i < len; ++i)
        if (!Check_Let(username_check[i]) && !Check_Number(username_check[i])) {
            cout << "You entered incorrect char, please try again." << endl;
            return false;
        }
    this->username = Set_String(username_check);
    return true;
}


bool User::Set_Password() {
    char pass_check[MAX];
    cout << "Select username:" << endl;
    msg05();
    cin.getline(pass_check, MAX);
    int len = int(strlen(pass_check));
    int upper = 0, lower = 0, num = 0;
    if (Blank_Line(len))
        return false;
    if (len > PUP_LIM || len < PASS_MIN) {
        cout << "You Enterd incorrect number of chars, please try again." << endl;
        return false;
    }
    for (int i = 0; i < len; ++i) {
        if (Check_Number(pass_check[i]))
            ++num;
        else if(Check_Upper(pass_check[i]))
            ++upper;
        else if (Check_Lower(pass_check[i]))
            ++lower;
        else {
            cout << "You Entered incorrect char, please try again" << endl;
            return false;
        }
    }
    this->password = Set_String(pass_check);
    return true;
}

bool User::Check_Date(char * str){
    int len = int(strlen(str));
    for (int i = 0; i < len; ++i)
        if (!Check_Number(str[i]))
            return false;
    return true;
}


bool User::Set_Birthday() {
//    char day[MAX], month[MAX], year[MAX];
//    cout << "Enter the year" << endl;
//    cin >> year;
//    cout << "Enter the month" << endl;
//    cin >> month;
//    cout << "Enter the day" << endl;
//    cin >> day;
//    if (Check_Number())
    this->birthday = "17/03/1998";
}
