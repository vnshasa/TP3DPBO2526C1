#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Person.h"

// ============================================================
// Director : CHILD class #2 dari Person (Hierarchical Inheritance)
// ============================================================
class Director : public Person {
private:
    std::string signatureStyle;
    int awardsWon;

public:
    Director(const std::string& name, int age, int debutYear,
             const std::string& signatureStyle, int awardsWon)
        : Person(name, age, debutYear),
          signatureStyle(signatureStyle), awardsWon(awardsWon) {}

    const std::string& getSignatureStyle() const { return signatureStyle; }
    int getAwardsWon() const { return awardsWon; }

    void setSignatureStyle(const std::string& signatureStyle) { this->signatureStyle = signatureStyle; }
    void setAwardsWon(int awardsWon) { this->awardsWon = awardsWon; }

    std::string getRole() const override { return "Director"; }

    void displayInfo() const override {
        Person::displayInfo();
        std::cout << "      Gaya Khas    : " << signatureStyle << "\n";
        std::cout << "      Penghargaan  : " << awardsWon << " piala\n";
    }
};

#endif
