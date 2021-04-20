#include <stdbool.h>

#ifndef _COMMON
#define _COMMON

struct AuthConf {
  char* username; // 用户名
  char* password; // 密码
  bool* read_flag; // 读取是否成功
};

#endif

int print_auth();

char* get_home_path();

struct AuthConf get_config();

struct AuthConf NewAuthConf(char*, char*);

struct AuthConf NewFailAuthConf();


/**
 * 配置文件
 */
#define CONFIG_FILE_NAME ".inet.conf"

/**
 * 用户名配置
 */
#define CONFIG_KEY_USER "username"

/**
 * 密码配置
 */
#define CONFIG_KEY_PASSWORD "password"