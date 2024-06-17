/**
 * @file WebServer.h
 * @brief Defines the WebServer class that represents a web server.
 */

#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"

/**
 * @class WebServer
 * @brief Represents a web server that processes requests.
 */
class WebServer {
public:
    /**
     * @brief Constructs a WebServer with no remaining processing time.
     */
    WebServer();

    /**
     * @brief Processes a request by setting the remaining processing time.
     * @param request The request to process.
     */
    void processRequest(const Request& request);

    /**
     * @brief Simulates the passage of one clock cycle by decrementing the remaining processing time.
     */
    void tick(); // Decrease remaining time by 1

    /**
     * @brief Checks if the server is available to process a new request.
     * @return True if the server is available, false otherwise.
     */
    bool isAvailable() const;

private:
    int remainingTime; ///< Remaining processing time for the current request.
};

#endif // WEBSERVER_H
