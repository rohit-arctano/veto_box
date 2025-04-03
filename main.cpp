#include <iostream>
#include <wiringPi.h>
#include <thread>
#include <chrono>
#include <atomic>
#include <csignal>
#include "GpioPinSemaphore.hpp"
#include "TestRunner.hpp"

#define GPIO_INPUT_1 0 // WiringPi 0 = BCM 17
#define GPIO_INPUT_2 2 // WiringPi 2 = BCM 27
#define GPIO_INPUT_3 3 // WiringPi 3 = BCM 22



std::atomic<bool> running(true);

void gpioCallback1() {
    // std::cout << "GPIO 17 (Pin 11) -> LOW (Pressed)" << std::endl;
}

void gpioCallback2() {
    // std::cout << "GPIO 27 (Pin 13) -> LOW (Pressed)" << std::endl;
}

void gpioCallback3() {
    // std::cout << "GPIO 22 (Pin 15) -> LOW (Pressed)" << std::endl;
}

void gpioTask() {
    wiringPiSetup();

    pinMode(GPIO_INPUT_1, INPUT);
    pullUpDnControl(GPIO_INPUT_1, PUD_UP);
    wiringPiISR(GPIO_INPUT_1, INT_EDGE_FALLING, &gpioCallback1);

    pinMode(GPIO_INPUT_2, INPUT);
    pullUpDnControl(GPIO_INPUT_2, PUD_UP);
    wiringPiISR(GPIO_INPUT_2, INT_EDGE_FALLING, &gpioCallback2);

    pinMode(GPIO_INPUT_3, INPUT);
    pullUpDnControl(GPIO_INPUT_3, PUD_UP);
    wiringPiISR(GPIO_INPUT_3, INT_EDGE_FALLING, &gpioCallback3);

    while (running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

#include "GpioPinSemaphore.hpp"

void pinMonitorTask() {
    while (running) {
        int state1 = digitalRead(GPIO_INPUT_1);
        int state2 = digitalRead(GPIO_INPUT_2);
        int state3 = digitalRead(GPIO_INPUT_3);

        std::string newState1 = (state1 == HIGH) ? "1" : "0";
        std::string newState2 = (state2 == HIGH) ? "1" : "0";
        std::string newState3 = (state3 == HIGH) ? "1" : "0";

        // Lock the mutex for each state before updating the corresponding state
        {
            std::lock_guard<std::mutex> lock(mtx1);  // Lock for lastState1
            if (newState1 != lastState1) {
                lastState1 = newState1;
                std::lock_guard<std::mutex> lock(mtIntrp);
                interupt =true;
                std::lock_guard<std::mutex> lock2(mtperiod);
                peridicTime =0;

                // Lock for lastState1
                
            }
        }

        {
            std::lock_guard<std::mutex> lock(mtx2);  // Lock for lastState2
            if (newState2 != lastState2) {
                lastState2 = newState2;
                std::lock_guard<std::mutex> lock(mtIntrp);
                interupt =true;
                std::lock_guard<std::mutex> lock2(mtperiod);
                peridicTime =0;
            }
        }

        {
            std::lock_guard<std::mutex> lock(mtx3);  // Lock for lastState3
            if (newState3 != lastState3) {
                lastState3 = newState3;
                std::lock_guard<std::mutex> lock(mtIntrp);
                interupt =true;
                std::lock_guard<std::mutex> lock2(mtperiod);
                peridicTime =0;
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void signalHandler(int signum) {
    std::cout << "Interrupt signal (" << signum << ") received.\n";
    running = false;
}

int main() {
    std::cout << "Starting my app with GPIO + DDS" << std::endl;

    signal(SIGINT, signalHandler);

    std::thread gpioThread(gpioTask);
    std::thread monitorThread(pinMonitorTask);

    run_dds_app("publisher"); // Blocking

    running = false;
    gpioThread.join();
    monitorThread.join();

    std::cout << "Application exiting." << std::endl;
    return 0;
}
