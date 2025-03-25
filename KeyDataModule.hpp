#ifndef KEYDATAMODULE_H  // Prevent multiple inclusions
#define KEYDATAMODULE_H

#include <iostream>

class KeyDataModule {
public:
    int k1;
    int k2;
    int k3;

    // Constructor
    KeyDataModule(int val1, int val2, int val3);

    // Method to display values
    void display() const;
};

#endif // KEYDATAMODULE_H
