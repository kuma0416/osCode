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
        // for(int i = 0; i < strlen(string_buf[0]); ++i){
        //     printf("%02x ", string_buf[0][i]);
        // }
        // printf("\n");
        // for(int i = 0; i < strlen(string_buf[1]); ++i){
        //     printf("%02x ", string_buf[1][i]);
        // }
        // printf("\n");
        for(int i = 0; i < argsSE; ++i){
            args[i] = string_buf[i];
        }
    }
    return 0;
}
