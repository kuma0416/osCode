#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int value = 5;
int main(void){
    pid_t pid;

    pid = fork();

    printf("pid=%d\n", pid);

    if(pid<0){
        fprintf(stderr, "fork failed.");
        return 1;
    } else if(pid==0){ //child process
        value += 15;
        printf("child:%d\n", value);
        return 0;
    } else {
        wait(NULL);
        printf("parent: value = %d\n", value);
        return 0;
    }
    return 0;
}
