#include <stdbool.h>

#define AUTHURL "http://210.22.55.58"

#define AUTHLOGINURL "http://210.22.55.58/0.htm"

#define AUTHLOGOUTURL "http://210.22.55.58/F.htm"

#define HASLOGINLENGTH 1000

#define LOGINSUCCESS "登录成功"

bool login(char *u, char *p);

bool logout();

bool has_login();

// void query_info();