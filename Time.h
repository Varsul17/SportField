//
// Created by Artiom on 20/02/2024.
//

#ifndef YESODOTFIELD_TIME_H
#define YESODOTFIELD_TIME_H
using namespace std;
#include <iostream>
#include <cstring>

class Time {
protected:
    int hours;
    int minutes;

public:
    Time():hours(0),minutes(0){}
    Time(int hours,int minutes){this->hours=hours; this->minutes=minutes;}
    Time(const Time& other){hours=other.hours; minutes=other.minutes;}
    virtual void printDetails()const{cout<<"Hours: "<<hours<<endl; cout<<"Minutes: "<<minutes<<endl;}
    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    bool operator>=(const Time &other) const
    {
        if (hours > other.hours || (hours == other.hours && minutes >= other.minutes))
        {
            return true;
        }
        return false;
    }

    bool operator<=(const Time &other) const
    {
        if (hours < other.hours || (hours == other.hours && minutes <= other.minutes)) {
            return true;
        }
        return false;
    }

};


#endif //YESODOTFIELD_TIME_H
