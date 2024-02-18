/***********************************************************************
// Version 1.0
// Date: feb 18 2024
// Author: alex mwnaiki
***********************************************************************/

#ifndef FRIDGE_H
#define FRIDGE_H

#include <iostream>

const int FRIDGE_CAP = 5;
const int NAME_LEN = 20;

class Food {
public:
    char m_name[NAME_LEN + 1];
    double m_weight;
};

class Fridge {
private:
    char* m_model;
    int m_numFoods;
    Food m_foods[FRIDGE_CAP];

public:
    Fridge();
    Fridge(int nf, const char* mod = "Ice Age");
    ~Fridge();

    bool addFood(const Food& f);
    void changeModel(const char* m);

    bool fullFridge() const;
    bool findFood(const char* f) const;
    std::ostream& display(std::ostream& os = std::cout) const;
};

#endif
