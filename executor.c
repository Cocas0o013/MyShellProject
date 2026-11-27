#include <stdio.h>
#include <stdlib.h>
#include "executor.h"
#include "builtins.h"

int execute_command(char **args, int background) {
    if (args[0] == NULL) {
        return 1; // Linha vazia, continua a shell
    }

    // 1. Verificar se e um comando interno (built-in)
    int builtin_status = handle_builtin(args);
    if (builtin_status == -1) {
        return 0; // Comando exit/quit: terminar a shell
    }
    if (builtin_status == 1) {
        return 1; // Built-in executado com sucesso, continuar a shell
    }

    // 2. Comando externo do SO (fork + execvp + wait)
    // TODO: Criar processo filho com fork(), executar comando com execvp()
    // e esperar com wait()/waitpid() se background == 0.
    (void)background;

    return 1;
}
