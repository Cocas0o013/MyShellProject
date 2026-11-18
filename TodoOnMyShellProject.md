#  TODO List: Trabalho Prático 2 - Shell Interativo (AHSO)

##  Estrutura Base do Projeto
- [x] Criar repositório no GitHub e convidar os colaboradores.
- [ ] Criar ficheiro `Makefile` (recomendado) para compilar o projeto[cite: 1].
- [ ] Criar a estrutura de ficheiros sugerida[cite: 1]:
  - [ ] `main.c`: Loop principal do shell (leitura de comandos e chamadas)[cite: 1].
  - [ ] `parser.c` / `parser.h`: Função `parse_command()` para separar comandos, argumentos e detetar caracteres especiais (`&`, `|`, `>`, `<`)[cite: 1].
  - [ ] `executor.c` / `executor.h`: Funções `execute_command()` (fork+exec) e `execute_builtin()`[cite: 1].
  - [ ] `builtins.c` / `builtins.h`: Implementação dos comandos internos (cd, exit, help)[cite: 1].

##  Parte 1: Funcionalidades Obrigatórias
- [ ] Apresentar uma prompt ao utilizador (ex: `myshell> `)[cite: 1].
- [ ] Ler comandos introduzidos pelo utilizador e fazer o respetivo parse[cite: 1].
- [ ] **Execução de comandos externos do SO:**
  - [ ] Usar `fork()` para criar um processo filho[cite: 1].
  - [ ] Usar família `exec()` (`execlp` ou `execvp`) para executar o comando no processo filho[cite: 1].
  - [ ] Usar `wait()` no processo pai para esperar que o filho termine a execução[cite: 1].
  - [ ] Mostrar mensagem de erro clara se o comando introduzido não existir[cite: 1].
- [ ] **Comandos Internos (Built-ins - execução sem criar novos processos):**
  - [ ] `exit` ou `quit`: Termina o shell[cite: 1].
  - [ ] `cd [directoria]`: Muda de diretoria usando `chdir()` do sistema; se a diretoria for omitida, ir para HOME[cite: 1].
  - [ ] `help`: Mostra a ajuda sobre os comandos disponíveis[cite: 1].
  - [ ] `clear` (opcional): Limpa o ecrã[cite: 1].

##  Parte 2: Funcionalidades Opcionais (Valorização)
- [ ] **Comandos em Background (+2 valores):** Permitir `&` no fim do comando sem que o shell espere pelo fim da execução[cite: 1].
- [ ] **Histórico de Comandos (+1.5 valores):**
  - [ ] Gravar os últimos N comandos executados[cite: 1].
  - [ ] Implementar comando `history` para apresentar a lista[cite: 1].
  - [ ] Implementar comando `!n` para re-executar o comando *n* do histórico[cite: 1].
- [ ] **Redirecionamento de I/O (+2 valores):**
  - [ ] Saída (`>`): Redirecionar output para ficheiro (usar `dup2()` e `open()`)[cite: 1].
  - [ ] Entrada (`<`): Redirecionar input a partir de um ficheiro[cite: 1].
- [ ] **Pipes (+2.5 valores):** Permitir pipes entre comandos, ex: `ls -la | grep txt` (usar `pipe()` e `dup2()`)[cite: 1].
- [ ] **Variáveis de Ambiente (+1 valor):**
  - [ ] Comando `export VAR=valor` para definir nova variável[cite: 1].
  - [ ] Substituir `$VAR` pelo seu valor correspondente nos comandos[cite: 1].
  - [ ] Comando `env` para listar todas as variáveis ativas[cite: 1].

##  Parte 4: Relatório e Entrega
- [ ] **Elaborar Relatório em PDF (máximo 10 páginas):**
  - [ ] 1. Página de capa (nomes e números dos alunos, título do trabalho, data de entrega)[cite: 1].
  - [ ] 2. Introdução (breve descrição do trabalho)[cite: 1].
  - [ ] 3. Arquitetura e Implementação (diagrama da estrutura, explicação das principais funções, decisões de implementação, dificuldades e soluções)[cite: 1].
  - [ ] 4. Funcionalidades Implementadas (lista das obrigatórias e opcionais, screenshots ou exemplos de execução)[cite: 1].
  - [ ] 5. Testes Realizados (casos de teste, comandos testados, situações de erro testadas)[cite: 1].
  - [ ] 6. Conclusão (resumo do trabalho e principais aprendizagens)[cite: 1].
  - [ ] 7. Bibliografia e Referências consultadas[cite: 1].
- [ ] **Preparar Ficheiro ZIP Final (`GrupoX_MiniShell.zip`):**
  - [ ] Ficheiros fonte (`.c` e `.h`)[cite: 1].
  - [ ] Ficheiro `Makefile`[cite: 1].
  - [ ] Relatório em formato PDF[cite: 1].