# Simple Logger

A lightweight and configurable logging library written in C. It supports six
priority levels for logging messages and allows logging to the console
and a file, based on the build configuration.

## Priority Levels

The logger supports the following priority levels:

1. **Trace** - Detailed information for debugging.
2. **Debug** - General debugging information.
3. **Info** - Informational messages about program execution.
4. **Warn** - Warnings about potential issues.
5. **Error** - Errors that need attention.
6. **Fatal** - Critical errors causing program termination.

## Features

- Configurable logging to file and the console.
- Lightweight and easy to integrate into C projects.
- Supports variadic arguments for logging messages.

## Build Configuration

By default, the logger is configured to log to a file. You can toggle this
behavior using CMake options.

### Enable or Disable File Logging

To build with logging to a file enabled (default):
```bash
cmake -S . -B build -DLOG_TO_FILE=ON
cmake --build build
```

To build with logging to a file disable:
```bash
cmake -S . -B build -DLOG_TO_FILE=OFF
cmake --build build
```
## Usage

Include the logger header file and use the provided macros for logging at
various levels.

### Available Macros

*   `trace(...)` - Log a message with the `LOG_TRACE` priority.
*   `debug(...)` - Log a message with the `LOG_DEBUG` priority.
*   `info(...)` - Log a message with the `LOG_INFO` priority.
*   `warn(...)` - Log a message with the `LOG_WARN` priority.
*   `error(...)` - Log a message with the `LOG_ERROR` priority.
*   `fatal(...)` - Log a message with the `LOG_FATAL` priority.

### Example

```c
#include "logger.h"

int main() {
    trace("This is a trace message.");
    debug("This is a debug message.");
    info("This is an info message.");
    warn("This is a warning message.");
    error("This is an error message.");
    fatal("This is a fatal message.");
    return 0;
}

