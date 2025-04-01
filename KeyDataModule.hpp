#ifndef KEYDATAMODULE_H  // Prevent multiple inclusions
#define KEYDATAMODULE_H

#include <iostream>

class KeyDataModule {
public:
std::string k1;  // k1 as string
std::string k2;  // k2 as string
std::string k3;  // k3 as string


    // Constructor
    KeyDataModule(const std::string& val1, const std::string& val2, const std::string& val3);

    // Method to display values
    void display() const;
};

#endif // KEYDATAMODULE_H
