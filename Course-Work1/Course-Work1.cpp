#include <iostream>
#include <string>

using namespace std;

class Animal {

protected:
	string name = " ";
	int age = 0;

public:
    Animal() : name("Unknown"), age(0) {}
    Animal(string n, int a = 1) : name(n), age(a) {}
    virtual ~Animal() {}

    // Собствени методи
    void breathe() { cout << name << " is breathing..." << endl; }
    void sleep() { cout << name << " is sleeping Zzz..." << endl; }

    // Виртуален метод за информация
    virtual void printInfo() {
        cout << "Animal: " << name << ", Age: " << age << endl;
    }
};




};