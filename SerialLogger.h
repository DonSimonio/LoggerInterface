#pragma once

#if defined(ARDUINO)

#include <LoggerInterface.h>
#include <Arduino.h>

class SerialLogger : public LoggerInterface {
public:
    static SerialLogger* getInstance();

    void init() override;
    void log(LogLevel level, const char* message, ...) override;

private:
    SerialLogger() = default;
    virtual ~SerialLogger() = default;

    // Delete copy constructor and assignment operator to prevent copying
    SerialLogger(const SerialLogger&) = delete;
    SerialLogger& operator=(const SerialLogger&) = delete;
};

#endif
