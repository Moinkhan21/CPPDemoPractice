#include <iostream>  // Header file for input and output operations (cout)
using namespace std;

/*
    CLASS: Animal (Base Class)
    --------------------------
    - This is the parent class that represents a generic animal.
    - It contains:
        → A constructor to initialize when an object is created.
        → A virtual function 'speak()' which can be overridden in derived classes.
*/
class Animal {
public:
    // Constructor of Animal class
    Animal() {
        cout << "I am inside animal constructor" << endl;
    }

    /*
        Virtual Function:
        -----------------
        - Declared with the keyword 'virtual' to allow dynamic (runtime) polymorphism.
        - If a derived class overrides this function, the derived version is called
          when accessed through a base class pointer or reference.
    */
    virtual void speak() {
        cout << "Speaking... " << endl;
    }
};

/*
    CLASS: Dog (Derived Class)
    --------------------------
    - The 'Dog' class inherits publicly from the 'Animal' class.
    - This means:
        → All public members of Animal become public in Dog.
        → All protected members of Animal become protected in Dog.
    - The Dog class overrides the 'speak()' function and has its own constructor.
*/
class Dog : public Animal {
public:
    // Constructor of Dog class
    Dog() {
        cout << "I am inside dog constructor" << endl;
    }

    /*
        Function Overriding:
        --------------------
        - The Dog class redefines the 'speak()' function from the Animal class.
        - Because 'speak()' in Animal is declared as virtual, this version
          will be called when a Dog object is accessed via a Dog pointer
          or through runtime polymorphism.
    */
    void speak() {
        cout << "Barking... " << endl;
    }
};

int main() {

    /*
        Step 1: Creating an Animal object dynamically
        ---------------------------------------------
        - 'new Animal()' allocates memory for an Animal object on the heap.
        - The Animal constructor runs automatically when the object is created.
        - The pointer 'a' stores the address of this dynamically created object.
    */
    Animal* a = new Animal();
    // Output: "I am inside animal constructor"

    /*
        Step 2: Creating a Dog object dynamically
        -----------------------------------------
        - Since Dog inherits from Animal, when we create a Dog object:
            1. The Animal constructor runs first (base class).
            2. Then the Dog constructor runs (derived class).
        - This ensures that the base part of the object is properly initialized.
    */
    Dog* b = new Dog();
    // Output:
    // "I am inside animal constructor"
    // "I am inside dog constructor"

    /*
        Step 3: Program ends
        --------------------
        - No destructor is explicitly defined in the classes.
        - Since we used 'new' to allocate memory, we should use 'delete' to free it.
          (Though omitted here, it’s good practice to include it to prevent memory leaks.)
    */
    delete a;  // Frees memory allocated for Animal object
    delete b;  // Frees memory allocated for Dog object

    return 0;  // Successful program termination
}
