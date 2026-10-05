#ifndef WRITER_H
#define WRITER_H

#include "Person.h"

// ============================================================
// Writer : CHILD class #3 dari Person (Hierarchical Inheritance)
// ============================================================
class Writer : public Person {
private:
    std::string penName;
    std::string specialtyGenre;

public:
    Writer(const std::string& name, int age, int debutYear,
           const std::string& penName, const std::string& specialtyGenre)
        : Person(name, age, debutYear),
          penName(penName), specialtyGenre(specialtyGenre) {}

    const std::string& getPenName() const { return penName; }
    const std::string& getSpecialtyGenre() const { return specialtyGenre; }

    void setPenName(const std::string& penName) { this->penName = penName; }
    void setSpecialtyGenre(const std::string& specialtyGenre) { this->specialtyGenre = specialtyGenre; }

    std::string getRole() const override { return "Writer"; }

    void displayInfo() const override {
        Person::displayInfo();
        std::cout << "      Nama Pena    : " << penName << "\n";
        std::cout << "      Spesialisasi : " << specialtyGenre << "\n";
    }
};

#endif
