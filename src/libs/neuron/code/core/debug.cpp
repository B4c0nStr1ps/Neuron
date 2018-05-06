#include "debug.h"
#include <stdio.h>
#include <stdarg.h>

namespace neuron {
namespace debug {

const char * GetVerbosityText(LoggingVerbosity verbosity)
{
	const char* verbosity_fatal = "FATAL";
	const char* verbosity_error = "ERROR";
	const char* verbosity_warning = "WARNING";
	const char* verbosity_info = "INFO";

	switch (verbosity)
	{
	case LoggingVerbosity::K_INFO:
		return verbosity_info;
		break;
	case LoggingVerbosity::K_WARNING:
		return verbosity_warning;
		break;
	case LoggingVerbosity::K_ERROR:
		return verbosity_error;
		break;
	case LoggingVerbosity::K_FATAL:
		return verbosity_fatal;
		break;
	default:
		break;
	}

	return nullptr;
}

void Log(LoggingVerbosity verbosity, const char* file_name, int line_num, const char * message)
{
	printf("[%s] %s - FILE: %s LINE: %d\n", GetVerbosityText(verbosity), message, file_name, line_num);
}

void LogFormat(LoggingVerbosity verbosity, const char* file_name, int line_num, const char * format, ...)
{
	char message[256];
	va_list args;
	va_start(args, format);
	vsprintf_s(message, format, args);
	va_end(args);

	Log(verbosity, file_name, line_num, message);
}

} // namespace logging.
} // namespace neuron.