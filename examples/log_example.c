#include "log_utils.h"

int main() {
  trace("TRACE TEST\n");
  debug("DEBUG TEST\n");
  info("INFO TEST\n");
  warn("WARN TEST\n");
  error("ERROR TEST\n");
  fatal("FATAL TEST\n");
  return 0;
}
