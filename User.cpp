#include "User.h"

char *User::Set_String(char * str) {
    char * res = new char[strlen(str) + 1];
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

void User::Set_Name() {
    char first_name [MAX];
    char last_name [MAX];
    cout << "Enter your first name: " << endl;
    msg01();
    cin >> first_name;
    while (!Check_Name(first_name) || !(Check_Range(1,NAME_LIM, int(strlen(first_name))))){
        cout << "The name you enter was incorrect, please try again:" << endl;
        msg01();
        cin >> first_name;
    }
    cout << "Enter your Last name" << endl;
    msg01();
    cin >> last_name;
    while (!Check_Name(last_name) || !(Check_Range(1,NAME_LIM, int(strlen(last_name))))) {
        cout << "The name you enter was incorrect, please try again:" << endl;
        msg01();
        cin >> last_name;
    }
    first_name[strlen(first_name)] = ' ';
    strcat(first_name, last_name);
    cout << first_name;
    //this->name = Set_String(first_name);
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
    }
    while(error);
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
 *      - The user typed space after the mail (optional - the user gets a massage but the email is still correct).
 *      The function only return true if all the rules are true (except the last one) otherwise false.    */
//bool User::Set_Email() {
//    char let = (char)(getchar());
//    if (Empty_Line(let)) // If the user typed empty line the func return false.
//        return false;
//    while ((let != AT_SIGN) && (let != ENTER)) { // We keep checking char until we reach enter or at sign
//        if ((!Check_Let(let)) && (!Check_Number(let))) // We check if the chars are not letters or numbers.
//            if ((let != DOT)&& (let != UNDERLINE)) { // We also check if the chars are not dot or underline.
//                cout << "You Entered incorrect char" << endl;
//                while(getchar() != ENTER); // We emtpy the rest of the chars.
//                return false;
//            } // second if
//        let = (char)(getchar());
//    } // while
//    if (let == ENTER) { // If the user press enter without typing @ the func return false.
//        cout << "You didn't entered @ in your mail." << endl;
//        return false;
//    }
//    bool is_dot = false; // We creat flag to check if the user print dot after the @.
//    let = (char)(getchar());
//    while ((let != SPACE)&&(let != ENTER)) { // We keep checking chars until we receive space (' ') or enter.
//        if ((!Check_Let(let)) && (!Check_Number(let)) && (let != DOT) && (let != UNDERLINE)){ // If The chars are not letters, numbers, dot or underline.
//            while(getchar() != ENTER); // We emtpy the rest of the chars.
//            cout << "You Entered incorrect char" << endl;
//            return false;
//        } // if
//        if (let == DOT) // We check if the char is dot and changing the flag.
//            is_dot = true;
//        let = (char)(getchar());
//    } // while
//    if (!is_dot){ // If the user didn't type dot the fun return false.
//        cout << "There is no dot after the @" << endl;
//        return false;
//    }
//    return true;
//} // func
//
//bool User::Empty_Line(char let) {
//    if (let == ENTER) { // We check if the char is Enter.
//        cout << "You entered a blank line!" << endl;
//        return true;
//    }
//    return false;
//}

bool User::Set_Email() {
    char email[MAX];
    cout << "Enter an email:" << endl;
    msg02();
    if (strlen(email) > 35) {
        cout << "The Email is to long" << endl;
        return false;
    }
    if (strlen())
    int counter = 0, index_dot = -1, index_at_sign = -1;;
    for (int i = 0; i < strlen(email); ++i) {
        if (email[i] == AT_SIGN)
            index_at_sign == i;
        else if (email[i] == )
    }
}