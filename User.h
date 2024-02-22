#ifndef FIELDSPROJECT_USER_H
#define FIELDSPROJECT_USER_H
#include <iostream>
#include <cstring>
#include <string>
#include "Date.h"
#define AT_SIGN '@'
#define ASTERISK '*'
#define DOT '.'
#define UNDERLINE '_'
#define ENTER '\n'
#define SPACE ' '
#define NAME_LIM 20
#define ID_LIM 9
#define EMAIL_LIM 35
#define PHONE_LIM 10
#define ADDRESS_LIM 30
#define PUP_LIM 10
#define PASS_MIN 6
#define MAX 100

using namespace std;

class User {
public:
    static bool Check_Range(int start, int end, int num) { return ((num >= start) && (num <= end)); } // Checked
    static bool Check_Upper(char ch) { return ((ch >= 'A') && (ch <= 'Z')); } // Checked
    static bool Check_Lower(char ch) { return ((ch >= 'a') && (ch <= 'z')); } // Checked
    static char Lower_To_Upper(char ch) { return ch - 'a' + 'A'; } // Checked
    static bool Check_Number(char ch) { return ((ch >= '0') && (ch <= '9')); } // Checked
    static bool Check_Let(char ch) { return Check_Lower(ch) || Check_Upper(ch); }; // Checked
    static bool Blank_Line(int len); //Checked
    static bool Check_Name(char *); // Checked
    static char *Set_String(char *); // Checked
    void Set_Name(); //Checked
    void Set_Gender(); //Checked
    bool Set_Email(); // Checked
    bool Set_ID(); //Checked
    static void msg01() { cout << "Notice: name can only contain letters and be up to 20 characters" << endl; }//Checked
    static void msg02() {
        cout << "Notice: Email must be in the format: example@company.ending and up to 35 characters" << endl;
    } // Checked

protected:
    char *ID;
    char *first_name;
    char *last_name;
    char gender;
    char *email;
    char *phone;
    char *username;
    char *password;
    char *address;
    Date birthday; // change to char

public:
    User() {}

    User(char *n_ID, char *f_name, char *l_name, char n_gender, char *n_email, char *n_phone, char *user, char *pass,
         char *add, Date birth) :
            ID(n_ID), first_name(f_name), last_name(l_name), gender(n_gender), email(n_email), phone(n_phone),
            username(user), password(pass), address(add), birthday(birth) {}

    User(const User &copy) : ID(copy.ID), first_name(copy.first_name), last_name(copy.last_name), gender(copy.gender),
                             email(copy.email), phone(copy.phone), username(copy.username),
                             password(copy.password), address(copy.address), birthday(copy.birthday) {}

};


#endif //FIELDSPROJECT_USER_H
