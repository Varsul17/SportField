//
// Created by Artiom on 19/02/2024.
//

#include <fstream>
#include "Field.h"

Field::Field(char* nameOfField,char* location,char* typeOfField,int length, int width,float pricePerHour)
{
    this->nameOfField = new char[strlen(nameOfField)+1];
    strcpy(this->nameOfField,nameOfField);

    this->location = new char[strlen(location)+1];
    strcpy(this->location,location);

    this->typeOfField = new char[strlen(typeOfField)+1];
    strcpy(this->typeOfField,typeOfField);

    this->width=width;
    this->length=length;
    this->pricePerHour=pricePerHour;
}


void Field::writeScheduleToFile()
{
    const ::string FILE_PATH = "C:\\Users\\Artiom\\Desktop\\SportField\\schedule list";
    ofstream scheduleFile(FILE_PATH, std::ios::app);
    if (!scheduleFile.is_open()) {
        cout << "Error opening schedule file." << endl;
        return;
    }
//    scheduleFile << "Field Name: " << nameOfField << endl;
//    scheduleFile << "Location: " << location << endl;
//    scheduleFile << "Type of Field: " << typeOfField << endl;
//    scheduleFile << "Available Time Slots: " << endl;
//
//    for (int hour = 8; hour <= 22; ++hour) {
//        scheduleFile << hour << ":00 - " << hour + 1 << ":00: " << endl;
//        scheduleFile << "Available "<<endl;
//    }
    scheduleFile << "+---------------------------------------+\n";
    scheduleFile << "| Field Name | Location | Type of Field |\n";
    scheduleFile << "+---------------------------------------+\n";
    scheduleFile << "| " << setw(11) << nameOfField << " | " << setw(8) << location << " | " << setw(13) << typeOfField << " |\n";
    scheduleFile << "+---------------------------------------+\n";
    scheduleFile << "| Available Time Slots                 |\n";
    scheduleFile << "+---------------------------------------+\n";

    // Print time slots
    for (int hour = 8; hour <= 22; ++hour) {
        scheduleFile << "| " << setw(2) << hour << ":00 - " << setw(2) << hour + 1 << ":00 | Available       |\n";
    }
    scheduleFile << endl;
    scheduleFile.close();
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

