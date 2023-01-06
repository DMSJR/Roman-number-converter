/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Functions.cpp
 * Author: marqu
 * 
 * Created on 6 de janeiro de 2023, 06:54
 */

#include "Functions.h"
#include <iostream>
#include <string>

Functions::Functions() {
}

Functions::Functions(const Functions& orig) {
}

Functions::~Functions() {
}

void Functions::menu(){
    int opc;
    cout << "Informe a Opcao desejada:\n";
    cout << "Para converter numeros arabicos em romanos digite 1\n";
    cout << "Para converter numeros romanos em arabicos digite 2\n";
    cin >> opc;
    
    if (opc == 1)
    {
        int num;
        cout << "Digite um numero positivo menor que 3999" << endl;
        cin >> num;

        if (num > 3999 || num < 1) {
            cout << "Valor inválido";
        }
        cout <<endl<<"Resultado da conversao: "<<to_roman(num);
    }
    else if (opc == 2){
        char num[12];
        cout << "Informe o numero em algarismos romanos: ";
        cin >> num;
        cout <<endl<<"Resultado da conversao: "<<to_arabic (num);
    }
    else 
        cout << "Opcao invalida";
}

string Functions::to_roman(int num){
    int numr10, numr100, numr1000, num1000;

        numr10 = num % 10;

        numr100 = ((num % 100) - numr10) / 10;
        numr1000 = ((num % 1000) - numr100 - numr10) / 100;
        num1000 = num / 1000;
       


        string u, d, c, m, r;
        if (numr10 <= 3) {
            for (int i = 1; i <= numr10; i++) {

                u = u + "I";
            }
        } else if (numr10 == 4) {
            u = "IV";
        } else if (numr10 == 5) {
            u = "V";
        } else if ((numr10 >= 6) && (numr10 < 9)) {
            u = "V";
            for (int i = 1; i <= (numr10 - 5); i++) {
                u = u + "I";
            }
        } else if (numr10 == 9) {
            u = "IX";
        }

        if (numr100 <= 3) {

            for (int i = 1; i <= numr100; i++) {
                d = d + "X";
            }
        } else if (numr100 == 4) {
            d = "XL";

        } else if (numr100 == 5) {
            d = "L";
        } else if ((numr100 >= 6)&&(numr100 <= 8)) {
            d = "L";
            for (int i = 1; i <= (numr100 - 5); i++) {
                d = d + "X";
            }
        } else if (numr100 == 9) {
            d = "XC";
        }

        if (numr1000 <= 3) {
            for (int i = 1; i <= numr1000; i++) {
                c = c + "C";
            }
        } else if (numr1000 == 4) {
            c = "CD";
        } else if (numr1000 == 5) {
            c = "D";
        } else if ((numr1000 >= 6)&&(numr1000 <= 8)) {
            c = "D";
            for (int i = 1; i <= (numr1000 - 5); i++) {
                c = c + "C";
            }
        } else if (numr1000 == 9) {
            c = "CM";
        }
        if ((num1000 <= 3)&&(num1000 > 0)) {

            for (int i = 1; i <= num1000; i++) {
                m = m + "M";

            }
        }
        r = m + c  + d  + u;
        return r;
}

int Functions::to_arabic (char num[12]){
    int u, d, c, m;
        
        int soma;
        for (int i = 0; i < 12; i++) {
            if (num[i] == 'I') {
                soma = soma + 1;
            } else if (num[i] == 'V') {
                soma = soma + 5;
            } else if (num[i] == 'X') {
                soma = soma + 10;
            } else if (num[i] == 'L') {
                soma = soma + 50;
            } else if (num[i] == 'C') {
                soma = soma + 100;
            } else if (num[i] == 'D') {
                soma = soma + 500;
            } else if (num[i] == 'M') {
                soma = soma + 1000;
            }
        }
        for (int i = 0; i < 12; i++) {
            if ((num[i] == 'I')&&(num[i + 1] == 'V')) {
                soma = soma - 2;
            } else if ((num[i] == 'I')&&(num[i + 1] == 'X')) {
                soma = soma - 2;
            } else if ((num[i] == 'X')&&(num[i + 1] == 'L')) {
                soma = soma - 20;
            } else if ((num[i] == 'X')&&(num[i + 1] == 'C')) {
                soma = soma - 20;
            } else if ((num[i] == 'C')&&(num[i + 1]) == 'D') {
                soma = soma - 200;
            } else if ((num[i] == 'C')&&(num[i + 1]) == 'M'){
                soma = soma - 200;
            }
        }
        
        return soma;
}