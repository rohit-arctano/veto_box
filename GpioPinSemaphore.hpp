#ifndef GPIOPINSEMAPHORE_HPP
#define GPIOPINSEMAPHORE_HPP

#include <iostream>
#include <string>
#include <mutex>

extern std::string lastState1;
extern std::string lastState2;
extern std::string lastState3;
extern bool interupt;
extern std::int16_t peridicTime;

extern std::mutex mtx1;
extern std::mutex mtx2;
extern std::mutex mtx3;
extern std::mutex mtIntrp;
extern std::mutex mtperiod;

#endif // GPIOPINSEMAPHORE_HPP