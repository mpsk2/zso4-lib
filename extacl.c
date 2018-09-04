#define _GNU_SOURCE

#include <inttypes.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/syscall.h>
#include "extacl.h"

int extacl_get_file(const char *path, struct extacl *val, size_t extacl_len) {
    printf("%s, %p, %ld\n", path, val, extacl_len);
    return syscall(EXTACL_GET_SYSCALL, path, val, extacl_len);
}

int extacl_set_file(const char *path, struct extacl *extacl, size_t extacl_len) {
    printf("%s, %p, %ld\n", path, extacl, extacl_len);
    return syscall(EXTACL_SET_SYSCALL, path, extacl, extacl_len);
}
