#pragma once
// Ensures this header file is only included once during compilation


#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

class Vet;  
// Forward declaration so Animal can declare Vet as friend


// =====================================================
// Base class representing a generic animal in the system
// =====================================================
class Animal {
protected:
    string name;
    string species;
    int age;
    bool isHealthy;

public:
    // Basic constructor shared by all animals
    // 'h' defaults to true, meaning animal starts healthy unless specified
    Animal(string n, string s, int a, bool h = true)
        : name(n), species(s), age(a), isHealthy(h) {}

    // Virtual destructor because we're going to inherit from this class
    virtual ~Animal() {}

    // Pure virtual functions force child classes to implement them
    virtual void makeSound() const = 0;
    virtual void eat() const = 0;

    // Shared function that prints a summary of the animal's status
    virtual void displayInfo() const {
        cout << "Name: " << name << ", Species: " << species
             << ", Age: " << age << ", Health: "
             << (isHealthy ? "Healthy" : "Sick") << endl;
    }

    // Simple getters
    int getAge() const { return age; }
    string getName() const { return name; }

    // Vet needs access to private/protected data (age, health, etc.)
    friend class Vet;
};


// =====================================================
// Herbivore base class — eats plants
// =====================================================
class Herbivore : public Animal {
public:
    Herbivore(string n, string s, int a, bool h = true)
        : Animal(n, s, a, h) {}

    // Generic herbivore eating behavior
    void eat() const override { cout << name << " grazes on plants.\n"; }
};


// =====================================================
// Carnivore base class — eats meat
// =====================================================
class Carnivore : public Animal {
public:
    Carnivore(string n, string s, int a, bool h = true)
        : Animal(n, s, a, h) {}

    // Generic carnivore eating behavior
    void eat() const override { cout << name << " eats meat.\n"; }
};


// =====================================================
// Feline subclass — big cats, small cats, etc.
// =====================================================
class Feline : public Carnivore {
public:
    Feline(string n, string s, int a, bool h = true)
        : Carnivore(n, s, a, h) {}

    // Cat-like vocalization override
    void makeSound() const override { cout << name << " roars or meows.\n"; }
};


// =====================================================
// Canine subclass — dogs, wolves, etc.
// =====================================================
class Canine : public Carnivore {
public:
    Canine(string n, string s, int a, bool h = true)
        : Carnivore(n, s, a, h) {}

    // Dog-like vocalization
    void makeSound() const override { cout << name << " barks or howls.\n"; }
};


// =====================================================
// Bovine subclass — cows and similar animals
// =====================================================
class Bovine : public Herbivore {
public:
    Bovine(string n, string s, int a, bool h = true)
        : Herbivore(n, s, a, h) {}

    // Cow sound override
    void makeSound() const override { cout << name << " moos gently.\n"; }
};


// =====================================================
// Equine subclass — horses, etc.
// =====================================================
class Equine : public Herbivore {
public:
    Equine(string n, string s, int a, bool h = true)
        : Herbivore(n, s, a, h) {}

    // Horse sound
    void makeSound() const override { cout << name << " neighs loudly.\n"; }
};


// =====================================================
// Vet class — gets direct access to Animal internals via 'friend'
// =====================================================
class Vet {
public:
    // Inspects an animal and prints its internal health/age directly
    void inspectAnimal(const Animal& a) const {
        cout << "Inspecting " << a.name << " (" << a.species
             << "), Age: " << a.age
             << ", Health: " << (a.isHealthy ? "Healthy" : "Sick") << endl;
    }

    // Allows the vet to heal sick animals by modifying their internals
    void healAnimal(Animal& a) const {
        if (!a.isHealthy) {
            cout << "Healing " << a.name << "...\n";
            a.isHealthy = true;
        }
    }

    // Vet can age the animal (because of friend access)
    void increaseAge(Animal& a, int years) const {
        a.age += years;
    }
};


// =====================================================
// Ecosystem: templated container that manages a group of animals
// Works with shared_ptr so memory is automatically cleaned up
// =====================================================
template <typename T>
class Ecosystem {
private:
    vector<shared_ptr<T>> animals;   // Store multiple animals of type T

public:
    // Add a new animal into the ecosystem
    void addAnimal(shared_ptr<T> animal) {
        animals.push_back(animal);
    }

    // Allows external code to access the list of animals directly
    vector<shared_ptr<T>>& getAnimals() {
        return animals;
    }

    // Print summary of every animal in the ecosystem
    void showAllAnimals() const {
        cout << "\n--- Animals ---\n";
        for (const auto& a : animals)
            a->displayInfo();
    }
};

