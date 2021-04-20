// ===================
// 公共库
// ===================

#include <ctype.h>
#include <string.h>

#include "cutils.h"
#include "md5.h"

/**
 * 去除空格
 * https://stackoverflow.com/a/2450779
 */
char *trim(char *string) {
  char *start;
  int len = strlen(string);
  int i;

  /* Find the first non whitespace char */
  for (i = 0; i < len; i++) {
    if (!isspace(string[i])) {
      break;
    }
  }

  if (i == len) {
    /* string is all whitespace */
    return NULL;
  }

  start = &string[i];

  /* Remove trailing white space */
  for (i = len; i > 0; i--) {
    if (isspace(string[i])) {
      string[i] = '\0';
    } else {
      break;
    }
  }

  return start;
}

/**
 * 生成密码
 * https://github.com/jsxxzy/ipsd
 */
char *create_password(char *raw_password) {
  char cache_var[50];
  strcat(cache_var, PID);
  strcat(cache_var, raw_password);
  strcat(cache_var, CALG);
  char *pwd_encode = md5_encrypt(cache_var, strlen(cache_var));
  strcat(pwd_encode, CALG);
  strcat(pwd_encode, PID);
  return pwd_encode;
}