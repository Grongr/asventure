//
// Created by grongr on 4/23/21.
//

#ifndef ASVERGIN_SPS_ERRORS_H
#define ASVERGIN_SPS_ERRORS_H

#include <exception>
#include <string>

//-----------------------------------------------------------------------------------------------------------//
/*!
 * Error which is thrown when count given of params of EFS builder is not 5
 */
class EFSParamCountError : public std::exception {
public:

    /*!
     * Default constructor to this error type
     * @param error  string which says what is an error
     */
    explicit EFSParamCountError(std::string error) : error{std::move(error)} {}

    /*!
     * @return Error massage
     */
    [[nodiscard]] const char* what() const noexcept override { return error.c_str(); }
    //TODO: change override if needed

private:
    std::string error;
};

class ZeroSpeedError : public std::exception {
public:
    /*!
     * Constructor with error massage as a param
     * @param error Error masage
     */
    explicit ZeroSpeedError(std::string error) : error{std::move(error)} {}

    /*!
     * Sometimes you need to read understand why it doesn't work
     */
    [[nodiscard]] const char* what() const noexcept final { return error.c_str(); }

private:
    std::string error;
};

/*!
 * Error which is thrown when count of given params of Spaceship
 * builder is not 5
 */
class SpaceShipBParamCountError : public std::exception {
public:

    SpaceShipBParamCountError() : error{} {}

    /*!
     * Constructor to this error type with error massage
     * @param error  some info about this error
     */
    explicit SpaceShipBParamCountError(std::string error) : error{std::move(error)} {}

    /*!
     * @return Error massage
     */
    [[nodiscard]] const char* what() const noexcept override { return error.c_str(); }

private:
    std::string error;
};

class PirateShipBParamCountError : public SpaceShipBParamCountError {
public:

    /*!
     * Default constructor to this error type
     * @param error some info about this error
     */
     explicit PirateShipBParamCountError(std::string error) : SpaceShipBParamCountError(error) {}
};

#endif //ASVERGIN_SPS_ERRORS_H
