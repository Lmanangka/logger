#ifndef LOG_UTILS_H
#define LOG_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  LOG_TRACE,
  LOG_DEBUG,
  LOG_INFO,
  LOG_WARN,
  LOG_ERROR,
  LOG_FATAL,
  LOG_LEVEL_LEN
} LOG_LEVEL;

void log_mesg(LOG_LEVEL level, const char *fmt, ...);

#define trace(...) log_mesg(LOG_TRACE, __VA_ARGS__);
#define debug(...) log_mesg(LOG_DEBUG, __VA_ARGS__);
#define info(...) log_mesg(LOG_INFO, __VA_ARGS__);
#define warn(...) log_mesg(LOG_WARN, __VA_ARGS__);
#define error(...) log_mesg(LOG_ERROR, __VA_ARGS__);
#define fatal(...) log_mesg(LOG_FATAL, __VA_ARGS__);

#ifdef __cplusplus
}
#endif

#endif // !LOG_UTILS_H
