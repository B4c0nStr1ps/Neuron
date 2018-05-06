#ifndef NEURON_DEBUG_H
#define NEURON_DEBUG_H

namespace neuron {
namespace debug {

enum class LoggingVerbosity : unsigned int
{
	K_INFO = 0,
	K_WARNING = 1,
	K_ERROR = 2,
	K_FATAL = 3,
	K_ASSERTION
};

const char* GetVerbosityText(LoggingVerbosity verbosity);

void Log(LoggingVerbosity verbosity, const char* file_name, int line_num, const char* message);

void LogFormat(LoggingVerbosity verbosity, const char* file_name, int line_num, const char* format, ...);

} // namespace logging.
} // namespace neuron.

#if NO_LOGGING
#define DEBUG_LOG(format, ...)
#define DEBUG_LOG_WARNING(format, ...)
#define DEBUG_LOG_ERROR(format, ...)
#define DEBUG_LOG_ASSERTION(format, ...)
#else
#define DEBUG_LOG(format, ...) \
{ neuron::debug::LogFormat(neuron::debug::LoggingVerbosity::K_INFO, __FILE__, __LINE__, format, ##__VA_ARGS__); }
#define DEBUG_LOG_WARNING(format, ...) \
{ neuron::debug::LogFormat(neuron::debug::LoggingVerbosity::K_WARNING, __FILE__, __LINE__, format, ##__VA_ARGS__); }
#define DEBUG_LOG_ERROR(format, ...) \
{ neuron::debug::LogFormat(neuron::debug::LoggingVerbosity::K_ERROR, __FILE__, __LINE__, format, ##__VA_ARGS__); }
#define DEBUG_LOG_ASSERTION(format, ...) \
{ neuron::debug::LogFormat(neuron::debug::LoggingVerbosity::K_ASSERTION, __FILE__, __LINE__, format, ##__VA_ARGS__); }
#endif // LOGGING_ON

#ifdef ASSERTION_DISABLED
#define DEBUG_ASSERT(...)
#define DEBUG_ASSERT_MSG(...)
#else
#include <intrin.h>

#define debugBreak() {__debugbreak();} 

#define DEBUG_ASSERT(expr) { \
  if (expr) {} \
  else \
  { \
		DEBUG_LOG_ASSERTION(#expr, __FILE__, __LINE__);\
		debugBreak(); \
	} \
}

#define DEBUG_ASSERT_MSG(expr, message) { \
  if (expr) {} \
  else \
  { \
		DEBUG_LOG_ASSERTION(#message, __FILE__, __LINE__);\
		debugBreak(); \
	} \
}
#endif //ASSERTION_DISABLED

#endif //NEURON_DEBUG_H