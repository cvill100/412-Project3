/**
 * @file RequestQueue.cpp
 * @brief Implements the RequestQueue class that manages a queue of requests.
 */

#include "RequestQueue.h"

/**
 * @brief Adds a request to the queue.
 * @param request The request to add.
 */
void RequestQueue::addRequest(const Request& request) {
    queue.push(request);
}

/**
 * @brief Retrieves and removes the next request from the queue.
 * @return The next request. If the queue is empty, returns a default request.
 */
Request RequestQueue::getNextRequest() {
    if (!queue.empty()) {
        Request req = queue.front();
        queue.pop();
        return req;
    }
    // return a default request if queue is empty
    return Request();
}

/**
 * @brief Checks if the queue is empty.
 * @return True if the queue is empty, false otherwise.
 */
bool RequestQueue::isEmpty() const {
    return queue.empty();
}

/**
 * @brief Gets the current size of the queue.
 * @return The number of requests in the queue.
 */
size_t RequestQueue::getSize() {
    return queue.size();
}
