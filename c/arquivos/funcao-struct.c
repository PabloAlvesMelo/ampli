#include <stdio.h>
#include <stdlib.h>

// Definição da struct para representar um nó na lista
struct Node {
    int data;
    struct Node *next;
};

// Função para criar um novo nó com um valor específico
struct Node *criarNovoNo(int valor) {
    struct Node *novoNo = (struct Node *)malloc(sizeof(struct Node));
    if (novoNo == NULL) {
        printf("Erro: Falha na alocação de memória para o novo nó.\n");
        exit(1);
    }
    novoNo->data = valor;
    novoNo->next = NULL;
    return novoNo;
}

// Função para adicionar um nó no início da lista
struct Node *adicionarNoNoInicio(struct Node *head, int valor) {
    struct Node *novoNo = criarNovoNo(valor);
    novoNo->next = head;
    return novoNo;
}

// Função para remover um nó com um valor específico da lista
struct Node *removerNo(struct Node *head, int valor) {
    struct Node *atual = head;
    struct Node *anterior = NULL;

    while (atual != NULL) {
        if (atual->data == valor) {
            if (anterior == NULL) {
                head = atual->next;
            } else {
                anterior->next = atual->next;
            }
            free(atual);
            return head;
        }
        anterior = atual;
        atual = atual->next;
    }

    printf("Valor %d não encontrado na lista.\n", valor);
    return head;
}

// Função para imprimir os elementos da lista
void imprimirLista(struct Node *head) {
    struct Node *atual = head;
    while (atual != NULL) {
        printf("%d -> ", atual->data);
        atual = atual->next;
    }
    printf("NULL\n");
}

int main() {
    // Inicializa a lista vazia
    struct Node *head = NULL;

    int valor;
    char continuar;

    do {
        printf("Digite um valor para inserir na lista: ");
        scanf("%d", &valor);

        head = adicionarNoNoInicio(head, valor);

        printf("Deseja continuar (S/N)? ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');

    printf("Lista atual: ");
    imprimirLista(head);

    printf("Digite um valor para remover da lista: ");
    scanf("%d", &valor);
    head = removerNo(head, valor);

    printf("Lista após a remoção: ");
    imprimirLista(head);

    // Libera a memória alocada para os nós
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
