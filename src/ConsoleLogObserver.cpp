#include "../include/ConsoleLogObserver.hpp"

void aw::ConsoleLogObserver::notifyCallback (LogLevel logLevel, const std::string& context, const std::string& message) {

    if (logLevel != aw::LogLevel::ERROR) {
        Console::stdoutLine(formatMessage(logLevel, context, message));
    } else {
        Console::stderrLine(formatMessage(logLevel, context, message));
    }

}

std::string aw::ConsoleLogObserver::formatMessage (LogLevel logLevel, const std::string& context, const std::string& message) const {

    auto time = std::time(nullptr);
    auto localtime = *std::localtime(&time);

    std::ostringstream oss;
    oss << std::put_time(&localtime, "%Y-%m-%d %H:%M:%S");
    oss << ' ';

    switch (logLevel) {

        case aw::LogLevel::VERBOSE:
            oss << ". VERBOSE : ";
            break;

        case aw::LogLevel::NOTICE:
            oss << "_ NOTICE  : ";
            break;

        case aw::LogLevel::WARNING:
            oss << "! WARNING : ";
            break;

        case aw::LogLevel::ERROR:
            oss << "# ERROR   : ";
            break;

        default:
            oss << "  UNKNOWN : ";
            break;

    }

    oss << context << " : " << message;

    return oss.str();

}
