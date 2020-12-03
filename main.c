#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char **parse_args(char *line) {
    char **argsv = malloc(6*sizeof(char *));
    char *p = line;

    int i = 0;
    while(p) {
        argsv[i] = strsep(&p, " ");
        i++;
    }

    return argsv; 
}

int main() {
    // testing parse_args
    char str[100] = "ls -a -l";
    
    char **args = parse_args(str);
    execvp(args[0], args);

    return 0;
}