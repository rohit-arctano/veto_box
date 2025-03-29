

#include "TestRunner.hpp"
#include "TestApplication.hpp"
#include <csignal>
#include <iostream>
#include <thread>
#include <memory>

using eprosima::fastdds::dds::Log;

std::function<void(int)> stop_handler;
void signal_handler(int signum)
{
    stop_handler(signum);
}

std::string parse_signal(const int& signum)
{
    switch (signum)
    {
        case SIGINT:
            return "SIGINT";
        case SIGTERM:
            return "SIGTERM";
#ifndef _WIN32
        case SIGQUIT:
            return "SIGQUIT";
        case SIGHUP:
            return "SIGHUP";
#endif // _WIN32
        default:
            return "UNKNOWN SIGNAL";
    }
}

void run_dds_app(const std::string& mode)
{
    int domain_id = 0;
    auto app = TestApplication::make_app(domain_id, mode.c_str());

    std::thread thread(&TestApplication::run, app);

    std::cout << mode << " running. Press Ctrl+C to stop..." << std::endl;

    stop_handler = [&](int signum)
            {
                std::cout << "\n" << parse_signal(signum) << " received, stopping " << mode << "." << std::endl;
                app->stop();
            };

    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
#ifndef _WIN32
    signal(SIGQUIT, signal_handler);
    signal(SIGHUP, signal_handler);
#endif // _WIN32

    thread.join();
    Log::Reset();
}
