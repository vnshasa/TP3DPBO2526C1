#ifndef ACTOR_H
#define ACTOR_H

#include "Person.h"

// ============================================================
// Actor : CHILD class #1 dari Person (Hierarchical Inheritance)
// ============================================================
class Actor : public Person {
private:
    std::string agency;
    std::string characterName;  // nama karakter yang diperankan di drama ini
    std::string roleType;       // Lead / Second Lead / Supporting

public:
    Actor(const std::string& name, int age, int debutYear,
          const std::string& agency,
          const std::string& characterName,
          const std::string& roleType)
        : Person(name, age, debutYear),
          agency(agency), characterName(characterName), roleType(roleType) {}

    const std::string& getAgency() const { return agency; }
    const std::string& getCharacterName() const { return characterName; }
    const std::string& getRoleType() const { return roleType; }

    void setAgency(const std::string& agency) { this->agency = agency; }
    void setCharacterName(const std::string& characterName) { this->characterName = characterName; }
    void setRoleType(const std::string& roleType) { this->roleType = roleType; }

    std::string getRole() const override { return "Actor"; }

    void displayInfo() const override {
        Person::displayInfo();
        std::cout << "      Karakter     : " << characterName << " (" << roleType << ")\n";
        std::cout << "      Agensi       : " << agency << "\n";
    }
};

#endif
