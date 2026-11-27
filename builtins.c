#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "builtins.h"

void builtin_help(void) {
    printf("=== MiniShell (AHSO) ===\n");
    printf("Comandos internos disponiveis:\n");
    printf("  cd [dir]  - Muda de diretoria\n");
    printf("  help      - Mostra esta mensagem de ajuda\n");
    printf("  clear     - Limpa o ecra\n");
    printf("  exit/quit - Termina a shell\n");
}

void builtin_cd(char **args) {
    // TODO: Implementar mudanca de diretoria com chdir() (<unistd.h>).
    // Se args[1] for NULL, mudar para getenv("HOME").
    (void)args;
}

int handle_builtin(char **args) {
    if (args[0] == NULL) {
        return 1;
    }

    if (strcmp(args[0], "exit") == 0 || strcmp(args[0], "quit") == 0) {
        return -1; // Sinaliza ao loop principal para terminar a shell
    }

    if (strcmp(args[0], "help") == 0) {
        builtin_help();
        return 1;
    }

    if (strcmp(args[0], "cd") == 0) {
        builtin_cd(args);
        return 1;
    }

    // TODO: Adicionar outros comandos internos se necessario (ex: clear, history, env, export)

    return 0; // Nao e comando interno
}
