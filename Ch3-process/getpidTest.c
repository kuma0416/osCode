#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
    pid_t pid, pid1;
    pid = fork();
    
    printf("root pid=%d, pid1=%d\n", pid, pid1);

    if(pid<0){
        fprintf(stderr, "fork failed.\n");
        return 1;
    } else if(pid == 0){
        pid1 = getpid();
        printf("child's pid=%d, pid1=%d\n", pid, pid1);
    } else {
        pid1 = getpid();
        printf("parent's pid=%d, pid1=%d\n", pid, pid1);
        wait(NULL);
    }
    return 0;
}
