#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    const int size = 4096;
    const char *name = "OS";
    const char *message_0 = "hello";
    const char *message_1 = "world";

    int shm_fd;
    void *ptr;

    shm_fd = shm_open(name, O_RDONLY, 0666);
    ftruncate(shm_fd, size);
    ptr = mmap(0, size, PROT_READ, MAP_SHARED, shm_fd, 0);

    printf("%s", (char *)ptr);//read from the shared memory object
    shm_unlink(name);//remove the shared memory object

    return 0;
}
