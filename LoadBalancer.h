/**
 * @file LoadBalancer.h
 * @brief Defines the LoadBalancer class that manages web servers and the request queue.
 */

#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "RequestQueue.h"
#include "WebServer.h"
#include <vector>

/**
 * @class LoadBalancer
 * @brief Manages web servers and the request queue to balance load.
 */
class LoadBalancer {
public:
    /**
     * @brief Constructs a LoadBalancer with the specified number of web servers.
     * @param numServers The number of web servers.
     */
    LoadBalancer(int numServers);

    /**
     * @brief Adds a request to the request queue.
     * @param request The request to add.
     */
    void addRequest(const Request& request);

    /**
     * @brief Balances the load by assigning requests to available servers.
     */
    void balanceLoad();

    /**
     * @brief Simulates the passage of time for all servers by decrementing their remaining processing time.
     */
    void tickAllServers(); // Tick all servers

    /**
     * @brief Gets the current size of the request queue.
     * @return The number of requests in the queue.
     */
    size_t getQueueSize();

private:
    RequestQueue requestQueue; ///< The queue of requests.
    std::vector<WebServer> webServers; ///< The list of web servers.
};

#endif // LOADBALANCER_H
