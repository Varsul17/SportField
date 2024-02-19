//
// Created by Artiom on 19/02/2024.
//

#ifndef USER_H_FIELD_H
#define USER_H_FIELD_H
using namespace std;
#include <iostream>
#include <cstring>

class Field {
protected:
    char* nameOfField;
    int sizeGolf,int sizeSoccer,int sizeBasketball, numOfField;

public:
    Field():nameOfField(nullptr),sizeGolf(0),sizeSoccer(0),sizeSoccer(0),sizeBasketBall(0),numOfField(0){}
    Field(char* nameOfField,int sizeGolf,int sizeSoccer,int sizeBasketball,numOfField);
    Field(const Field &other);
    virtual ~Field(){delete[] nameOfField;}
    virtual void printDetails();
    char* getNameOfField()const{return nameOfField;}
    int getSizeGolf()const{return sizeGolf;}
    int getSizeSoccer()const{return sizeSoccer;}
    int getSizeBasketball()const{return sizeBasketball;}
    int getNumOfField()const{return numOfField;}



};


#endif //USER_H_FIELD_H
