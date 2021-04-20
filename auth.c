#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include "ini.h"
#include "auth.h"
#include "filepath.h"

/**
 * 创建auth
 */
struct AuthConf NewAuthConf(char* u, char* p) {
  struct AuthConf conf;
  conf.username = u;
  conf.password = p;
  conf.read_flag = true;
  return conf;
}

/**
 * 返回错误的auth
 */
struct AuthConf NewFailAuthConf() {
  struct AuthConf conf;
  conf.read_flag = false;
  return conf;
}

/**
 * 获取用户主目录
 */
char* get_home_path() {
  struct passwd *pwd = getpwuid(getuid());
  if (pwd) {
    return pwd->pw_dir;
  } else {
    return getenv("home");
  }
}

/**
 * 获取配置文件
 */
struct AuthConf get_config() {
  char *user_home = get_home_path();
  char *outfile = path_join(user_home, CONFIG_FILE_NAME);
  ini_t *ini_tool = ini_load(outfile);
  if (!ini_tool) {
    return NewFailAuthConf();
  }
  char *u = ini_get(ini_tool,"", CONFIG_KEY_USER);
  char *p = ini_get(ini_tool, "", CONFIG_KEY_PASSWORD);
  if (!u || !p) {
    return NewFailAuthConf();
  }
  ini_free(ini_tool);
  return NewAuthConf(u, p);;
}

/**
 * 打印用户
 */
int print_auth(){
  struct AuthConf data = get_config();
  if (!data.read_flag) {
    printf("读取错误\n");
    return 0;
  }
  printf("用户名: %s\n  密码: %s\n", data.username, data.password);
  return 0;
}