#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
    string name;
    int age;

public:
    Animal() : name("Unknown"), age(0) {}
    Animal(string n, int a = 1) : name(n), age(a) {}
    virtual ~Animal() {}

    void breathe() { cout << name << " is breathing..." << endl; }
    void sleep() { cout << name << " is sleeping." << endl; }

    virtual void printInfo() = 0;
};

class Mammal : public Animal {
protected:
    string furColor;
    bool isDomestic;

public:
    Mammal() : Animal(), furColor("Brown"), isDomestic(true) {}
    Mammal(string n, int a, string fur, bool domestic = true)
        : Animal(n, a), furColor(fur), isDomestic(domestic) {
    }

    void walk() { cout << name << " is walking on 4 legs." << endl; }
    void makeNoise() { cout << name << " makes a mammal sound." << endl; }

    void printInfo() override {
        cout << "[Mammal] Name: " << name << ", Age: " << age << ", Fur: " << furColor << endl;
    }
};

class Dog : public Mammal {
public:
    Dog() : Mammal("Sharo", 1, "Black") {}
    Dog(string n, int a) : Mammal(n, a, "Golden") {}
    void bark() { cout << name << " says: Woof-woof!" << endl; }
    void wagTail() { cout << name << " is wagging its tail." << endl; }
    void printInfo() override { cout << "[Dog] Name: " << name << " (Man's best friend)" << endl; }
};

class Cat : public Mammal {
protected:
    string breed;
public:
    Cat() : Mammal(), breed("Street Cat") {}
    Cat(string n, int a, string b, string fur = "Orange")
        : Mammal(n, a, fur), breed(b) {
    }

    void meow() { cout << name << " says: Meow!" << endl; }
    void purr() { cout << name << " is purring: Prrr..." << endl; }

    void printInfo() override {
        cout << "[Cat] Name: " << name << ", Breed: " << breed << ", Fur: " << furColor << endl;
    }
};

class Bird : public Animal {
protected:
    double wingSpan;
public:
    Bird() : Animal(), wingSpan(0.5) {}
    Bird(string n, int a, double span = 1.0) : Animal(n, a), wingSpan(span) {}

    void fly() { cout << name << " is flying high!" << endl; }
    void layEgg() { cout << name << " laid an egg." << endl; }

    void printInfo() override {
        cout << "[Bird] Name: " << name << ", Wing Span: " << wingSpan << "m" << endl;
    }
};

class Eagle : public Bird {
public:
    Eagle() : Bird("Eagle", 2, 2.0) {}
    Eagle(string n, int a, double span) : Bird(n, a, span) {}
    void hunt() { cout << name << " is diving to hunt!" << endl; }
    void screech() { cout << name << " screeches loudly!" << endl; }
    void printInfo() override { cout << "[Eagle] King of birds: " << name << endl; }
};

class GoldenEagle : public Eagle {
public:
    GoldenEagle() : Eagle("Goldie", 3, 2.5) {}
    GoldenEagle(string n, int a) : Eagle(n, a, 2.5) {}
    void showGoldenFeathers() { cout << name << " displays golden feathers." << endl; }
    void territoryPatrol() { cout << name << " is patrolling its territory." << endl; }
    void printInfo() override { cout << "[Golden Eagle] Rare species: " << name << endl; }
};

int main() {
    const int SIZE = 5;
    Animal* zoo[SIZE];

    zoo[0] = new Cat("Tom", 3, "British Shorthair");
    zoo[1] = new Dog("Rex", 5);
    zoo[2] = new Bird("Tweety", 1, 0.2);
    zoo[3] = new Eagle("Aquila", 4, 2.1);
    zoo[4] = new GoldenEagle("Goldie", 2);

    for (int i = 0; i < SIZE; i++) {
        zoo[i]->printInfo();

        if (Cat* c = dynamic_cast<Cat*>(zoo[i])) {
            c->meow();
        }
        else if (Dog* d = dynamic_cast<Dog*>(zoo[i])) {
            d->bark();
        }
        else if (GoldenEagle* ge = dynamic_cast<GoldenEagle*>(zoo[i])) {
            ge->showGoldenFeathers();
        }
        else if (Eagle* e = dynamic_cast<Eagle*>(zoo[i])) {
            e->hunt();
        }
        else if (Bird* b = dynamic_cast<Bird*>(zoo[i])) {
            b->fly();
        }

        cout << "----------------------------------------" << endl;
    }

    for (int i = 0; i < SIZE; i++) {
        delete zoo[i];
    }

    return 0;
}