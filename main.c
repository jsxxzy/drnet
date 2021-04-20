#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "cutils.h"
#include "drcore.h"
#include "auth.h"
#include "opener.h"
#include "filepath.h"

#define USEAG " login: 登录\n   get: 获取保存的账号密码\n check: 查询是否登录\nlogout: 注销\nconfig: 打开配置文件\n"

// 打开配置文件
int open_config() {
  char *h = get_home_path();
  char *outfile = path_join(h, CONFIG_FILE_NAME);

  printf("打开配置文件: %s\n请自行写入配置,参照格式: \n\nusername = u\npassword = p\n", outfile);

  //
  // 尝试兼容`windows`平台
  //
  // char *file_method = "file://";
  // int i = strlen(outfile) + strlen(file_method);
  // char *u[i];
  // strcat(u, file_method);
  // strcat(u, outfile);

  return opener(outfile);
}

int main_app(int args, char *argv[]) {
  if (args <= 1) {
    printf(USEAG);
    return 0;
  }
  char *cmd = argv[1];
  char *action = trim(cmd);
  if (strcmp(action, "login") == 0) {

    char *u = "";
    char *p = "";

    struct AuthConf conf = get_config();

    if (conf.read_flag && strlen(conf.username) >= 1 && strlen(conf.password) >= 1) {
      u = conf.username;
      p = conf.password;
    } else {
      printf("配置文件没有配置用户\n");
    }

    int arg_int = 4;

    if (args >= 4) {
      u = trim(argv[2]);
      p = trim(argv[3]);
    }
    if (strlen(u) <= 1 || strlen(p) <= 1) {
      printf("未设置账号密码\n可以手动设置账号密码或者传递参数\nexp: drnet user pwd\n");
      return -1;
    }
    // else {
    //   printf("%s\n%s\n", u, p);
    // }

    bool f = login(u, p);

    char *msg = "登录成功";

    if (!f)
      msg = "登录失败";

    printf("%s\n",msg);

  } else if (strcmp(action, "get") == 0) {
    
    print_auth();

    return 0;

  } else if (strcmp(action, "check") == 0) {
    
    bool f = has_login();
    
    char *msg = "已登录";
    if (!f)
      msg = "未登录";

    printf("%s\n", msg);

    return 0;

  } else if (strcmp(action, "logout") == 0) {
    
    // 注销没有状态码, 未知状态, 一般都可以注销成功
    logout();

    printf("注销成功\n");

    return 0;

  } else if (strcmp(action, "config") == 0) {

    open_config();

    return 0;

  } else {

    printf("不支持的命令\n");
    return -1;

  }
  return 0;
}

int main(int argc, char *argv[]) {
  return main_app(argc, argv);
}