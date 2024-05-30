#include "Logger.h"

Logger::Logger(const std::string& filename) {
    logFile.open(filename, std::ios::in | std::ios::out | std::ios::app);
    if (!logFile.is_open()) {
        throw std::runtime_error("Не удалось открыть файл логов");
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::logMessage(const std::string& message) {
    std::unique_lock<std::shared_mutex> lock(logMutex);
    logFile << message << std::endl;
}

std::string Logger::readMessage() {
    std::shared_lock<std::shared_mutex> lock(logMutex);
    std::string line;
    if (std::getline(logFile, line)) {
        return line;
    }
    return "";
}