CC = gcc

all: clean run_md5 run_pwdgen run_rs run_open

clean:
	rm *.o

# 测试MD5
run_md5:
	$(CC) -o md5_gen.o ../md5.c md5_test.c
	./md5_gen.o 666

# 测试密码生成
run_pwdgen:
	$(CC) -o pwd_gen.o ../md5.c ../cutils.c pwd_test.c
	./pwd_gen.o 666

# 空格去除
run_rs:
	$(CC) -o rs.o ../md5.c ../cutils.c removespace_test.c
	./rs.o

# 测试全平台打开`url`
run_open:
	$(CC) -o opener_x.o ../opener.c open_test.c
	./opener_x.o https://github.com/abranhe/opener.c/blob/master/opener.h