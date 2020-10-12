#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE 80

int main(void){
    char *args[MAX_LINE/2+1];
    int should_run = 1;
    char string[80];
    while(should_run){
        printf("osh>");
        fflush(stdout);

        int length, argsSE = 0;
        char string_buf[10][80];
        fgets(string, MAX_LINE, stdin);
        length = strlen(string);
        char *start = string;
        char *space;
        printf("%s", string);
        while(start!=NULL){
            space = strchr(start, ' ');
            if(space == NULL){
                strcpy(string_buf[argsSE], start);
                ++argsSE;
                start = NULL;
            } else {
                strncpy(string_buf[argsSE], start, space - start);
                string_buf[argsSE][space - start] = '\0';
                ++argsSE;
                start = space + 1;
            }
        }
    }
    return 0;
}
