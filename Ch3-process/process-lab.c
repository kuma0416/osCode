#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE 80

int main(void){
    char *args[MAX_LINE/2+1];
    int should_run = 1;
    char string[80], string_buf[10][80];
    while(should_run){
        printf("osh>");
        fflush(stdout);

        int length, argsSE = 0;
        fgets(string, MAX_LINE, stdin);
        length = strlen(string);
        while(scanf("%s", &string)!= EOF){
            printf("%s", string);
        }
        //printf("length: %d, string: %s\n", length, string);
        //args[0] = string; 
        //printf("args test: %s", args[0]);
        /*for(int i=0; i< length; ++i){
            printf("before: %c\n", string[i]);
            if(string[i]==' ' || string[i] == '\0'){
                ++argsSE;
            } else {
                strcat( string_buf[argsSE], &string[i]);
            }
            printf("after: string_buf->%s, argsSE: %d\n", string_buf[argsSE], argsSE);
        }*/
        /*for(int i=0; i<2; ++i){
            printf("string buf: %s\n", &string_buf[i]);
        }*/
        /*char a[10] = "a";
        strcat(string, a);
        printf("args test: %s, string: %s", args[0], string);*/
    }
    return 0;
}
