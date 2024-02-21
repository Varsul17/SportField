//
// Created by Artiom on 20/02/2024.
//

#ifndef YESODOTFIELD_BRANCH_H
#define YESODOTFIELD_BRANCH_H
#include "Field.h"

class Branch {
protected:
    Field** fieldArray;
    int branchId;
    int sizeFieldArray;
    Time TimeOpening;
    Time TimeClosing;
public:
    Branch():fieldArray(nullptr),branchId(0),sizeFieldArray(0){}
    ~Branch(){
        for (int i = 0; i < sizeFieldArray; ++i)
        {
            delete fieldArray[i];
        }
        delete [] fieldArray;
    }
    int getBranchID()const{return branchId;}
    int getSizeFieldArray()const{return sizeFieldArray;}
    void printDetails()const;
    Branch &operator +=(Field* object);
    void removeField(Field* object);
    Time getTimeOpening()const {return TimeOpening;}
    Time getTimeClosing()const {return TimeClosing;}
    bool ifIsOpen(const Time &currentTime) const {
        if (currentTime >= TimeOpening && currentTime <= TimeClosing) {
            return true;  // Branch is open
        }
        else
        {
            cout << "The branch is currently closed." << endl;
            return false;  // Branch is closed
        }
    }
};


#endif //YESODOTFIELD_BRANCH_H
