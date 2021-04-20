#include <regex.h>
#include <stdio.h>
#include <string.h>

#include "html_parser.h"
#include "gistregex.h"

/**
 * 获取`title`
 */
char* get_title(char *raw_html) {
  char *title = match(raw_html, "<title.*>(.*)<\/title>");
  return title;
}