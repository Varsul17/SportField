//
// Created by Artiom on 19/02/2024.
//

#include "Field.h"

Field::Field(char* nameOfField,int sizeGolf,int sizeSoccer,int sizeBasketball,numOfField)
{
    nameOfField = new char[strlen(this->nameOfField)+1];
    strcpy_s(this->nameOfField,nameOfField);
    this->sizeGolf=sizeGolf;
    this->sizeSoccer=sizeSoccer;
    this->sizeBasketball=sizeBasketball;
    this->numOfField=numOfField
}

Field:Field(const Field &other)
{
    nameOfField = new char[strlen(other.nameOfField)+1];
    strcpy_s(nameOfField,other.nameOfField);
    sizeGolf=other.sizeGolf;
    sizeSoccer=other.sizeSoccer;
    sizeBasketball=other.sizeBasketball;
    numOfField=other.numOfField
}

Field::printDetails()
{
    cout<<"Field name: "<< nameOfField<<endl;
    cout<<"Golf field size: "<< sizeGolf<<endl;
    cout<<"Soccer field size: "<< sizeSoccer <<endl;
    cout<<"Basket ball field size: "<< sizeBasketball <<endl;
    cout << "Field number: "<< numOfField<<endl;

}

