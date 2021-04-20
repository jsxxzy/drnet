#include <stdio.h>
#include "../cutils.h"

/**
 * 生成密码测试
 */
int main(int argc, char** argv) {

  char *pwd = argv[1];
  char *outpassword = create_password(pwd);
  
  printf("%s\n", outpassword);
  return 0;
}