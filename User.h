#ifndef FIELDSPROJECT_USER_H
#define FIELDSPROJECT_USER_H
#include <iostream>
#include <cstring>
#include "Date.h"
#define AT_SIGN '@'
#define ASTERISK '*'
#define DOT '.'
#define UNDERLINE '_'
#define ENTER '\n'
#define SPACE ' '
#define NAME_LIM 20
#define EMAIL_LIM 35
#define PHONE_LIM 10
#define ADDRESS_LIM 30
#define PUP_LIM 10
#define PASS_MIN 6
#define Max 100

using namespace std;

class User {
public:
    static char* Set_String(char*) ; // Checked
    bool Empty_Line(char let);
    static bool Check_Range(int start, int end, int num){return ((num >= start)&&(num <= end));} // Checked
    static bool Check_Upper(char ch){return ((ch >= 'A')&&(ch <= 'Z'));} // Checked
    static bool Check_Lower(char ch){return ((ch >= 'a')&&(ch <= 'z'));}// Checked
    static bool Check_Let()
    static bool Check_Letters(char *); // Checked
    static char Lower_To_Upper(char ch){return ch - 'a' + 'A';}
    void Set_Name(); //Checked
    void Set_Gender(); //Checked
    bool Set_Email();
    static void msg01(){cout << "Notice: name can only contain letters and be up to 20 characters}" << endl;} //Checked

protected:
    long ID;
    char * name;
    char gender;
    char * email;
    char * phone;
    char * username;
    char * password;
    char * address;
    Date birthday;

public:
    User(){}

    User(long n_ID, char* n_name, char n_gender, char* n_email, char* n_phone, char* user, char* pass ,char* add ,Date birth):
    ID(n_ID), name(n_name), gender(n_gender), email(n_email), phone(n_phone), username(user), password(pass), address(add), birthday(birth){}

    User(const User& copy): ID(copy.ID), name(copy.name), gender(copy.gender), email(copy.email), phone(copy.phone), username(copy.username),
    password(copy.password), address(copy.address), birthday(copy.birthday){}





};


#endif //FIELDSPROJECT_USER_H
