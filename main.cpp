#include <iostream>
#include <wiringPi.h>
#include <thread>
#include <chrono>
#include <atomic>
#include <csignal>

#include "TestRunner.hpp"

#define GPIO_INPUT_1 0 // WiringPi 0 = BCM 17
#define GPIO_INPUT_2 2 // WiringPi 2 = BCM 27
#define GPIO_INPUT_3 3 // WiringPi 3 = BCM 22

std::atomic<bool> running(true);

void gpioCallback1() {
    std::cout << "GPIO 17 (Pin 11) -> LOW (Pressed)" << std::endl;
}

void gpioCallback2() {
    std::cout << "GPIO 27 (Pin 13) -> LOW (Pressed)" << std::endl;
}

void gpioCallback3() {
    std::cout << "GPIO 22 (Pin 15) -> LOW (Pressed)" << std::endl;
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
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void pinMonitorTask() {
    bool lastState1 = HIGH;
    bool lastState2 = HIGH;
    bool lastState3 = HIGH;

    while (running) {
        int state1 = digitalRead(GPIO_INPUT_1);
        int state2 = digitalRead(GPIO_INPUT_2);
        int state3 = digitalRead(GPIO_INPUT_3);

        if (state1 == HIGH && lastState1 == LOW) {
            std::cout << "GPIO 17 (Pin 11) -> HIGH (Released)" << std::endl;
        }
        if (state2 == HIGH && lastState2 == LOW) {
            std::cout << "GPIO 27 (Pin 13) -> HIGH (Released)" << std::endl;
        }
        if (state3 == HIGH && lastState3 == LOW) {
            std::cout << "GPIO 22 (Pin 15) -> HIGH (Released)" << std::endl;
        }

        lastState1 = state1;
        lastState2 = state2;
        lastState3 = state3;

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
