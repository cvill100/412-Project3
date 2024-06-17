/**
 * @file LoadBalancer.cpp
 * @brief Implements the LoadBalancer class that manages web servers and the request queue.
 */

#include "LoadBalancer.h"
#include "Request.h"
#include <iostream>

/**
 * @brief Constructs a LoadBalancer with the specified number of web servers.
 * @param numServers The number of web servers.
 */
LoadBalancer::LoadBalancer(int numServers) {
    webServers.resize(numServers);
}

/**
 * @brief Adds a request to the request queue.
 * @param request The request to add.
 */
void LoadBalancer::addRequest(const Request& request) {
    requestQueue.addRequest(request);
}

/**
 * @brief Balances the load by assigning requests to available servers.
 * 
 * Iterates through the list of web servers and assigns a request to each available server.
 * Prints the processing details for each request assigned to a server.
 */
void LoadBalancer::balanceLoad() {
    for (size_t i = 0; i < webServers.size(); i++) {
        auto *server = &webServers.at(i);
        if (server->isAvailable() && !requestQueue.isEmpty()) {
            Request currRequest = requestQueue.getNextRequest();
            std::cout << "Processing request with time " << currRequest.getTime() << " on web server " << i << std::endl;
            server->processRequest(currRequest);
        }
    }
}

/**
 * @brief Simulates the passage of time for all servers by decrementing their remaining processing time.
 */
void LoadBalancer::tickAllServers() {
    for (auto& server : webServers) {
        server.tick();
    }
}

/**
 * @brief Gets the current size of the request queue.
 * @return The number of requests in the queue.
 */
size_t LoadBalancer::getQueueSize() {
    return requestQueue.getSize();
}
