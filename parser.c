#include <stdio.h>
#include <string.h>
#include "parser.h"

int parse_command(char *line, char **args, int *background) {
    int count = 0;
    *background = 0;

    // Remove o '\n' do final da linha lida pelo fgets
    line[strcspn(line, "\n")] = '\0';

    // TODO: Separar a string 'line' por espacos/tabs usando strtok()
    // e guardar cada palavra em args[count].
    // TODO: Verificar se o ultimo argumento e "&" (background)
    // e terminar o array com args[count] = NULL.
    (void)args;

    return count;
}
