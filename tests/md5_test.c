#include <stdio.h>
#include <string.h>
#include "../md5.h"


int main(int argc, char** argv)
{
	printf("%s\n", md5_encrypt(argv[1], strlen(argv[1])));
	return 0;
}
