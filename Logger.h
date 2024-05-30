#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
#include <shared_mutex>

class Logger {
public:
    Logger(const std::string& filename);
    ~Logger();

    void logMessage(const std::string& message);
    std::string readMessage();

private:
    std::fstream logFile;
    std::shared_mutex logMutex;
};

#endif // LOGGER_H