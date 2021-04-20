#include <stdio.h>
#define _GNU_SOURCE
#include <string.h>

#include "drcore.h"
#include "html_parser.h"
#include "auth.h"
#include "http.h"
#include "cutils.h"

/**
 * 登录
 */
bool login(char *u, char *p) {
  if (strlen(u) <= 1 || strlen(u) <= 1)
    return false;
  ft_http_init();
  ft_http_client_t* http = ft_http_new();
  char *gp = create_password(p);
  // printf("create password: %s\n", gp);

  char *sp1 = "R1=0&R2=1&para=00&0MKKey=123456&upass=";
  char *sp2 = "&DDDDD=";
  int total_len = strlen(sp1) + strlen(sp2) + strlen(gp) + strlen(u);
  char *post_data[total_len];
  strcat(post_data, sp1);
  strcat(post_data, gp);
  strcat(post_data, sp2);
  strcat(post_data, u);
  // printf("post_data: %s\n", post_data);

  char *user_header = "Content-Type: application/x-www-form-urlencoded";
  // printf("user_header: %s\n", user_header);

  char* body = ft_http_post_request(http, AUTHLOGINURL, post_data, user_header);
  // printf("%s\n", body);

  char *title = get_title(body);
  char *rep_title = trim(title); 

  // printf("标题: %s\n", trim_title);

  // 预留
  // 0  未登录(表示请求网关失败)
  // 1  密码错误
  // 5  多台设备在线
  // 66 登录成功
  if (rep_title == LOGINSUCCESS) {
    // printf("妈妈我登录成功了\n");
    return true;
  }

  return false;
} 

/**
 * 注销
 */
bool logout() {
  ft_http_init();
  ft_http_client_t* http = ft_http_new();
  const char *str =  ft_http_sync_request(http, AUTHLOGOUTURL, M_GET);
  return has_login();
}

/**
 * 判断是否登录
 */
bool has_login() {

  ft_http_init();
  ft_http_client_t* http = ft_http_new();
  const char *str =  ft_http_sync_request(http, AUTHURL, M_GET);

  //===============
  // 当访问错误时, 应该是超时了
  // 是因为这个库的问题, 无法处理302的问题 => false
  //===============
  if (str == NULL) return false;
  
  int max_html_code = strlen(str);

  // printf("%s\n", str);

  // if (max_html_code >= HASLOGINLENGTH) {
  //   return !(strlen(title) == 0);
  // };
  // return false;

  return (max_html_code >= HASLOGINLENGTH);
}