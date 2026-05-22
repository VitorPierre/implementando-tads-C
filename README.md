# Pilha e Fila em C

Projeto em C que implementa os TADs **Pilha** e **Fila** usando **listas encadeadas dinâmicas**.  
O programa também preenche as estruturas com 50 elementos inteiros e realiza a inversão dos nós.

## Objetivo

- Implementar uma Pilha em C.
- Implementar uma Fila em C.
- Utilizar listas encadeadas dinâmicas.
- Inserir 50 valores inteiros em cada estrutura.
- Inverter a ordem dos elementos da Pilha e da Fila.

## Estruturas utilizadas

O projeto utiliza as seguintes estruturas:

- `No`: representa um nó da lista encadeada.
- `Pilha`: armazena o ponteiro para o topo e o tamanho.
- `Fila`: armazena os ponteiros para o início, fim e tamanho.

## Funcionalidades

- Criar nós dinamicamente com `malloc`.
- Empilhar elementos.
- Desempilhar elementos.
- Enfileirar elementos.
- Desenfileirar elementos.
- Inverter a Pilha.
- Inverter a Fila.
- Imprimir os elementos das estruturas.

## Como compilar

Use o GCC para compilar o arquivo principal:

```bash
gcc main.c -o programa
```

## Como executar

Depois de compilar, execute:

```bash
./programa
```

## Exemplo de uso

O programa:
1. Cria a Pilha e a Fila.
2. Insere 50 números inteiros em cada estrutura.
3. Mostra os dados antes da inversão.
4. Inverte as estruturas.
5. Mostra os dados depois da inversão.

## Observações

- A inversão é feita sobre a lista encadeada.
- A ordem dos elementos muda, mas a quantidade de nós permanece a mesma.
- O projeto foi desenvolvido como अभ्यास de estruturas de dados em C.

## Requisitos

- Compilador C
- GCC ou equivalente

## Autor

Desenvolvido para estudo de TADs, listas encadeadas, pilha e fila em C.
