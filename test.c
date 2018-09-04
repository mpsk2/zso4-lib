#include <inttypes.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include "extacl.h"

int main(int argc, char **argv) {
	int err;
	struct extacl *buff;
	unsigned int size = 1;
	char *file_name;
	if (argc < 2) {
		printf("too few args\n");
		return 1;
	}
	file_name = argv[1];
	printf("allocating %ld memory for size %ld and count %ld\n", sizeof(struct extacl) * 16, sizeof(struct extacl), 16);

	buff = malloc(sizeof(struct extacl) * 16);
	
	if (!buff) {
		perror("Failed to malloc\n");
		return 1;
	}
	
	if (strcmp(argv[2], "get") == 0) {
		err = extacl_get_file(file_name, buff, 16);
		printf("God %d\n", err);
	} else if ((strcmp(argv[2], "set") == 0)) {
		buff->type = EXTACL_USER_READ;
		buff->_pad = 0;
		buff->uid_gid = 42;
		buff->range_start = 500;
		buff->range_len = 500;
	

		err = extacl_set_file(file_name, buff, 2);
	} else {
			err = 1;
			perror("Not known command");
	}
	printf("Did not fail\n");	
	

	printf("%d\n", buff->type);
	printf("%d\n", buff->_pad);
	printf("%d\n", buff->uid_gid);
	printf("%d\n", buff->range_start);
	printf("%d\n", buff->range_len);
	if (err) {
		perror("failed to get");
		return 1;
	}
	
	return 0;
}
