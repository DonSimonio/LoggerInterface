#pragma once

#include <cstdarg>

enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    FATAL
};

class LoggerInterface {
public:
    virtual void init() = 0;
    virtual void log(LogLevel level, const char* message, ...) = 0;

    virtual void setVerbosity(LogLevel level) {
        verbosity = level;
    }

protected:
    LoggerInterface() = default;
    virtual ~LoggerInterface() = default;

    LogLevel verbosity = LogLevel::DEBUG;
};

// Convenience macros
#define LOG_DEBUG(logger, message, ...)   (logger)->log(LogLevel::DEBUG, message, ##__VA_ARGS__)
#define LOG_INFO(logger, message, ...)    (logger)->log(LogLevel::INFO, message, ##__VA_ARGS__)
#define LOG_WARNING(logger, message, ...) (logger)->log(LogLevel::WARNING, message, ##__VA_ARGS__)
#define LOG_ERROR(logger, message, ...)   (logger)->log(LogLevel::ERROR, message, ##__VA_ARGS__)
#define LOG_FATAL(logger, message, ...)   (logger)->log(LogLevel::FATAL, message, ##__VA_ARGS__)
