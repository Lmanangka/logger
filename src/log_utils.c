#include "log_utils.h"
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

// #define LOG_TO_FILE

#ifdef __EMSCRIPTEN
#define NO_ANSI

#endif

static const char *level_str[LOG_LEVEL_LEN] = {"TRACE", "DEBUG", "INFO",
                                               "WARN",  "ERROR", "FATAL"};
static const char *level_colors[LOG_LEVEL_LEN] = {
    "\x1b[1;38;5;8m",         "\x1b[1;34m", "\x1b[1;37m", "\x1b[1;33m",
    "\x1b[1;38;2;255;165;0m", "\x1b[1;31m"};

static char timestamp[20];
static char log_entry[512];

static void get_time() {
  time_t current_time = time(NULL);
  struct tm *local_time = localtime(&current_time);
  strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", local_time);
}

void log_mesg(LOG_LEVEL level, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vsnprintf(log_entry, sizeof(log_entry), fmt, args);
  get_time();

#ifdef LOG_TO_FILE

  FILE *log_file = fopen("log.txt", "a");
  if (log_file == NULL) {
    perror("Unable to open log file");
  }
  fprintf(log_file, "[%s]-->[%s] %s", timestamp, level_str[level], log_entry);
  fclose(log_file);

#endif

  printf("[%s]-->", timestamp);

#ifndef NO_ANSI
  printf("%s[%s]\x1b[0m ", level_colors[level], level_str[level]);
#else
  printf("[%s] ", level_str[level]);
#endif /* ifndef NO_ANSI */

  printf("%s", log_entry);
  va_end(args);
}
