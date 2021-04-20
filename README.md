该项目尝试将校园网客户端带入到嵌入式设备中

```bash
 login: 登录
   get: 获取保存的账号密码
 check: 查询是否登录
logout: 注销
config: 打开配置文件
```

注: 需要手动创建本地配置文件, 并写入配置

```bash
# touch ~/.inet.conf


# 请填入账号和密码即可
# https://github.com/jsxxzy/inettray

username = u
password = p
```

参考项目:

- https://gitee.com/linxyruffy/httpclient
- https://github.com/abranhe/opener.c

**只是做了一点点微小的工作, 站在了巨人的肩膀上**

该库仅在`macos big sur 11.2.3`下测试编译成功, 在其他平台下可能编译错误, 请自行编译

推荐使用: https://github.com/jsxxzy/inet