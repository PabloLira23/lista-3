#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAMANHO 100

typedef struct {
    int dados[TAMANHO];
    int topo;
} Pilha;

typedef struct {
    char dados[TAMANHO];
    int topo;
} PilhaChar;

bool isEmpty(Pilha *p){
    return p->topo == -1;
}

void inicializar(Pilha *p){
    p->topo = -1;
}

void push(Pilha *p, int dado){
    if(p->topo == TAMANHO - 1){
        printf("Pilha Cheia!\n");
        return;
    }
    p->topo++;
    p->dados[p->topo] = dado;
}

int pop(Pilha *p){
    if(isEmpty(p)){
        printf("Pilha Vazia!\n");
        return -1;
    }
    int temp = p->dados[p->topo];
    p->topo--;
    return temp;
}

void imprime_pilha(Pilha *p){
    if(isEmpty(p)){
        printf("Pilha Vazia\n");
        return;
    }
    printf("Pilha: ");
    for(int i = 0; i <= p->topo; i++){
        printf("%d ", p->dados[i]);
    }
    printf("(topo: %d)\n", p->dados[p->topo]);
}

bool isEmptyChar(PilhaChar *p){
    return p->topo == -1;
}

void inicializarChar(PilhaChar *p){
    p->topo = -1;
}

void pushChar(PilhaChar *p, char dado){
    if(p->topo == TAMANHO - 1){
        printf("Pilha Cheia!\n");
        return;
    }
    p->topo++;
    p->dados[p->topo] = dado;
}

char popChar(PilhaChar *p){
    if(isEmptyChar(p)){
        printf("Pilha Vazia!\n");
        return '\0';
    }
    char temp = p->dados[p->topo];
    p->topo--;
    return temp;
}

void exercicio1(){
    printf("=== EXERCICIO 1: Inverter elementos de um vetor ===\n");
    int vetor[] = {1, 2, 3, 4, 5};
    int tamanho = 5;
    Pilha p;
    inicializar(&p);
    
    printf("Vetor original: ");
    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
        push(&p, vetor[i]);
    }
    printf("\n");
    
    printf("Vetor invertido: ");
    for(int i = 0; i < tamanho; i++){
        vetor[i] = pop(&p);
        printf("%d ", vetor[i]);
    }
    printf("\n\n");
}

void exercicio2(){
    printf("=== EXERCICIO 2: Verificar se uma palavra e palindromo ===\n");
    char palavra[100];
    printf("Digite uma palavra: ");
    scanf("%s", palavra);
    
    PilhaChar p;
    inicializarChar(&p);
    
    int tamanho = strlen(palavra);
    for(int i = 0; i < tamanho; i++){
        pushChar(&p, palavra[i]);
    }
    
    bool eh_palindromo = true;
    for(int i = 0; i < tamanho; i++){
        if(palavra[i] != popChar(&p)){
            eh_palindromo = false;
            break;
        }
    }
    
    if(eh_palindromo){
        printf("A palavra '%s' eh um palindromo!\n\n", palavra);
    } else {
        printf("A palavra '%s' NAO eh um palindromo!\n\n", palavra);
    }
}

void exercicio3(){
    printf("=== EXERCICIO 3: Simular desfazer/refazer ===\n");
    Pilha desfazer, refazer;
    inicializar(&desfazer);
    inicializar(&refazer);
    
    int operacao, valor;
    
    printf("Sistema de Undo/Redo\n");
    printf("1 - Adicionar operacao\n");
    printf("2 - Desfazer\n");
    printf("3 - Refazer\n");
    printf("0 - Sair\n");
    
    while(1){
        printf("\nEscolha uma opcao: ");
        scanf("%d", &operacao);
        
        switch(operacao){
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                push(&desfazer, valor);
                inicializar(&refazer);
                printf("Operacao %d adicionada\n", valor);
                break;
            case 2:
                if(!isEmpty(&desfazer)){
                    valor = pop(&desfazer);
                    push(&refazer, valor);
                    printf("Operacao %d desfeita\n", valor);
                } else {
                    printf("Nada para desfazer\n");
                }
                break;
            case 3:
                if(!isEmpty(&refazer)){
                    valor = pop(&refazer);
                    push(&desfazer, valor);
                    printf("Operacao %d refeita\n", valor);
                } else {
                    printf("Nada para refazer\n");
                }
                break;
            case 0:
                printf("Saindo...\n\n");
                return;
            default:
                printf("Opcao invalida\n");
        }
    }
}

void exercicio4(){
    printf("=== EXERCICIO 4: Remover elementos pares da pilha ===\n");
    Pilha original, auxiliar;
    inicializar(&original);
    inicializar(&auxiliar);
    
    push(&original, 1);
    push(&original, 2);
    push(&original, 3);
    push(&original, 4);
    push(&original, 5);
    push(&original, 6);
    
    printf("Pilha original: ");
    imprime_pilha(&original);
    
    while(!isEmpty(&original)){
        int valor = pop(&original);
        if(valor % 2 != 0){
            push(&auxiliar, valor);
        }
    }
    
    while(!isEmpty(&auxiliar)){
        push(&original, pop(&auxiliar));
    }
    
    printf("Pilha sem pares: ");
    imprime_pilha(&original);
    printf("\n");
}

void exercicio5(){
    printf("=== EXERCICIO 5: Ordenar uma pilha ===\n");
    Pilha original, auxiliar;
    inicializar(&original);
    inicializar(&auxiliar);
    
    push(&original, 5);
    push(&original, 1);
    push(&original, 4);
    push(&original, 2);
    push(&original, 3);
    
    printf("Pilha original: ");
    imprime_pilha(&original);
    
    while(!isEmpty(&original)){
        int temp = pop(&original);
        
        while(!isEmpty(&auxiliar) && auxiliar.dados[auxiliar.topo] > temp){
            push(&original, pop(&auxiliar));
        }
        
        push(&auxiliar, temp);
    }
    
    while(!isEmpty(&auxiliar)){
        push(&original, pop(&auxiliar));
    }
    
    printf("Pilha ordenada: ");
    imprime_pilha(&original);
    printf("\n");
}

int main(){
    int escolha;
    
    printf("LISTA DE EXERCICIOS - PILHAS\n");
    printf("1 - Inverter elementos de um vetor\n");
    printf("2 - Verificar se uma palavra eh palindromo\n");
    printf("3 - Simular desfazer/refazer\n");
    printf("4 - Remover elementos pares da pilha\n");
    printf("5 - Ordenar uma pilha\n");
    printf("0 - Sair\n");
    
    while(1){
        printf("\nEscolha um exercicio (0 para sair): ");
        scanf("%d", &escolha);
        
        switch(escolha){
            case 1:
                exercicio1();
                break;
            case 2:
                exercicio2();
                break;
            case 3:
                exercicio3();
                break;
            case 4:
                exercicio4();
                break;
            case 5:
                exercicio5();
                break;
            case 0:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opcao invalida!\n");
        }
    }
    
    return 0;
}
