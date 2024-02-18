/***********************************************************************
// OOP244 Workshop #4 p1: tester program
//
// File	Fridge.cpp
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

Fridge::Fridge() {
    m_model = nullptr;
    m_numFoods = 0;
}

Fridge::Fridge(int nf, const char* mod) {
    m_model = nullptr;
    m_numFoods = 0;

    if (nf > 0 && mod != nullptr && *mod != '\0') {
        m_numFoods = nf;
        m_model = new char[strlen(mod) + 1];
        strcpy(m_model, mod);

        for (int i = 0; i < nf && i < FRIDGE_CAP; i++) {
            m_foods[i] = Food();
        }
    }
}

Fridge::~Fridge() {
    delete[] m_model;
}

bool Fridge::addFood(const Food& f) {
    if (m_numFoods < FRIDGE_CAP) {
        m_foods[m_numFoods] = f;
        m_numFoods++;
        return true;
    }
    return false;
}

void Fridge::changeModel(const char* m) {
    if (m != nullptr && *m != '\0') {
        delete[] m_model;
        m_model = new char[strlen(m) + 1];
        strcpy(m_model, m);
    }
}

bool Fridge::fullFridge() const {
    return m_numFoods == FRIDGE_CAP;
}

bool Fridge::findFood(const char* f) const {
    for (int i = 0; i < m_numFoods; i++) {
        if (strcmp(m_foods[i].m_name, f) == 0) {
            return true;
        }
    }
    return false;
}

std::ostream& Fridge::display(std::ostream& os) const {
    if (m_model == nullptr) {
        return os;
    }

    os << "Fridge Model: " << m_model << '\n';
    os << "Food count: " << m_numFoods << " Capacity: " << FRIDGE_CAP << '\n';
    os << "List of Foods" << '\n';

    for (int i = 0; i < m_numFoods; i++) {
        os.width(NAME_LEN);
        os << m_foods[i].m_name << " | " << m_foods[i].m_weight << '\n';
    }

    return os;
}