#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "executor.h"
#include "builtins.h"

int main(void) {
    char line[MAX_LINE];
    char *args[MAX_ARGS];
    int background = 0;
    int running = 1;

    while (running) {
        // 1. Apresentar a prompt
        printf("myshell> ");
        fflush(stdout);

        // 2. Ler comando do utilizador (termina se receber EOF / Ctrl+D)
        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("\n");
            break;
        }

        // 3. Fazer parse da linha para separar o comando e argumentos
        int num_args = parse_command(line, args, &background);
        if (num_args == 0) {
            continue;
        }

        // 4. Executar o comando (interno ou externo)
        running = execute_command(args, background);
    }

    return 0;
}
