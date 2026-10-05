#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

// ============================================================
// Person : BASE CLASS pada Hierarchical Inheritance.
// Actor, Director, dan Writer sama-sama mewarisi kelas ini.
// ============================================================
class Person {
private:
    std::string name;
    int age;
    int debutYear;

public:
    Person(const std::string& name, int age, int debutYear)
        : name(name), age(age), debutYear(debutYear) {}

    const std::string& getName() const { return name; }
    int getAge() const { return age; }
    int getDebutYear() const { return debutYear; }

    void setName(const std::string& name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setDebutYear(int debutYear) { this->debutYear = debutYear; }

    // Method virtual; child dapat melakukan override untuk menentukan peran.
    virtual std::string getRole() const { return "Person"; }

    // Virtual -> child boleh menambah informasi (override),
    // lalu memanggil Person::displayInfo() untuk bagian yang sama.
    virtual void displayInfo() const {
        std::cout << "  * [" << getRole() << "] " << name << "\n";
        std::cout << "      Umur / Debut : " << age << " tahun / debut " << debutYear << "\n";
    }
};

#endif
