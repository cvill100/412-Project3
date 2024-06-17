/**
 * @file Request.h
 * @brief Defines the Request class that represents a web request.
 */

#ifndef REQUEST_H
#define REQUEST_H

#include <string>

/**
 * @class Request
 * @brief Represents a web request with input IP, output IP, and processing time.
 */
class Request {
public:
    /**
     * @brief Default constructor that generates random IP addresses and processing time.
     */
    Request();

    /**
     * @brief Constructor that initializes the Request with specified IP addresses and time.
     * @param ipIn Input IP address.
     * @param ipOut Output IP address.
     * @param time Processing time.
     */
    Request(const std::string& ipIn, const std::string& ipOut, int time);

    /**
     * @brief Gets the input IP address.
     * @return Input IP address.
     */
    std::string getIpIn() const;

    /**
     * @brief Gets the output IP address.
     * @return Output IP address.
     */
    std::string getIpOut() const;

    /**
     * @brief Gets the processing time.
     * @return Processing time.
     */
    int getTime() const;

private:
    std::string ipIn;  ///< Input IP address.
    std::string ipOut; ///< Output IP address.
    int time;          ///< Processing time.
};

#endif // REQUEST_H
