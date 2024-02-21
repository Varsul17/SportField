//
// Created by Artiom on 19/02/2024.
//

#include "Field.h"

Field::Field(char* nameOfField,char* location,char* typeOfField,int length, int width,float pricePerHour)
{
    this->nameOfField = new char[strlen(this->nameOfField)+1];
    strcpy(this->nameOfField,nameOfField);

    this->location = new char[strlen(this->location)+1];
    strcpy(this->location,location);

    this->typeOfField = new char[strlen(this->typeOfField)+1];
    strcpy(this->typeOfField,typeOfField);

    this->width=width;
    this->length=length;
    this->pricePerHour=pricePerHour;
}

Field::Field(const Field &other)
{
    nameOfField = new char[strlen(other.nameOfField)+1];
    strcpy(nameOfField,other.nameOfField);

    location = new char[strlen(other.location)+1];
    strcpy(location,other.location);

    typeOfField = new char[strlen(other.typeOfField)+1];
    strcpy(typeOfField,other.typeOfField);

    width=other.width;
    length=other.length;
    pricePerHour=other.pricePerHour;
}

void Field::printDetails()
{
    cout << "Field Name: " << nameOfField << endl;
    cout << "Location: " << location << endl;
    cout << "Type: " << typeOfField << endl;
    cout << "Length: " << length << endl;
    cout << "Width: " << width << endl;
    cout << "Price per hour is: " << pricePerHour << endl;
}

