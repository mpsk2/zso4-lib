#include <inttypes.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include "extacl.h"

int main(int argc, char **argv) {
	int err;
	extacl_t *buff;
	size_t size = 1;
	buff = malloc(sizeof(extacl_t) * size);
	buff->type = EXTACL_USER_READ;
	buff->_pad = 0;
	buff->uid_gid = 42;
	buff->range_start = 500;
	buff->range_len = 500;
	
	if (strcmp(argv[2], "get") == 0) {
		err = extacl_get_file(argv[1], buff, size);
	} else if ((strcmp(argv[2], "set") == 0)) {
		err = extacl_set_file(argv[1], buff, size);
	} else {
			err = 1;
			perror("Not known command");
	}
	
	if (err) {
		perror("failed to get");
		return 1;
	}
	return 0;
}
