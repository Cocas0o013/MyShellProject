#ifndef BUILTINS_H
#define BUILTINS_H

// Verifica se args[0] e um comando interno (cd, exit, quit, help, clear).
// Devolve:
//   1 -> Era um comando interno e foi executado
//   0 -> Nao e um comando interno (deve ser executado pelo executor.c)
//  -1 -> O utilizador pediu para sair da shell (exit / quit)
int handle_builtin(char **args);

void builtin_help(void);
void builtin_cd(char **args);

#endif
