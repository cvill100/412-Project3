/**
 * @file main.cpp
 * @brief Entry point for the load balancer simulation.
 */

#include "LoadBalancer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

/**
 * @brief Main function for the load balancer simulation.
 * 
 * Prompts the user to enter the number of web servers and the runtime in cycles.
 * Initializes the load balancer with the specified number of servers and runs the simulation for the given runtime.
 * Randomly adds new requests to the queue during each cycle.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main() {
    srand(time(0)); // Seed the random number generator
    int numServers, runtime;

    std::cout << "Enter the number of web servers: ";
    std::cin >> numServers;
    std::cout << "Enter the runtime for the load balancer (cycles): ";
    std::cin >> runtime;

    LoadBalancer lb(numServers);

    // Initially fill the queue with requests
    for (int i = 0; i < numServers * 100; ++i) {
        lb.addRequest(Request());
    }

    std::cout << "Starting Queue Size: " << lb.getQueueSize() << std::endl;
    std::cout << "Request Time Range: 5-20 Clock Cycles" << std::endl;

    for (int t = 0; t < runtime; ++t) {
        std::cout << "====Clock Cycle: " << t << "====" << std::endl;
        lb.tickAllServers(); // decrement time in webservers with running tasks
        lb.balanceLoad(); // search for available servers to process next request
        std::cout << std::endl;

        // Randomly add a new request
        if (rand() % 10 < 3) { // 30% chance to add a new request each cycle
            lb.addRequest(Request());
        }
    }

    std::cout << "Ending Queue Size: " << lb.getQueueSize() << std::endl;

    return 0;
}
