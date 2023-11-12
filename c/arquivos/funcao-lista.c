#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>

// Estrutura para um nó da lista
struct No {
    int info; // Valor armazenado no nó
    struct No* proximo; // Ponteiro para o próximo nó
    struct No* anterior; // Ponteiro para o nó anterior
};

// Estrutura para a lista
struct Lista {
    struct No* inicio; // Ponteiro para o início da lista
    struct No* fim; // Ponteiro para o final da lista    
    int tamanho; // Tamanho atual da lista
};

// Função para criar uma nova lista
struct Lista* criar() {
    struct Lista* nova_lista = (struct Lista*) malloc(sizeof(struct Lista));
    if (nova_lista != NULL) { // Verifica se a memória foi alocada corretamente
        nova_lista->inicio = NULL;
        nova_lista->fim = NULL;        
        nova_lista->tamanho = 0;
    }
    return nova_lista;
}

// Função para verificar se a lista está vazia
bool vazia(struct Lista* li) {
    assert(li != NULL);     
    if (li->inicio == NULL) { // Verifica se a lista está vazia
        return true;
    } else {
        return false;
    }
}

// Função para inserir um valor em uma posição específica
void inserir (struct Lista* li, int pos, int item) {
    assert(li != NULL);
    assert(pos >= 0 && pos <= li->tamanho);

    struct No* novo_no = (struct No*) malloc(sizeof(struct No));
    if (novo_no == NULL) { // Verifica se a memória foi alocada corretamente
        printf("Falha na alocação de memória. Não foi possível inserir o elemento.\n");
        return;
    }
    novo_no->info = item;
    if (pos == 0) { // Inserção no início da lista
        novo_no->proximo = li->inicio;
        novo_no->anterior = NULL;
        if (li->inicio != NULL) {
            li->inicio->anterior = novo_no;
        }
        li->inicio = novo_no; 
       if (li->tamanho == 0) {
            li->fim = novo_no;
        }
    } else { // Inserção em outra posição da lista
       struct No* aux = li->inicio;
       for(int i = 0; i < pos - 1; i++) { // Loop para encontrar a posição correta
           aux = aux->proximo;
       }
       novo_no->proximo = aux->proximo;
       novo_no->anterior = aux;
       if (aux->proximo != NULL) {
           aux->proximo->anterior = novo_no;
       }
       aux->proximo = novo_no;
    }
    li->tamanho++; 
}

// Função para imprimir a lista
void imprimir(struct Lista* li) {
    assert(li != NULL);
    printf("\nLista: ");
    struct No* aux = li->inicio;
    for(int i = 0; i < li->tamanho; i++) { // Loop para imprimir todos os elementos da lista
        printf("%d ", aux->info);
        aux = aux->proximo;
    }
 }

// Função para obter o valor em uma posição específica
int obterValor(struct Lista* li, int pos) {
    assert(li != NULL);
    assert(pos >= 0 && pos < li->tamanho);

    if (vazia(li)) { // Verifica se a lista está vazia
        printf("A lista está vazia.\n");
        return -1;
    }

    struct No* aux = li->inicio;
    for(int i = 0; i < pos; i++) { // Loop para encontrar o valor na posição especificada
        aux = aux->proximo;
    }
    return aux->info;
}

// Função para remover um valor da lista
void remover(struct Lista* li, int item) {
    assert(li != NULL);

    if (vazia(li)) { // Verifica se a lista está vazia
        printf("A lista está vazia.\n");
        return;
    }

    struct No* aux = li->inicio;

    while (aux != NULL && aux->info != item) { // Loop para encontrar o item a ser removido
        aux = aux->proximo;
    }

    if (aux == NULL) { // Verifica se o item foi encontrado
        printf("O item não foi encontrado na lista.\n");
        return;
    }

    printf("Removendo o item %d da lista.\n", item); // Informa o valor a ser removido

    if (aux->anterior != NULL) { // Remove o nó da lista
        aux->anterior->proximo = aux->proximo;
    } else {
        li->inicio = aux->proximo;
    }

    if (aux->proximo != NULL) {
        aux->proximo->anterior = aux->anterior;
    }

    free(aux);
    li->tamanho--;
}

int main() {
     struct Lista* minha_lista = criar(); 
     inserir(minha_lista, 0, 5);      
     inserir(minha_lista, 0, 3);      
     inserir(minha_lista, 2, 6);         
     inserir(minha_lista, 1, 0);
     inserir(minha_lista, 4, 7);
     inserir(minha_lista, 1, 2);
     inserir(minha_lista, 5, 6);
     inserir(minha_lista, 3, 4);
     imprimir(minha_lista);
     printf("\nValor na posição 2: %d \n", obterValor(minha_lista, 2));
     remover(minha_lista, 10);
     imprimir(minha_lista);
     return 0;
}
