#include <stdio.h>
#include <unistd.h>
int main(){
    char* const arg[5] = {"cat", "test.c", NULL};
    execvp(arg[0], arg);
}
