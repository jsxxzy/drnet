#include <stdio.h>

#include "../opener.h"

int main(int argc, char** argv) {
  char *url = argv[1];
  int flag = opener(url);
  return flag;
}