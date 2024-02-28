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

};


#endif //YESODOTFIELD_BRANCH_H
