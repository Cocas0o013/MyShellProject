#ifndef PARSER_H
#define PARSER_H

#define MAX_LINE 1024
#define MAX_ARGS 64

// Separa a linha introduzida pelo utilizador em comando e argumentos (args).
// Define *background = 1 se o comando terminar com '&', caso contrario 0.
// Devolve o numero de argumentos encontrados.
int parse_command(char *line, char **args, int *background);

#endif
