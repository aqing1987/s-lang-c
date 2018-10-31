#include <stdio.h>
#include <syslog.h>
#include <stdarg.h>

#define BUF_SIZE 1024

void a_print(const char* level, const char* format, ...) {
  char buf[BUF_SIZE] = {0};

  va_list ptr;
  va_start(ptr, format);
  vsnprintf(buf, BUF_SIZE, format, ptr);
  va_end(ptr);

  printf("level: %s\n", level);
  printf("%s", buf);
}

#define aa_print(...) a_print("wow", __VA_ARGS__)


int main(int argc, char *argv[]) {
  aa_print("%s", "really crazy\n");
  return 0;
}
