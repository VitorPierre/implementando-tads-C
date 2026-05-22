#include <stdio.h>
#include <stdlib.h>

//--------------------- TADs -------------------
typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct Fila {
    No* inicio;
    No* fim;
    size_t tamanho;
} Fila;

typedef struct Pilha {
    No* topo;
    size_t tamanho;
} Pilha;
//----------------------------------------------

//--------------- CRIANDO O NÓ -----------------
No* criarNo(int valor) {
    No* no = malloc(sizeof(No));
    if (no == NULL) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    no->valor = valor;
    no->proximo = NULL;
    return no;
}
//----------------------------------------------

//---------------- INICIANDO FILA --------------
Fila* criar_fila(void) {
    Fila* fila = malloc(sizeof(Fila));
    if (fila == NULL) {
        printf("Erro de memoria\n");
        exit(1);
    }

    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
}

int vazia(Fila* fila) {
    return fila->inicio == NULL;
}

int frente(Fila* fila) {
    if (vazia(fila)) {
        printf("Erro: fila vazia\n");
        exit(1);
    }
    return fila->inicio->valor;
}

void destruir_fila(Fila* fila) {
    No* no_atual = fila->inicio;
    while (no_atual != NULL) {
        No* proximo_no = no_atual->proximo;
        free(no_atual);
        no_atual = proximo_no;
    }
    free(fila);
}

void enfileirar(Fila* fila, int valor) {
    No* no = criarNo(valor);

    if (vazia(fila)) {
        fila->inicio = no;
    } else {
        fila->fim->proximo = no;
    }

    fila->fim = no;
    fila->tamanho++;
}

int desenfileirar(Fila* fila) {
    if (vazia(fila)) {
        printf("Erro: fila vazia\n");
        exit(1);
    }

    No* removido = fila->inicio;
    int valor_removido = removido->valor;
    fila->inicio = removido->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(removido);
    fila->tamanho--;
    return valor_removido;
}
//----------------------------------------------

//--------------- INICIANDO PILHA --------------
Pilha* criar_pilha(void) {
    Pilha* pilha = malloc(sizeof(Pilha));
    if (pilha == NULL) {
        printf("Erro: memoria insuficiente\n");
        exit(1);
    }

    pilha->topo = NULL;
    pilha->tamanho = 0;
    return pilha;
}

int pilha_vazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

int pilha_topo(Pilha* pilha) {
    if (pilha_vazia(pilha)) {
        printf("Erro: pilha vazia\n");
        exit(1);
    }

    return pilha->topo->valor;
}

void pilha_destruir(Pilha* pilha) {
    No* no_atual = pilha->topo;
    while (no_atual != NULL) {
        No* proximo = no_atual->proximo;
        free(no_atual);
        no_atual = proximo;
    }
    free(pilha);
}

void empilhar(Pilha* pilha, int valor) {
    No* no = criarNo(valor);
    no->proximo = pilha->topo;
    pilha->topo = no;
    pilha->tamanho++;
}

int desempilhar(Pilha* pilha) {
    if (pilha_vazia(pilha)) {
        printf("Erro: pilha vazia\n");
        exit(1);
    }

    No* removido = pilha->topo;
    int valor = removido->valor;

    pilha->topo = removido->proximo;
    free(removido);
    pilha->tamanho--;

    return valor;
}
//----------------------------------------------

//------------- INVERTENDO A LISTA -------------
No* inverteLista(No* cabeca) {
    No* anterior = NULL;
    No* proximo;

    while (cabeca) {
        proximo = cabeca->proximo;
        cabeca->proximo = anterior;
        anterior = cabeca;
        cabeca = proximo;
    }

    return anterior;
}
//----------------------------------------------

//--------- INVERTENDO PILHA E FILA ------------
void invertePilha(Pilha* pilha) {
    pilha->topo = inverteLista(pilha->topo);
}

void inverteFila(Fila* fila) {
    fila->inicio = inverteLista(fila->inicio);
    fila->fim = fila->inicio;

    while (fila->fim && fila->fim->proximo) {
        fila->fim = fila->fim->proximo;
    }
}
//----------------------------------------------

//------------------ IMPRIMIR ------------------
void imprimir(No* no) {
    while (no) {
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n");
}
//----------------------------------------------

int main() {
    Fila* fila = criar_fila();
    Pilha* pilha = criar_pilha();
	
	int i = 0;
    for (i = 1; i <= 50; i++) {
        empilhar(pilha, i);
        enfileirar(fila, i);
    }

    printf("Fila antes do inverso:\n");
    imprimir(fila->inicio);
    printf("\n");

    inverteFila(fila);
    printf("Fila depois do inverso:\n");
    imprimir(fila->inicio);
    printf("\n");

    printf("Pilha antes do inverso:\n");
    imprimir(pilha->topo);
    printf("\n");

    invertePilha(pilha);
    printf("Pilha depois do inverso:\n");
    imprimir(pilha->topo);

    destruir_fila(fila);
    pilha_destruir(pilha);

    return 0;
}
