#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t pid;

    pid = fork();

    if (pid < 0){
        fprintf(stderr, "fork failed");
        return 1;
    } else if (pid == 0){
        execlp("/bin/ls", "ls", NULL);
    } else {
        wait(NULL);
        printf(stdout, "child complete");
    }
    return 0;
}