#define _GNU_SOURCE

#include <inttypes.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include "extacl.h"

int extacl_get_file(const char *path, struct extacl *extacl, size_t extacl_len) {
  return syscall(EXTACL_GET_SYSCALL, path, extacl, extacl_len);
}

int extacl_set_file(const char *path, struct extacl *extacl, size_t extacl_len) {
    return syscall(EXTACL_SET_SYSCALL, path, extacl, extacl_len);
}
