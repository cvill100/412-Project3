/**
 * @file RequestQueue.h
 * @brief Defines the RequestQueue class that manages a queue of requests.
 */

#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include "Request.h"
#include <queue>

/**
 * @class RequestQueue
 * @brief Manages a queue of requests.
 */
class RequestQueue {
public:
    /**
     * @brief Adds a request to the queue.
     * @param request The request to add.
     */
    void addRequest(const Request& request);

    /**
     * @brief Retrieves and removes the next request from the queue.
     * @return The next request. If the queue is empty, returns a default request.
     */
    Request getNextRequest();

    /**
     * @brief Checks if the queue is empty.
     * @return True if the queue is empty, false otherwise.
     */
    bool isEmpty() const;

    /**
     * @brief Gets the current size of the queue.
     * @return The number of requests in the queue.
     */
    size_t getSize();

private:
    std::queue<Request> queue; ///< The queue of requests.
};

#endif // REQUESTQUEUE_H
