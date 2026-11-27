#ifndef EXECUTOR_H
#define EXECUTOR_H

// Executa um comando (verifica primeiro se e built-in; se nao for, usa fork + execvp).
// Devolve 0 se o utilizador pediu para sair (exit/quit), ou 1 para continuar o loop.
int execute_command(char **args, int background);

#endif
