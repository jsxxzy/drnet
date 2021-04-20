#include <stdio.h>

#include "../cutils.h"

int main() {
  char *data = " 你好 世界 ";
  char *r_data = trim(data);
  printf("out_data: %s\n", data);
  printf("trim_fun: %s\n", r_data);
  return 0;
}