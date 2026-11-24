# 🛠️ Guia Prático: C com Vários Ficheiros (`.c` e `.h`) e `Makefile`

Este guia foi criado para explicar, do zero, como organizar o nosso projeto **MiniShell** em vários ficheiros e como usar o **`Makefile`** para compilar tudo automaticamente.

---

## 1. Porque não fazemos tudo apenas no `main.c`?

Até agora, provavelmente fizemos programas em C todos dentro de um único ficheiro `main.c`. No entanto, neste trabalho prático temos dois motivos fortes para separar o código:

1. **Trabalho em Equipa no GitHub:** Se 2 ou 3 pessoas editarem o `main.c` ao mesmo tempo, o Git vai gerar conflitos (*merge conflicts*) sempre que alguém tentar fazer `git push`. Se cada pessoa trabalhar num ficheiro diferente (`parser.c`, `executor.c`, `builtins.c`), quase nunca haverá conflitos.
2. **Requisito do Enunciado:** O enunciado sugere exatamente esta divisão (`main`, `parser`, `executor`, `builtins`) e exige um `Makefile` na entrega final.

---

## 2. Como funcionam os ficheiros `.h` (Headers) e `.c` (Source)?

Em C, quando queremos dividir o código em módulos, cada módulo leva **dois ficheiros**:

| Tipo de Ficheiro | Nome | Para que serve? |
| :--- | :--- | :--- |
| **Cabeçalho (Header)** | `modulo.h` | É o **"menu" ou "índice"**. Só declara **quais** funções, `structs` ou constantes existem naquele módulo, para que outros ficheiros as conheçam. **Não leva o código das funções.** |
| **Código-Fonte (Source)** | `modulo.c` | É a **"cozinha"**. Aqui escrevemos o código real (a implementação) das funções prometidas no `.h`. |

### Exemplo Prático: Módulo `builtins`

Imaginem que queremos criar a função `executar_cd()` no módulo `builtins` e chamá-la a partir do `main.c`.

#### Passo 1: Declarar a função no `builtins.h`
```c
#ifndef BUILTINS_H
#define BUILTINS_H

// Apenas a assinatura (cabeçalho) da função, terminada em ponto e vírgula (;)
int executar_builtin(char **args);
void mostrar_ajuda(void);

#endif
```

> **O que são aquelas linhas `#ifndef`, `#define` e `#endif`?**
> Chamam-se **Header Guards** (proteções de cabeçalho). Servem apenas para garantir que, se dois ficheiros diferentes fizerem `#include "builtins.h"`, o compilador não lê o mesmo ficheiro duas vezes (o que daria erro de "função duplicada").
> **Regra simples:** Em qualquer ficheiro `.h`, começa sempre com `#ifndef NOME_DO_FICHEIRO_H` / `#define NOME_DO_FICHEIRO_H` e termina com `#endif`.

#### Passo 2: Escrever o código da função no `builtins.c`
```c
#include <stdio.h>
#include <unistd.h>
#include "builtins.h" // Incluímos o nosso próprio .h para confirmar que tudo bate certo

void mostrar_ajuda(void) {
    printf("--- MiniShell AHSO ---\n");
    printf("Comandos internos: cd, help, exit\n");
}

int executar_builtin(char **args) {
    // Código dos comandos internos aqui...
    return 0;
}
```

#### Passo 3: Usar a função no `main.c`
Para o `main.c` conseguir chamar `mostrar_ajuda()`, basta incluir o **`builtins.h`** no topo (nunca se faz `#include` de um `.c`!):

```c
#include <stdio.h>
#include "builtins.h" // Usa ASPAS "" em vez de <> para ficheiros do nosso projeto!
#include "parser.h"
#include "executor.h"

int main(void) {
    mostrar_ajuda(); // Funciona! O main conhece a função graças ao builtins.h
    return 0;
}
```

> **⚠️ Regra de Ouro do `#include`:**
> - Bibliotecas do sistema levam `< >`: `#include <stdio.h>`, `#include <unistd.h>`
> - Ficheiros criados por nós levam `" "`: `#include "parser.h"`, `#include "builtins.h"`
> - **NUNCA** faças `#include "builtins.c"`. Faz-se sempre `#include` do **`.h`**!

---

## 3. Como compilar vários ficheiros? (O papel do `Makefile`)

Quando temos 4 ficheiros `.c` (`main.c`, `parser.c`, `executor.c`, `builtins.c`), se compilarmos apenas `gcc main.c -o myshell`, vai dar erro (`undefined reference to...`), porque o `gcc` precisa de juntar todos os ficheiros `.c`.

Sem `Makefile`, teríamos de escrever sempre no terminal:
```bash
gcc -Wall -Wextra -g main.c parser.c executor.c builtins.c -o myshell
```

Com um ficheiro chamado **`Makefile`** (sem extensão!) na pasta do projeto, automatizamos tudo.

### Estrutura do nosso `Makefile`

```makefile
# Compilador e flags de avisos/debug
CC = gcc
CFLAGS = -Wall -Wextra -g

# Nome do executável final
TARGET = myshell

# Lista de ficheiros .c e respetivos ficheiros objeto (.o)
SRCS = main.c parser.c executor.c builtins.c
OBJS = $(SRCS:.c=.o)

# Regra principal: corre quando escrevemos apenas "make"
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compila cada .c individualmente para .o (só recompila o que foi alterado!)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Corre o programa com "make run"
run: $(TARGET)
	./$(TARGET)

# Apaga ficheiros temporários e o executável com "make clean"
clean:
	rm -f $(OBJS) $(TARGET)
```

> **⚠️ Atenção ao editar um `Makefile`:**
> As linhas de comando dentro das regras (como `$(CC)...` e `rm -f...`) têm obrigatoriamente de começar com um **`TAB`** (tecla Tab) e não com espaços normais.

### Comandos do dia a dia no terminal

Com o `Makefile` criado, só precisam de saber 3 comandos no terminal:

1. **`make`** → Compila o projeto (só recompila os ficheiros que tiverem sido modificados) e gera o executável `./myshell`.
2. **`./myshell`** (ou `make run`) → Executa a nossa shell.
3. **`make clean`** → Apaga os ficheiros `.o` e o executável `myshell` para fazer uma compilação limpa do zero.

---

## 4. ⚠️ Nota Muito Importante: Linux / WSL

Este projeto de Sistemas Operativos usa chamadas de sistema POSIX/Linux como:
- `fork()`
- `execvp()` / `execlp()`
- `wait()` / `waitpid()`
- `pipe()` e `dup2()`

Estas funções pertencem à biblioteca `<unistd.h>` e `<sys/wait.h>` do **Linux/Unix** — **não existem nativamente no Windows puro (MinGW)**.

Se estiverem a usar Windows:
- Usem o **WSL (Windows Subsystem for Linux)** — podem abrir a pasta do projeto diretamente no VS Code com a extensão *WSL* ou abrir o terminal Ubuntu/WSL.
- Ou usem uma Máquina Virtual Linux.
- No terminal Linux/WSL, instalem o `gcc` e o `make` (se ainda não tiverem) com:
  ```bash
  sudo apt update && sudo apt install build-essential
  ```
