#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char command[50];
    while (true) {
        printf(":: ");
        fgets(command, 50, stdin);
        //scanf("%s", command);
        if (strcmp(command, "exit\n") == 0)
            return 0;
        else
            system(command);
    }

    return 0;
}
