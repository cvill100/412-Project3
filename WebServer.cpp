/**
 * @file WebServer.cpp
 * @brief Implements the WebServer class that represents a web server.
 */

#include "WebServer.h"

/**
 * @brief Constructs a WebServer with no remaining processing time.
 */
WebServer::WebServer() : remainingTime(0) {}

/**
 * @brief Processes a request by setting the remaining processing time.
 * @param request The request to process.
 */
void WebServer::processRequest(const Request& request) {
    remainingTime = request.getTime();
}

/**
 * @brief Simulates the passage of one clock cycle by decrementing the remaining processing time.
 */
void WebServer::tick() {
    if (remainingTime > 0) {
        --remainingTime;
    }
}

/**
 * @brief Checks if the server is available to process a new request.
 * @return True if the server is available, false otherwise.
 */
bool WebServer::isAvailable() const {
    return remainingTime == 0;
}
