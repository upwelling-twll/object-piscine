#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <format>         // C++20
#include <source_location> // C++20
#include <chrono>

namespace railways {
	
	enum class LogLevel {
		DEBUG   = 0,
		INFO    = 1,
		ACTION  = 2,
		WARNING = 3,
		ERROR   = 4,
		SILENT  = 5,  // suppress everything
	};
	
	class Logger
	{

	private:
		Logger() = default;
		LogLevel      m_level = LogLevel::DEBUG;
		std::ofstream m_fileStream;
		
		static std::string_view levelToString(LogLevel l) 
		{
			switch (l) 
			{
				case LogLevel::DEBUG:   return "DEBUG";
				case LogLevel::INFO:    return " INFO";
				case LogLevel::ACTION:  return "  ACT";
				case LogLevel::WARNING: return " WARN";
				case LogLevel::ERROR:   return "ERROR";
				default:                return "  ???";
			}
		}
		
		static std::string_view levelToColor(LogLevel l) 
		{
			switch (l)
			{
				case LogLevel::DEBUG:   return "\033[90m";  // grey
				case LogLevel::INFO:    return "\033[33m";  // yellow
				case LogLevel::ACTION:  return "\033[36m";  // cyan
				case LogLevel::WARNING: return "\033[95m";  // pink
				case LogLevel::ERROR:   return "\033[31m";  // red
				default:                return "\033[0m";
			}
		}

	public:
		static Logger& get()
		{
			static Logger instance;
			return instance;
		}

    // --- Configuration ---
    void setLevel(LogLevel level)  { m_level = level; }
    void enableFile(const std::string& path) {
        m_fileStream.open(path, std::ios::out | std::ios::app);
    }

    // --- Core log function with source location (replaces macros!) ---
    void log(
        LogLevel level,
        std::string_view message,
        const std::source_location loc = std::source_location::current()
    ) {
        if (level < m_level) return;

        auto now = std::chrono::system_clock::now();
        auto entry = std::format("[{}][{}:{}] {}",
            levelToString(level),
            loc.file_name(),        // which file
            loc.line(),             // which line
            message
        );

        // Colored console output
        std::cout << levelToColor(level) << entry << "\033[0m\n";

        // Optionally also write to file (for simulation logs)
        if (m_fileStream.is_open())
            m_fileStream << entry << '\n';
    }

    // --- Convenience wrappers (match your existing LOG_XXXX names) ---
    void debug(std::string_view msg,   std::source_location loc = std::source_location::current()) { log(LogLevel::DEBUG,   msg, loc); }
    void info(std::string_view msg,    std::source_location loc = std::source_location::current()) { log(LogLevel::INFO,    msg, loc); }
    void action(std::string_view msg,  std::source_location loc = std::source_location::current()) { log(LogLevel::ACTION,  msg, loc); }
    void warning(std::string_view msg, std::source_location loc = std::source_location::current()) { log(LogLevel::WARNING, msg, loc); }
    void error(std::string_view msg,   std::source_location loc = std::source_location::current()) { log(LogLevel::ERROR,   msg, loc); }

	}; //Logger class

// --- Global convenience macros (optional, backward compatible with old LOG_XXXX) ---
// These automatically capture file name and line number!
#define LOG_DBUG(msg)    railways::Logger::get().debug(msg)
#define LOG_INFO(msg)    railways::Logger::get().info(msg)
#define LOG_ACTION(msg)  railways::Logger::get().action(msg)
#define LOG_WARNING(msg) railways::Logger::get().warning(msg)
#define LOG_ERROR(msg)   railways::Logger::get().error(msg)

} // namespace railways

