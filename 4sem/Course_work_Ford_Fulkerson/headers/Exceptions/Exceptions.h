#ifndef COURSE_WORK_FORD_FULKERSON_EXCEPTIONS_H
#define COURSE_WORK_FORD_FULKERSON_EXCEPTIONS_H


#include <exception>
#include <string>

class Exception: virtual public std::exception {

protected:

    int errorNumber_;               ///< Error number
    std::string errorMessage_;      ///< Error message

public:

    /** Constructor (C++ STL string, int, int).
     *  @param msg The error message
     *  @param errNum Error number
     *  @param err_off Error offset
     */
    explicit
    Exception(const std::string& msg, int errNum):
            errorNumber_(errNum),
            errorMessage_(msg)
    {}

    /** Destructor.
     *  Virtual to allow for subclassing.
     */
    virtual ~Exception() throw () {}

    /** Returns a pointer to the (constant) error description.
     *  @return A pointer to a const char*. The underlying memory
     *  is in possession of the Exception object. Callers must
     *  not attempt to free the memory.
     */
    virtual const char* what() const throw () {
        return errorMessage_.c_str();
    }

    /** Returns error number.
     *  @return #errorNumber_
     */
    virtual int getErrorNumber() const throw() {
        return errorNumber_;
    }

};


#endif //COURSE_WORK_FORD_FULKERSON_EXCEPTIONS_H
