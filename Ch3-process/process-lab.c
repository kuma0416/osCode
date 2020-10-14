#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_LINE 80

int main(void){
    char *args[MAX_LINE/2+1];
    int should_run = 1;
    char string[80];
    for(int i = 0; i < MAX_LINE/2+1 ; ++i){
        args[i] = NULL;
    }
    while(should_run){
        printf("osh>");
        fflush(stdout);

        int length, argsSE = 0;
        char string_buf[10][80];
        fgets(string, MAX_LINE, stdin);
        if(strspn(string, "exit")){
            should_run = 0;
            return 0;
        }
        length = strlen(string);
        char *start = string;
        char *space;
        while(start!=NULL){
            space = strchr(start, ' ');
            if(space == NULL){
                int lastLength = strlen(start) - 1;
                strcpy(string_buf[argsSE], start);
                string_buf[argsSE][lastLength] = '\0';
                ++argsSE;
                start = NULL;
            } else {
                strncpy(string_buf[argsSE], start, space - start);
                string_buf[argsSE][space - start] = '\0';
                ++argsSE;
                start = space + 1;
            }
        }
        for(int i=0;i<argsSE;++i){
            args[i] = string_buf[i];
        }
        pid_t pid;
        pid = fork();
        if(pid<0){
            printf("fork error.\n");
            return 1;
        } else if(pid==0){//child process
            execvp(args[0], args);
            return 0;
        } else {
            wait(NULL);
            should_run = 1;
        }
        //execvp(args[0], args);
        //args[argsSE] = "NULL";
        //execvp(args[0], args);
    }
    return 0;
}
