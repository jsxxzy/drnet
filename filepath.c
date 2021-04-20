#include "filepath.h"

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <libgen.h>

#include <sys/types.h>
#include <sys/stat.h>

/**
 * 路径合并
 */
char* path_join(const char *p1, const char *p2) {
  char *path;
  size_t p1_len, p2_len;
  if (p2 == NULL)
    return NULL;
  if (p2[0] == PATH_SEP)
    return strdup(p2);
  p1_len = (p1 == NULL) ? 0 : strlen(p1);
  p2_len = strlen(p2);
  path = malloc(sizeof(char) * (p1_len + p2_len + 2));
  if (p1) {
    strncpy(path, p1, p1_len);
  }
  if (p1_len && path[p1_len - 1] != PATH_SEP) {
    path[p1_len] = PATH_SEP;
    strncpy(path + p1_len + 1, p2, p2_len);
    path[p1_len + 1 + p2_len] = '\0';
  } else {
    strncpy(path + p1_len, p2, p2_len);
    path[p1_len + p2_len] = '\0';
  }
  return path;
}
