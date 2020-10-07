#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main(){
    const int size = 4096;
    const char *name = "OS";
    const char *message_0 = "hello";
    const char *message_1 = "world";

    int shm_fd;
    void *ptr;

    shm_fd = shm_open(name, O_CREAT | O_RDRW, 0666);
    ftruncate(shm_fd, size);
    ptr = mmap(0, size, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    sprintf(ptr, "%s", message_0);
    ptr += strlen(message_0);
    sprintf(ptr, "%s", message_1);
    ptr += strlen(message_1);

    return 0;
}