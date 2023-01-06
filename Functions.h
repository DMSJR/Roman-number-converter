/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Functions.h
 * Author: marqu
 *
 * Created on 6 de janeiro de 2023, 06:54
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
using namespace std;
class Functions {
public:
    Functions();
    Functions(const Functions& orig);
    virtual ~Functions();
    void menu();
    int to_arabic(char num[12]);
    string to_roman (int num);
private:

};

#endif /* FUNCTIONS_H */

