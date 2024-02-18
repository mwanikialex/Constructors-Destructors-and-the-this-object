/***********************************************************************
// OOP244 Workshop #4 p1: tester program
//
// File	main.cpp
// Version 1.0
// Date: 
// Author:
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "Fridge.h"
#include <cstring>
/* I have done all the coding by myself  */ 
/* and only copied the code that my professor provided to complete my workshops and assignments. */
int main() {
    Fridge fridge(3, "Unfilled Fridge");

    Food f1;
    strcpy(f1.m_name, "Apple");
    f1.m_weight = 2;
    fridge.addFood(f1);

    Food f2;
    strcpy(f2.m_name, "Banana");
    f2.m_weight = 3;
    fridge.addFood(f2);

    Food f3;
    strcpy(f3.m_name, "Orange");
    f3.m_weight = 0.25;
    fridge.addFood(f3);

    fridge.display();

    return 0;
}