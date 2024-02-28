//
// Created by segev on 2/21/2024.
//

#include "DataBase.h"
#define NumberOfColl 9




DataBase::DataBase()
{
    const std::string FILE_PATH = "C:\\Users\\segev\\CLionProjects\\SportField\\players list";
    {
        mainDate.open(FILE_PATH, std::ios::in);

        if (!mainDate) {
            std::cout << "Error: Unable to open file " << FILE_PATH << std::endl;
            return;
        }

        counter = 0;
        char temp[300];

        // Use mainDate.peek() to check for end-of-file
        while (mainDate.peek() != EOF) {
            mainDate.getline(temp, 300);
            counter++;
        }

        matrix = new char** [counter];
        mainDate.clear(); // Clear the end-of-file flag
        mainDate.seekg(0, std::ios::beg);

        for (int i = 0; i < counter; ++i)
        {
            matrix[i] = new char* [NumberOfColl];
            mainDate.getline(temp, 300);
            int k = 0;

            for (int j = 0; j < NumberOfColl; ++j)
            {
                char tempCopy[30];
                int w = 0;

                while (temp[k] != ' ' && temp[k] != '\0')
                {
                    tempCopy[w] = temp[k];
                    k++;
                    w++;
                }
                tempCopy[w] = '\0';
                matrix[i][j] = new char[strlen(tempCopy)+1];
                strcpy(matrix[i][j],tempCopy);
                k++;
            }
        }

        for (int i = 0; i < counter; ++i)
        {
            for (int j = 0; j < NumberOfColl; ++j)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    mainDate.close();
}



DataBase::~DataBase() {

    std::cout << "detractor" << std::endl;

    const std::string FILE_PATH = "C:\\Users\\segev\\CLionProjects\\SportField\\players list";
    std::ofstream ofs(FILE_PATH, std::ofstream::out | std::ofstream::trunc);

    std::cout<< "fuck1" << std::endl;

    if (!ofs.is_open()) {
        std::cerr << "Error: Unable to open file " << FILE_PATH << std::endl;
        return;
    }

    std::cout<< "fuck2" << std::endl;

    for (int i = 0; i < counter; ++i)
    {
        for (int j = 0; j < NumberOfColl; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout<< "fuck3" << std::endl;


    for (int i = 0; i < counter; ++i) {
        bool hasData = false;
        for (int j = 0; j < NumberOfColl; ++j)
        {
            if (strcmp(matrix[i][j],"$") != 0)
            {
                ofs << matrix[i][j] << ' ';
                hasData = true;
            }
        }
        if (hasData) {
            ofs << std::endl;
        }
    }
    std::cout<< "fuck4" << std::endl;


    mainDate.close();

    std::cout<< "fuck5" << std::endl;


    for (int i = 0; i < counter-1; ++i)
    {
        for (int j = 0; j < NumberOfColl; ++j)
        {
            delete[] matrix[i][j];
        }
        delete[] matrix[i];
    }
    delete[] matrix;
}









//DataBase& DataBase::operator=(const DataBase& other) {
//    if (this != &other) { // Avoid self-assignment
//
//        // Release existing resources
//        for (int i = 0; i < counter-1; ++i)
//        {
//            for (int j = 0; j < NumberOfColl; ++j)
//            {
//                delete[] matrix[i][j];
//            }
//            delete[] matrix[i];
//        }
//        delete[] matrix;
//
//
//        // Allocate new memory
//        matrix = new char**[counter];
//
//        // Copy data
//        for (int i = 0; i < counter; ++i)
//        {
//            matrix[i] = new char*[NumberOfColl];
//
//            for (int j = 0; j < NumberOfColl; ++j)
//            {
//                matrix[i][j] = new char[strlen(other.matrix[i][j]) + 1];
//                strcpy(matrix[i][j], other.matrix[i][j]);
//            }
//        }
//    }
//}