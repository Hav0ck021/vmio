# vmio – virtual machine with input/output
vmio é uma implementação didática de uma pequena máquina virtual escrita em C.
O projeto demonstra conceitos fundamentais de pilha, registradores e execução de instruções.

## 📁 Estrutura do Projeto

```bash
├── include             # Declaração
│   ├── core.h          # Fluxo central da máquina virtual
│   ├── registers.h     # Registradores, ponteiros básicos e seus índices
│   └── stack.h         # Implementação da pilha de controle (stack)
├── main.c
├── Makefile
├── README.md
└── src                 # Definição
│   ├── core.c          # Implementação de cada instrução existente na VM
│   ├── registers.c     
│   └── stack.c         # Funções de push e pop para a pilha (stack) estática
```

## 🎯 Objetivo

O objetivo da vmio é demonstrar de forma simples como funciona uma máquina virtual baseada em:
- stack (pilha),
- registradores,
- ciclo de execução (fetch → decode → execute),
- interpretação de instruções.

A VM é intencionalmente simples, ideal para estudo ou experimentação.

## ⚙️ Funcionamento Geral

A execução segue um loop:
1. A VM busca a instrução atual através do registrador ip (instruction pointer).
2. Decodifica e executa a instrução.
3. Incrementa ip e continua até encontrar a instrução EXT.

Registradores importantes:
- ip — aponta sempre para a próxima instrução no programa.
- sp — aponta para o topo da pilha.
A pilha é utilizada para operações aritméticas e armazenamento temporário.

## 📚 Implementação da Stack

A stack suporta:

| Função	| Descrição |
|-----------|-----------|
| stack_init | Inicializa a pilha e ajusta sp = -1. |
| stack_push | Insere um valor no topo. |
| stack_pop	| Remove e retorna o valor do topo. |

Ela armazena inteiros e protege contra underflow e overflow.

## 🧠 Núcleo da VM

As instruções são interpretadas pela função eval().
O loop principal está em run_vm():

```c
while (running) {
    eval(fetch(reg[ip]), &stack);
    reg[ip]++;
}
```

## 📌 Conjunto de Instruções
| Instrução |	Ação |
|-----------|-----------|
| PSH	| empilha um valor imediato	|
| POP	| desempilha o topo	|
| ADD	| soma os dois valores do topo	|
| EXT	| encerra a execução |

### 📝 Exemplo: Programa Interno da VM

A VM contém um pequeno programa embutido:

```c
const int program[] = {
    PSH, 5,
    PSH, 6,
    ADD,
    EXT
};
```

Etapas da execução:

1. PSH 5
   1. IP aponta para PSH
   2. VM lê PSH
   3. Incrementa ip e lê o próximo valor: 5
   4. Executa stack_push(5)
   5. Pilha: [5]

```bash
data pushed: 5
```
2. PSH 6
   1. IP aponta para PSH
   2. VM empilha 6
   3. Pilha: [5, 6]

```bash
data pushed: 6
```

3. ADD
   1. VM executa stack_pop → obtém 6
   2. VM executa novamente → obtém 5
   3. Calcula 5 + 6 = 11
   4. Empilha o resultado
   5. Pilha: [11] 

```bash
add: 11
```

4. EXT
   1. Instrui a VM a parar a execução
   2. Loop principal encerra

## 🛠️ Compilação

Compile o projeto:

```bash
make debug
```

Limpe arquivos gerados:
```bash
make clean
```

## ▶️ Execução

Após compilar:

```bash
./debug
```
Saída prevista:

```bash
data pushed: 5
data pushed: 6
add: 11
```

## ✅ To‑Do (branch develop)

- [ ] Adicionar suporte a novas instruções — definir e implementar opcodes além de PSH, POP, ADD, EXT. Exemplo: subtração, multiplicação, divisão, operações lógicas, comparação, saltos condicionais, etc.
- [ ] Implementar suporte a memória “externa” (heap / memória RAM emulado) — permitir que a VM leia e escreva dados em uma região de memória além da pilha (para simular memória de dados, variáveis, heap, etc.).
- [ ] Criar funcionalidade de carregamento de bytecode externo — permitir que o programa da VM seja carregado a partir de um arquivo (em vez de estar embutido como array program[]), facilitando testes e flexibilidade.
- [ ] Desenvolver um sistema de debug / trace — registrar (ou imprimir) passo a passo da execução da VM (instrução atual, conteúdo da pilha, registradores, etc.), para facilitar depuração e compreensão do comportamento.
