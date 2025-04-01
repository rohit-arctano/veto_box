#include "GpioPinSemaphore.hpp"

std::string lastState1;
std::string lastState2;
std::string lastState3;
bool interupt;
std::int peridicTime;

std::mutex mtx1;
std::mutex mtx2;
std::mutex mtx3;
std::mutex mtIntrp;
std::mutex mtperiod;