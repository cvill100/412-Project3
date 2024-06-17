/**
 * @file Request.cpp
 * @brief Implements the Request class that represents a web request.
 */

#include "Request.h"
#include <cstdlib>
#include <sstream>

/**
 * @brief Default constructor that generates random IP addresses and processing time.
 */
Request::Request() {
    std::stringstream ss;
    ss << rand() % 256 << "." << rand() % 256 << "." << rand() % 256 << "." << rand() % 256;
    ipIn = ss.str();
    ss.str("");
    ss << rand() % 256 << "." << rand() % 256 << "." << rand() % 256 << "." << rand() % 256;
    ipOut = ss.str();
    time = rand() % 15 + 5; // Time range is 5 to 20 clock cycles
}

/**
 * @brief Constructor that initializes the Request with specified IP addresses and time.
 * @param ipIn Input IP address.
 * @param ipOut Output IP address.
 * @param time Processing time.
 */
Request::Request(const std::string& ipIn, const std::string& ipOut, int time) : ipIn(ipIn), ipOut(ipOut), time(time) {}

/**
 * @brief Gets the input IP address.
 * @return Input IP address.
 */
std::string Request::getIpIn() const {
    return ipIn;
}

/**
 * @brief Gets the output IP address.
 * @return Output IP address.
 */
std::string Request::getIpOut() const {
    return ipOut;
}

/**
 * @brief Gets the processing time.
 * @return Processing time.
 */
int Request::getTime() const {
    return time;
}
