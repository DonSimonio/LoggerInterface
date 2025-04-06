#if defined(ARDUINO)

#include "SerialLogger.h"

static const char* levelToString(LogLevel level) {
    switch (level) {
        case LogLevel::DEBUG: return "DEBUG";
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::ERROR: return "ERROR";
        case LogLevel::FATAL: return "FATAL";
        default: return "UNKNOWN";
    }
}

SerialLogger* SerialLogger::getInstance() {
    static SerialLogger instance;  // This will be the only instance created
    return &instance;
}

void SerialLogger::init() {
    Serial.begin(115200);
    while (!Serial);
}

void SerialLogger::log(LogLevel level, const char* message, ...) {
    if (level >= verbosity) {
        va_list args;
        va_start(args, message);

        Serial.print("[");
        Serial.print(levelToString(level));
        Serial.print("] ");

        char buffer[1024]; // Buffer to store the formatted message
        vsnprintf(buffer, sizeof(buffer), message, args);
        Serial.print(buffer);

        va_end(args);
        Serial.println();
    }
}

#endif