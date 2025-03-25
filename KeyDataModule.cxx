#include "KeyDataModule.hpp"

// Constructor Implementation
KeyDataModule::KeyDataModule(int val1, int val2, int val3) : k1(val1), k2(val2), k3(val3) {}

// Method Implementation
void KeyDataModule::display() const {  // Added `const`
    std::cout << "k1: " << k1 << ", k2: " << k2 << ", k3: " << k3 << std::endl;
}
